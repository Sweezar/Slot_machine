#ifndef _EDGESHADING_H_
#define _EDGESHADING_H_

#include <SFML/Graphics.hpp>

#include "config.h"

class EdgeShading {
 public:
  EdgeShading(sf::Vector2f position);

  void draw(sf::RenderWindow& window);

 private:
  sf::RectangleShape shape_;
};

#endif  // _EDGESHADING_H_