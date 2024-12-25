#include "button.h"

Button::Button(sf::Font &font, const std::string &text,
               const sf::Vector2f &position, const sf::Vector2f &size)
    : shape_(sf::RectangleShape(size)) {
  shape_.setPosition(position);
  shape_.setFillColor(sf::Color::White);

  this->text_.setString(text);
  this->text_.setFont(font);
  this->text_.setFillColor(sf::Color::Green);
  this->text_.setCharacterSize(30);

  centeringText();
}

void Button::centeringText() {
  sf::FloatRect textBounds = this->text_.getLocalBounds();
  this->text_.setOrigin(textBounds.left + textBounds.width / 2.0f,
                        textBounds.top + textBounds.height / 2.0f);
  this->text_.setPosition(shape_.getPosition().x + shape_.getSize().x / 2.0f,
                          shape_.getPosition().y + shape_.getSize().y / 2.0f);
}

void Button::draw(sf::RenderWindow &window) {
  window.draw(shape_);
  window.draw(text_);
}

bool Button::isClicked(sf::Vector2i mousePos) {
  return shape_.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

void Button::setPosition(const sf::Vector2f &position) {
  shape_.setPosition(position);
  centeringText();
}
