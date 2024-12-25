#include "rollSegment.h"

RollSegment::RollSegment(RollValue value, sf::Texture &texture)
    : value_(value), texture_(texture) {
  sprite_.setTexture(texture);
  sf::IntRect figureRect = getFigureRectInSprite(value, texture);
  sprite_.setTextureRect(figureRect);

  float scale = ROLL_SEGMENT_SIZE / (texture.getSize().x / 2.0);
  sprite_.setScale(scale, scale);
}

sf::IntRect RollSegment::getFigureRectInSprite(RollValue value,
                                               sf::Texture &texture) {
  // Текстура разделена на четыре части
  // по горизонтали и по вертикали
  int textureWidth = texture.getSize().x;
  int textureHeight = texture.getSize().y;

  int halfWidth = textureWidth / 2;
  int halfHeight = textureHeight / 2;

  switch (value) {
    case RollValue::CIRCLE:
      return sf::IntRect(0, 0, halfWidth, halfHeight);
    case RollValue::SQUARE:
      return sf::IntRect(0, halfHeight, halfWidth, textureHeight);
    case RollValue::TRIANGLE:
      return sf::IntRect(halfWidth, 0, textureWidth, halfHeight);
    case RollValue::UMBRELLA:
      return sf::IntRect(halfWidth, halfHeight, textureWidth, textureHeight);
      break;
    default:
      throw std::invalid_argument("Unknown value");
  }
}

RollValue RollSegment::getValue() const { return this->value_; }

void RollSegment::setPosition(const sf::Vector2f &position) {
  this->sprite_.setPosition(position);
}

sf::Vector2f RollSegment::getPosition() { return this->sprite_.getPosition(); }

void RollSegment::draw(sf::RenderWindow &window) const {
  window.draw(this->sprite_);
}

void RollSegment::update(float dt) {
  sf::Vector2f newPosition = getPosition();
  newPosition.y += dt;

  sprite_.setPosition(newPosition);
}

sf::FloatRect RollSegment::getBounds() const {
  return sprite_.getGlobalBounds();
}
