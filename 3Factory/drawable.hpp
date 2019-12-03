#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class drawable {
  public:
    drawable(sf::Vector2f position, sf::Vector2f size = sf::Vector2f(30.0, 30.0), sf::Color Color = sf::Color::White ):
        position(position),
        size(size),
        Color(Color)
    {}

    virtual void draw(sf::RenderWindow& window) const = 0;

    void jump(sf::Vector2f target) {
        position = target;
    }

    void jump(sf::Vector2i target) {
        jump(sf::Vector2f(static_cast<float>(target.x), static_cast<float>(target.y)));
    }

  protected:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color Color;
};

#endif