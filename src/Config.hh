#ifndef SNAKE_SFML_CONFIG_HH
#define SNAKE_SFML_CONFIG_HH

#include <SFML/Graphics/Color.hpp>
#include <array>

// TODO
namespace config {
  constexpr unsigned int windowSize {1200};
  constexpr unsigned int nBlocks {13};
  constexpr float blockSize {windowSize / static_cast<float>(nBlocks)};
  constexpr float foodRadius {blockSize / 3};

  constexpr auto fontSize {static_cast<unsigned int>(windowSize / 5)};

  namespace color {
    // FIXME
    const auto snake {sf::Color::Green};
    // FIXME
    const std::array<sf::Color, 4> food {
        sf::Color::Red,
        sf::Color::Cyan,
        sf::Color::Yellow,
        sf::Color::Magenta,
    };
  }
}

#endif // SNAKE_SFML_CONFIG_HH
