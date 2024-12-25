#ifndef _SLOT_MACHINE_H_
#define _SLOT_MACHINE_H_

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

#include "config.h"
#include "edgeShading.h"
#include "input.h"
#include "resultDisplay.h"
#include "roll.h"
#include "textures.h"

class SlotMachine {
 public:
  SlotMachine(const sf::Vector2f& position, const sf::Vector2f& size,
              Textures& texture);

  void start();
  void stop();

  void draw(sf::RenderWindow& window);
  void update(float dt);

  bool isStopped() const;
  RollValue isRollSegmentValueInResultDisplay(int rollIndex);

  int getScore();

 private:
  sf::RectangleShape shape_;
  std::vector<Roll> rolls_;
  ResultDisplay resultDisplay_;
  int score_;
  EdgeShading topShadow_;
  EdgeShading bottomShadow_;
};

#endif  // _SLOT_MACHINE_H_