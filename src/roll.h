#ifndef _ROLL_H_
#define _ROLL_H_

#include <SFML/Graphics.hpp>
#include <random>

#include "config.h"
#include "rollSegment.h"
#include "textures.h"

class Roll {
 public:
  Roll(sf::Vector2f position, Textures& texture);

  RollSegment createRandomRollSegment(Textures& texture, int index);

  void start();
  void stop();

  void rotate(float dt);
  void wrapSegmentIfOutOfBounds(unsigned long i);
  void draw(sf::RenderWindow& window);

  bool isSegmentInView(RollSegment& segment);

  bool isStopped();
  int getSegmentIndexInPosition(sf::Vector2f position);
  RollValue getRollValue();

 private:
  sf::Vector2f position_;
  std::vector<RollSegment> segments_;
  float speed_;
  bool stopped_;
  float offset_ = 0.0f;
  sf::RectangleShape shape_;
};

#endif  // _ROLL_H_