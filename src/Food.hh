#ifndef SNAKE_SFML_FOOD_HH
#define SNAKE_SFML_FOOD_HH

#include "Config.hh"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Food : public sf::Drawable {
public:
  Food();
  [[nodiscard]] auto getGlobalBounds() const -> sf::FloatRect;

private:
  sf::CircleShape shape {config::foodRadius};
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // SNAKE_SFML_FOOD_HH
