#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "config.h"
#include "game.h"
#include "textures.h"

using namespace std;

int main() {
  srand(time(NULL));
  // Создание главного окна
  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                          WINDOW_TITLE);
  window.setFramerateLimit(WINDOW_FPS);

  // Загрузка текстур
  Textures textures;
  textures.setTextures();

  // загрузка шрифта
  sf::Font font;
  if (!font.loadFromFile(FONT_FILE)) {
    return EXIT_FAILURE;
  }

  sf::Clock clock;

  // Создание игры
  Game game(font, textures);

  while (window.isOpen()) {
    float dt = clock.getElapsedTime().asSeconds();
    clock.restart();

    game.handleInput(window);

    game.draw(window);
    game.update(dt);
  }

  return EXIT_SUCCESS;
}