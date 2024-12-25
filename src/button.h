#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <SFML/Graphics.hpp>

class Button {
 public:
  Button(sf::Font& font, const std::string& text, const sf::Vector2f& position,
         const sf::Vector2f& size);

  void draw(sf::RenderWindow& window);
  bool isClicked(sf::Vector2i mousePos);

  void setPosition(const sf::Vector2f& position);

 private:
  sf::RectangleShape shape_;
  sf::Text text_;

  void centeringText();
};  // class Button

#endif  //_BUTTON_H_