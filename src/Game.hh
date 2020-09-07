#ifndef SNAKE_SFML_GAME_HH
#define SNAKE_SFML_GAME_HH

#include "Food.hh"
#include "Snake.hh"
#include <SFML/Graphics/RenderWindow.hpp>

class Game {
public:
  explicit Game(sf::RenderWindow& window);
  void run();

private:
  sf::RenderWindow& window;
  sf::Clock clock {};
  unsigned int score {};
  Food food {};
  Snake snake {};
  auto handleEvents() const -> bool;
  void handleKeys();
  void draw() const;
  void show_score() const;
};

#endif // SNAKE_SFML_GAME_HH
