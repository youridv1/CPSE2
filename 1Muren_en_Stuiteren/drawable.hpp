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
    }

    void move() {
        if(direction){
            position.x += speed.x;
        } else {
            position.y += speed.y;
        }
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
    }

    void jump(sf::Vector2i target) {
        jump(sf::Vector2f(static_cast<float>(target.x), static_cast<float>(target.y)));
    }

    virtual void update() {
        floatRekt = sf::Rect<float>(position, sf::Vector2f(2*size, 2*size));
    }

    sf::Vector2f getSpeed(){
        return speed;
    }

    void setSpeed(const sf::Vector2f s){
        speed = s;
    }

    bool intersect( const sf::Rect<float> & rectangle){
        return floatRekt.intersects(rectangle);
    }

    sf::Rect<float> getFloatrekt(){
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

    sf::Rect<float> floatRekt;
    sf::Vector2f position;

  protected:
    bool direction;
    
    sf::Color Color;
    float size;
    sf::Vector2f speed;
    
};