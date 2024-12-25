#include "roll.h"

Roll::Roll(sf::Vector2f pos, Textures& texture)
    : position_(pos),
      speed_(0),
      stopped_(true),
      shape_(sf::RectangleShape(sf::Vector2f(ROLL_WIDTH, ROLL_HEIGHT))) {
  shape_.setPosition(position_);
  shape_.setFillColor(sf::Color::Red);

  segments_.reserve(ROLL_SEGMENT_COUNT);
  for (int i = 0; i < ROLL_SEGMENT_COUNT; i++) {
    segments_.push_back(this->createRandomRollSegment(texture, i));
  }
}

RollSegment Roll::createRandomRollSegment(Textures& texture, int index) {
  int randomSegmentValue = rand() % (int)RollValue::COUNT;
  RollSegment segment(static_cast<RollValue>(randomSegmentValue),
                      texture.figuresTexture);
  sf::Vector2f segmentPos =
      sf::Vector2f(position_.x + (ROLL_WIDTH / 2 - ROLL_SEGMENT_SIZE / 2),
                   position_.y + index * ROLL_SEGMENT_SIZE);
  segment.setPosition(segmentPos);

  return segment;
}

void Roll::start() {
  if (speed_ == 0) {
    stopped_ = false;
    speed_ = ROLL_SPEED;
  }
}

void Roll::stop() {
  if (speed_ > ROLL_SPEED_MIN) {
    speed_ *= ROLL_SPEED_DECAY;
  } else {
    int segmentIndex = getSegmentIndexInPosition(position_);
    if (std::abs(segments_[segmentIndex].getPosition().y -
                 (position_.y + ROLL_SEGMENT_SIZE)) < offset_) {
      stopped_ = true;
      speed_ = 0;
    }
  }
}

void Roll::rotate(float dt) {
  if (speed_ > 0) {
    offset_ = dt * speed_;

    for (long unsigned i = 0; i < segments_.size(); ++i) {
      segments_[i].update(offset_);
      wrapSegmentIfOutOfBounds(i);
    }
  }
}

void Roll::wrapSegmentIfOutOfBounds(unsigned long index) {
  if (segments_[index].getPosition().y > position_.y + ROLL_HEIGHT) {
    sf::Vector2f newPosition = position_;
    index == segments_.size() - 1
        ?  // если индекс сегмента последний в коллекции
        newPosition.y = segments_[0].getPosition().y - ROLL_SEGMENT_SIZE
        : newPosition.y =
              segments_[index + 1].getPosition().y - ROLL_SEGMENT_SIZE;
    segments_[index].setPosition(newPosition);
  }
}

void Roll::draw(sf::RenderWindow& window) {
  window.draw(shape_);

  for (auto& segment : segments_) {
    if (isSegmentInView(segment)) {
      segment.draw(window);
    }
  }
}

bool Roll::isSegmentInView(RollSegment& segment) {
  sf::FloatRect segmentBounds = segment.getBounds();

  return (segmentBounds.top + segmentBounds.height >= position_.y &&
          segmentBounds.top < position_.y + ROLL_HEIGHT);
}

bool Roll::isStopped() { return stopped_; }

int Roll::getSegmentIndexInPosition(sf::Vector2f position) {
  for (long unsigned i = 0; i < segments_.size(); ++i) {
    if (std::abs(segments_[i].getPosition().y -
                 (position.y + ROLL_SEGMENT_SIZE)) < (ROLL_SEGMENT_SIZE)) {
      return i;
    }
  }
  return -1;
}

RollValue Roll::getRollValue() {
  return segments_[getSegmentIndexInPosition(position_)].getValue();
}
