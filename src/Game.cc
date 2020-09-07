#include "Game.hh"
#include "Config.hh"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

using namespace config;

Game::Game(sf::RenderWindow& window) : window {window} {}

void Game::run() {
  while (true) {
    if (!handleEvents()) {
      return;
    }

    handleKeys();

    // TODO
    if (clock.getElapsedTime() >= sf::seconds(score < 10 ? 0.20F : 0.15F)) {
      snake.move();
      if (!snake.isPositionValid()) {
        break;
      }

      if (snake.getHeadGlobalBounds().intersects(food.getGlobalBounds())) {
        score += 1;
        food = Food {};
        snake.grow();
      }

      clock.restart();
    }

    draw();
  }

  show_score();
}

// TODO
auto Game::handleEvents() const -> bool {
  sf::Event event {};
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
      return false;
    }
  }

  return true;
}

void Game::handleKeys() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    snake.turn(Direction::Up);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    snake.turn(Direction::Right);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    snake.turn(Direction::Down);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    snake.turn(Direction::Left);
  }
}

void Game::draw() const {
  window.clear(sf::Color::Black);

  window.draw(food);
  window.draw(snake);

  window.display();
}

void Game::show_score() const {
  sf::Font font {};

  // FIXME
  font.loadFromFile("./assets/FiraCode-Bold.ttf") ||
      font.loadFromFile("../assets/FiraCode-Bold.ttf");

  sf::Text text {std::to_string(score), font, fontSize};

  auto textRect {text.getGlobalBounds()};
  text.setOrigin(textRect.left + textRect.width / 2,
                 textRect.top + textRect.height / 2);

  text.setPosition(windowSize / 2.F, windowSize / 2.F);

  auto initialTime {clock.getElapsedTime()};
  while (clock.getElapsedTime() - initialTime <= sf::seconds(2)) {
    if (!handleEvents()) {
      return;
    }

    window.clear(sf::Color::Black);
    window.draw(text);
    window.display();
  }
}
