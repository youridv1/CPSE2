#ifndef PICTURE_HPP
#define PICTURE_HPP

#include "drawable.hpp"

class picture : public drawable {
public:
    picture(sf::Vector2f position, std::string filename):
        drawable(position),
        filename(filename) 
    {
        texture.loadFromFile(filename);
        sprite.setTexture(texture);
        sprite.setPosition(position);
        sprite.setScale(sf::Vector2f(0.1, 0.1));
    }
    
private:
    std::string filename;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif