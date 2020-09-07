#include "Config.hh"
#include "Game.hh"
#include <SFML/Graphics/RenderWindow.hpp>

using namespace config;

auto main() -> int {
  sf::RenderWindow window {sf::VideoMode {windowSize, windowSize}, "Snake",
                           sf::Style::Close};

  window.setMouseCursorVisible(false);
  window.setVerticalSyncEnabled(true);

  while (window.isOpen()) {
    Game {window}.run();
  }
}
