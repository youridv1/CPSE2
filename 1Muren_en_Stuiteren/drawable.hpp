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
        if(rectangle != floatRekt){
            return floatRekt.intersects(rectangle);
        }
        return false;
    }

    sf::Rect<float> getFloatRekt(){
        return floatRekt;
    }

    void bounce(drawable & other){
        if(other.getSpeed() != sf::Vector2f(0.0, 0.0)){
            if(!direction){
                if(speed.x / other.getSpeed().x < 0){
                    invertSpeedX();
                    other.invertSpeedX();
                    while(intersect(other.getFloatRekt())){
                        moveX();
                        update();
                    }
                } else if (speed.x > other.getSpeed().x){
                    other.addSpeedX(speed.x);
                    speed.x = 0.0;
                    while(intersect(other.getFloatRekt())){
                        other.moveX();
                        other.update();
                }
                } else {
                    addSpeedX(other.getSpeed().x);
                    other.stopX();
                    while(intersect(other.getFloatRekt())){
                        moveX();
                        update();
                    }
                }
                
            } else if (speed.y / other.getSpeed().y < 0){
                invertSpeedY();
                other.invertSpeedY();
                while(intersect(other.getFloatRekt())){
                    moveY();
                    update();
                }
            } else if (speed.y > other.getSpeed().y){
                other.addSpeedX(speed.y);
                speed.y = 0.0;
                while(intersect(other.getFloatRekt())){
                    other.moveY();
                    other.update();
                }
            } else {
                addSpeedX(other.getSpeed().y);
                other.stopY();
                while(intersect(other.getFloatRekt())){
                    moveY();
                    update();
                }
            }
        } else {
            if(!direction){
                invertSpeedX();
                while(intersect(other.getFloatRekt())){
                    moveX();
                    update();
                }
            } else {
                invertSpeedY();
                while(intersect(other.getFloatRekt())){
                    moveY();
                    update();
                }
            } 
        }
    }

    sf::Vector2f getSpeed(){
        return speed;
    }

    // public speed modifiers
    void invertSpeedX(){ speed.x *= -1.0; }
    void invertSpeedY(){ speed.y *= -1.0; }
    void addSpeedX(const float s){ speed.x += s; }
    void addSpeedY(const float s){ speed.y += s; }
    void stopX(){ speed.x = 0.0; }
    void stopY(){ speed.y = 0.0; }

  protected:
    sf::Rect<float> floatRekt;
    bool direction;
    sf::Vector2f position;
    sf::Color Color;
    float size;
    sf::Vector2f speed;
};