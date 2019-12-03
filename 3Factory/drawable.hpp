#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class drawable {
  public:
    drawable(sf::Vector2f position, sf::Vector2f size = sf::Vector2f(30.0, 30.0), sf::Color Color = sf::Color::White ):
        position(position),
        size(size),
        Color(Color),
        fRect(position, -size)
    {}

    virtual void draw(sf::RenderWindow& window) const = 0;

    void jump(sf::Vector2f target) {
        position = target;
        update();
    }

    void jump(sf::Vector2i target) {
        jump(sf::Vector2f(static_cast<float>(target.x), static_cast<float>(target.y)));
    }

    void update(){
      fRect = sf::Rect<float>(position, -size);
    }

    template<typename T>
    bool contains(const sf::Vector2<T> & point){
      sf::Vector2f cPoint = sf::Vector2f(static_cast<float>(point.x), static_cast<float>(point.y));
      return fRect.contains(cPoint);
    }

  protected:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color Color;
    sf::Rect<float> fRect;
};

#endif