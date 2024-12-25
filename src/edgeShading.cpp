#include "edgeShading.h"

EdgeShading::EdgeShading(sf::Vector2f position)
    : shape_(sf::RectangleShape(sf::Vector2f(SHADOW_WIDTH, SHADOW_HEIGHT))) {
  shape_.setFillColor(sf::Color::Black);
  shape_.setPosition(position);
}

void EdgeShading::draw(sf::RenderWindow &window) { window.draw(this->shape_); }
