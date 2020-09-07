#include "Snake.hh"
#include <algorithm>

using namespace config;

Snake::Snake() {
  head.setFillColor(color::snake);

  if (nBlocks % 2 != 0) {
    head.setPosition(windowSize / 2.F - blockSize / 2.F,
                     windowSize / 2.F - blockSize / 2.F);
  }
}

void Snake::turn(const Direction& dire) {
  if (oppositeDirection(dire) == direction) {
    return;
  }

  direction = dire;
}

void Snake::move() {
  if (!body.empty()) {
    body.insert(body.begin(), head);
    body.pop_back();
  }

  switch (direction) {
    case Direction::Up: head.move(0, -blockSize); break;
    case Direction::Right: head.move(blockSize, 0); break;
    case Direction::Down: head.move(0, blockSize); break;
    case Direction::Left: head.move(-blockSize, 0); break;
    case Direction::None: break;
  }
}

auto Snake::isPositionValid() const -> bool {
  auto position {head.getPosition()};

  return (position.x >= -1 && position.x < windowSize) &&
         (position.y >= -1 && position.y < windowSize) &&
         std::all_of(body.begin(), body.end(), [&](auto e) {
           return e.getPosition() != head.getPosition();
         });
}

auto Snake::getHeadGlobalBounds() const -> sf::FloatRect {
  return head.getGlobalBounds();
}

void Snake::grow() { body.push_back(head); }

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(head, states);

  for (const auto& i : body) {
    target.draw(i, states);
  }
}
