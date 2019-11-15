#pragma once

#include <SFML/Graphics.hpp>

class drawable {
  public:
    virtual void draw(sf::RenderWindow& window) const = 0;
    
    drawable(sf::Vector2f position, sf::Color Color, float size = 30.0, sf::Vector2f speed = sf::Vector2f(0.0, 0.0))
        : position(position), Color(Color), size(size), speed(speed) {}

    void move(sf::Vector2f delta) {
        position += delta;
    }

    void jump(sf::Vector2f target) {
        position = target;
    }

    void jump(sf::Vector2i target) {
        jump(sf::Vector2f(static_cast<float>(target.x), static_cast<float>(target.y)));
    }

  protected:
    sf::Vector2f position;
    sf::Color Color;
    float size;
    sf::Vector2f speed;
};