#ifndef BALL_HPP
#define BALL_HPP

#include "drawable.hpp"

class ball : public drawable {
    public:
        ball(sf::Vector2f position, float radius, sf::Color Color = sf::Color::White, sf::Vector2f size = sf::Vector2f(0.0, 0.0)):
            drawable(position, size, Color),
            radius(radius)
        {}

        void ball::draw( sf::RenderWindow & window ) const override {
            sf::CircleShape circle;
            circle.setRadius(radius);
            circle.setPosition(position);
            circle.setFillColor(Color);
            window.draw(circle);
        }
        
    protected:
       float radius; 
};

#endif