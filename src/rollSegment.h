#ifndef _ROLLSEGMENT_H_
#define _ROLLSEGMENT_H_

#include <SFML/Graphics.hpp>

#include "config.h"

enum class RollValue { CIRCLE, SQUARE, TRIANGLE, UMBRELLA, COUNT };

class RollSegment {
 public:
  RollSegment(RollValue value, sf::Texture& texture);

  sf::IntRect getFigureRectInSprite(RollValue value, sf::Texture& texture);

  RollValue getValue() const;
  void setPosition(const sf::Vector2f& position);
  sf::Vector2f getPosition();
  void draw(sf::RenderWindow& window) const;
  void update(float dt);
  sf::FloatRect getBounds() const;

 private:
  RollValue value_;
  const sf::Texture& texture_;
  sf::Sprite sprite_;
};

#endif  // _ROLLSEGMENT_H_