#ifndef _TEXTURES_H_
#define _TEXTURES_H_

#include <SFML/Graphics.hpp>

#define FIGURE_TEXTURE_PATH "assets/figure_asset.png"

class Textures {
 public:
  Textures() { setTextures(); }
  ~Textures() {}

  sf::Texture figuresTexture;

  void setFiguresTexture() { figuresTexture.loadFromFile(FIGURE_TEXTURE_PATH); }

  void setTextures() { setFiguresTexture(); }
};  // class Textures

#endif /* _TEXTURES_H_ */