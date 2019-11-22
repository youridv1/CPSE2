#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class drawable {
  public:
    virtual void draw(sf::RenderWindow& window) const = 0;
    
    drawable(sf::Vector2f position, sf::Color Color, float size = 30.0, sf::Vector2f speed = sf::Vector2f(0.0, 0.0)):
        position(position),
        Color(Color),
        size(size),
        speed(speed) 
        {
            update();
            direction = true;
        }

    void move(sf::Vector2f delta) {
        position += delta;
        update();
    }

    void move() {
        if(direction){
            position.x += speed.x;
        } else {
            position.y += speed.y;
        }
        update();
        direction = !direction;        
    }

    void moveX(){
        position.x += speed.x;
    }

    void moveY(){
        position.y += speed.y;
    }

    void jump(sf::Vector2f target) {
        position = target;
        update();
    }

    void jump(sf::Vector2i target) {
        jump(sf::Vector2f(static_cast<float>(target.x), static_cast<float>(target.y)));
        update();
    }

    virtual void update() {
        floatRekt = sf::Rect<float>(position, sf::Vector2f(2*size, 2*size));
    }

    bool intersect( const sf::Rect<float> & rectangle){
        return floatRekt.intersects(rectangle);
    }

    sf::Rect<float> getFloatRekt(){
        return floatRekt;
    }

    void bounce(const sf::Rect<float> & rectangle){
        if(!direction){
            speed.x *= -1.0;
            while(intersect(rectangle)){
                moveX();
                update();
            }
        } else {
            speed.y *= -1.0;
            while(intersect(rectangle)){
                moveY();
                update();
            }
        }
    }

  protected:
    sf::Rect<float> floatRekt;
    bool direction;
    sf::Vector2f position;
    sf::Color Color;
    float size;
    sf::Vector2f speed;
    
};