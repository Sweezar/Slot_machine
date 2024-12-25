#ifndef _RESULT_DISPLAY_H_
#define _RESULT_DISPLAY_H_

#include <SFML/Graphics.hpp>

class ResultDisplay {
 public:
  ResultDisplay(const sf::Vector2f& position, const sf::Vector2f& size);

  sf::Vector2f getPosition();
  void draw(sf::RenderWindow& window);

 private:
  sf::Vector2f position_;
  sf::RectangleShape shape_;
};  // class ResultDisplay

#endif  //_RESULT_DISPLAY_H_