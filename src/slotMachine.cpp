#include "slotMachine.h"

SlotMachine::SlotMachine(const sf::Vector2f &position, const sf::Vector2f &size,
                         Textures &texture)
    : shape_(sf::RectangleShape(size)),
      resultDisplay_(sf::Vector2f(position.x, position.y + ROLL_SEGMENT_SIZE),
                     sf::Vector2f(size.x, ROLL_SEGMENT_SIZE)),
      topShadow_(sf::Vector2f(SHADOW_TOP_X, SHADOW_TOP_Y)),
      bottomShadow_(sf::Vector2f(SHADOW_BOTTOM_X, SHADOW_BOTTOM_Y)) {
  shape_.setPosition(position);
  shape_.setFillColor(sf::Color::White);

  rolls_.reserve(ROLLS_COUNT);
  for (int i = 0; i < ROLLS_COUNT; ++i) {
    rolls_.push_back(Roll(
        sf::Vector2f(position.x + i * (ROLL_WIDTH + ROLL_GAP) + ROLL_PADDING,
                     position.y),
        texture));
  }
}

void SlotMachine::start() {
  for (auto &roll : rolls_) {
    roll.start();
  }
}

void SlotMachine::stop() {
  for (auto &roll : rolls_) {
    roll.stop();
  }
}

void SlotMachine::draw(sf::RenderWindow &window) {
  window.draw(shape_);
  for (auto roll : rolls_) {
    roll.draw(window);
  }
  resultDisplay_.draw(window);

  // Затенение краев слот машины
  topShadow_.draw(window);
  bottomShadow_.draw(window);
}

void SlotMachine::update(float dt) {
  for (auto &roll : rolls_) {
    roll.rotate(dt);
    dt += ROLL_SPEED_STEP;
  }
}

bool SlotMachine::isStopped() const {
  for (auto roll : rolls_) {
    if (!roll.isStopped()) {
      return false;
    }
  }
  return true;
}

RollValue SlotMachine::isRollSegmentValueInResultDisplay(int rollIndex) {
  Roll &roll = rolls_[rollIndex];
  return roll.getRollValue();
}

int SlotMachine::getScore() {
  std::unordered_map<RollValue, int> rollValues;

  for (long unsigned int i = 0; i < rolls_.size(); ++i) {
    rollValues[isRollSegmentValueInResultDisplay(i)]++;
  }

  int score = 0;

  for (auto it = rollValues.begin(); it != rollValues.end(); ++it) {
    if (it->second == 2) {
      score += 100;
    }
    if (it->second == 3) {
      score += 300;
    }
    if (it->second == 4) {
      score += 1000;
    }
    if (it->second == 5) {
      score += 5000;
    }
  }

  return score;
}
