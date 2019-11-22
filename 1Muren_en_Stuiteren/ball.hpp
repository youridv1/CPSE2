#ifndef _BALL_HPP
#define _BALL_HPP

#include "drawable.hpp"

class ball : public drawable {
  public:
    ball(sf::Vector2f position, sf::Color Color, float size = 30.0, sf::Vector2f speed = sf::Vector2f(0.5, 1.0));

    void draw(sf::RenderWindow& window) const override;
};

#endif
