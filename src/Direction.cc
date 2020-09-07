#include "Direction.hh"

auto oppositeDirection(const Direction& direction) -> Direction {
  switch (direction) {
    case Direction::None: return Direction::None;
    case Direction::Up: return Direction::Down;
    case Direction::Right: return Direction::Left;
    case Direction::Down: return Direction::Up;
    case Direction::Left: return Direction::Right;
  }
}
