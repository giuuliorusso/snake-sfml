#include "Food.hh"
#include <random>

using namespace config;

Food::Food() {
  // TODO
  std::random_device rd;
  std::mt19937 mt {rd()};
  std::uniform_int_distribution<> dis {0, nBlocks - 1};

  // FIXME
  float x {dis(mt) * blockSize + foodRadius / 2};
  float y {dis(mt) * blockSize + foodRadius / 2};

  shape.setPosition(x, y);
  shape.setFillColor(color::food.at(dis(mt) % color::food.size()));
}

auto Food::getGlobalBounds() const -> sf::FloatRect {
  return shape.getGlobalBounds();
}

void Food::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(shape, states);
}
