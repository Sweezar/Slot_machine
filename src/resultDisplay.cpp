#include "resultDisplay.h"

ResultDisplay::ResultDisplay(const sf::Vector2f& position,
                             const sf::Vector2f& size)
    : shape_(sf::RectangleShape(size)) {
  shape_.setPosition(position);
  shape_.setOutlineThickness(5);
  shape_.setOutlineColor(sf::Color::Yellow);
  shape_.setFillColor(sf::Color::Transparent);
}

sf::Vector2f ResultDisplay::getPosition() { return position_; }

void ResultDisplay::draw(sf::RenderWindow& window) { window.draw(shape_); }
