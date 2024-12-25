#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>
#include <vector>

#include "button.h"
#include "config.h"
#include "fsm/fsm.h"
#include "roll.h"
#include "slotMachine.h"
#include "textures.h"

class Game {
 public:
  Game(sf::Font &font, Textures &texture);

  void update(float dt);
  void checkTimerExpire(float dt);
  void draw(sf::RenderWindow &window);
  void handleInput(sf::RenderWindow &window);
  void handleMouseEvent(sf::Event &event, sf::RenderWindow &window);
  void handleWindowEvent(sf::Event &event, sf::RenderWindow &window);
  void stateUpdate(Input input);
  void setScore(int score);

 private:
  float timer_;
  sf::Text score_;
  SlotMachine slotMachine_;

  Button startButton_;
  Button stopButton_;

  FSM fsm_;
};

#endif  // _GAME_H_