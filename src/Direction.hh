#ifndef SNAKE_SFML_DIRECTION_HH
#define SNAKE_SFML_DIRECTION_HH

enum class Direction { None, Up, Right, Down, Left };

[[nodiscard]] auto oppositeDirection(const Direction& direction) -> Direction;

#endif // SNAKE_SFML_DIRECTION_HH
