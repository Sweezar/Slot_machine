#include "game.h"

Game::Game(sf::Font &font, Textures &texture)
    : slotMachine_(sf::Vector2f(SLOT_MACHINE_X, SLOT_MACHINE_Y),
                   sf::Vector2f(SLOT_MACHINE_WIDTH, SLOT_MACHINE_HEIGHT),
                   texture),
      startButton_(font, "Start", sf::Vector2f(START_BUTTON_X, START_BUTTON_Y),
                   sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT)),
      stopButton_(font, "Stop", sf::Vector2f(STOP_BUTTON_X, STOP_BUTTON_Y),
                  sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT)) {
  score_.setPosition(sf::Vector2f(SCORE_X, SCORE_Y));
  score_.setFont(font);
}

void Game::update(float dt) {
  fsm_.handleInput(slotMachine_, Input::NO_INPUT, dt);
  checkTimerExpire(dt);
  if (slotMachine_.isStopped()) {
    setScore(slotMachine_.getScore());
  }
}

void Game::checkTimerExpire(float dt) {
  timer_ += dt;
  if (timer_ > GAME_MAX_TIME) {
    fsm_.handleInput(slotMachine_, Input::STOP_INPUT, dt);
    timer_ = 0;
  }
}

void Game::draw(sf::RenderWindow &window) {
  window.clear();

  slotMachine_.draw(window);
  startButton_.draw(window);
  stopButton_.draw(window);

  window.draw(score_);

  window.display();
}

void Game::handleInput(sf::RenderWindow &window) {
  sf::Event event;
  while (window.pollEvent(event)) {
    handleWindowEvent(event, window);
    handleMouseEvent(event, window);
  }
}

void Game::handleMouseEvent(sf::Event &event, sf::RenderWindow &window) {
  if (event.type == sf::Event::MouseButtonPressed) {
    if (event.mouseButton.button == sf::Mouse::Left) {
      sf::Vector2i mousePos = sf::Mouse::getPosition(window);

      if (startButton_.isClicked(mousePos)) {
        timer_ = 0;
        stateUpdate(Input::START_INPUT);
      } else if (stopButton_.isClicked(mousePos)) {
        stateUpdate(Input::STOP_INPUT);
      }
    }
  }
}

void Game::handleWindowEvent(sf::Event &event, sf::RenderWindow &window) {
  if (event.type == sf::Event::Closed) {
    window.close();
  }
  if (event.type == sf::Event::KeyPressed) {
    if (event.key.code == sf::Keyboard::Escape) {
      window.close();
    }
  }
}

void Game::stateUpdate(Input input) {
  fsm_.handleInput(slotMachine_, input, 0);
}

void Game::setScore(int score) {
  this->score_.setString(std::to_string(score));
}
