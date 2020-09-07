#ifndef SNAKE_SFML_SNAKE_HH
#define SNAKE_SFML_SNAKE_HH

#include "Config.hh"
#include "Direction.hh"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Snake : public sf::Drawable {
public:
  Snake();
  void turn(const Direction& dire);
  void move();
  [[nodiscard]] auto isPositionValid() const -> bool;
  [[nodiscard]] auto getHeadGlobalBounds() const -> sf::FloatRect;
  void grow();

private:
  sf::RectangleShape head {sf::Vector2f {config::blockSize, config::blockSize}};
  std::vector<sf::RectangleShape> body {};
  Direction direction {Direction::None};
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // SNAKE_SFML_SNAKE_HH
