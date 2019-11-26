#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "drawable.hpp"

class rectangle : public drawable {
    public:
        void draw(sf::RenderWindow& window) const {
            sf::RectangleShape rectangle;
            rectangle.setPosition(position);
            rectangle.setSize(size);
            rectangle.setFillColor(Color);
            window.draw(rectangle); 
        }
};

#endif