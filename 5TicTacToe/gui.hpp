#ifndef GUI_HPP
#define GUI_HPP

#include "interface.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class gui : public myInterface {
public:
    gui(sf::RenderWindow& window):
        window( window )
    {}

    void draw(std::vector<myMove> & moves) override {
        float x;
        float y;
        sf::Vector2f size{205.0, 205.0};
        sf::Color color;
        window.clear();
        // Draw Tic Tac Toe Grid
        drawRectangle(sf::Vector2f{0.0, 205.0}, sf::Vector2f{655.0, 20.0}, sf::Color::Yellow);
        drawRectangle(sf::Vector2f{0.0, 430.0}, sf::Vector2f{655.0, 20.0}, sf::Color::Yellow);
        drawRectangle(sf::Vector2f{205.0, 0.0}, sf::Vector2f{20.0, 655.0}, sf::Color::Yellow);
        drawRectangle(sf::Vector2f{430.0, 0.0}, sf::Vector2f{20.0, 655.0}, sf::Color::Yellow);
        for( auto move : moves ){
            // Which X
            if(move.getMove()[0] == 0){ x = 0.0 ;}
            else if(move.getMove()[0] == 1){ x = 225.0;}
            else{ x = 450.0; }
            // Which Y
            if(move.getMove()[1] == 0){ y = 0.0 ;}
            else if(move.getMove()[1] == 1){ y = 225.0;}
            else{ y = 450.0; }
            // Which Player
            if(move.getPlayer()){ color = sf::Color::Blue; }
            else{ color = sf::Color::Red; }
            // Draw Move
            drawRectangle(sf::Vector2f{x, y}, size, color);
        }
        window.display();
    } 

    myMove getMove(const bool player) override {
        // If Clicked
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){ 
            int x, y;
            auto pos = sf::Mouse::getPosition(window);
            // Check for Undo
            if(pos.x > 655){
                return myMove(-2, -2 , -2);
            }
            // Determine X
            if(pos.x >= 450.0){ x = 2; }
            else if(pos.x >= 225 ){ x = 1; }
            else{ x = 0; }
            // Determine Y
            if(pos.y >= 450.0){ y = 2; }
            else if(pos.y >= 225 ){ y = 1; }
            else{ y = 0; }
            // Return Move
            return myMove(player, x, y);
        }
        // Default if no mouse click was registered
        return myMove(-1, -1 , -1);
    }

    void endGame(const float state) override {
        auto color = sf::Color::Red;
        window.clear();
        if(state == 0.5){
            color = sf::Color::Magenta;
        }else if(state){
            color = sf::Color::Blue;
        }
        drawRectangle(sf::Vector2f{0, 0}, sf::Vector2f{655, 655}, color);
        window.display();
        sf::sleep(sf::seconds(5));
    }

    void drawRectangle(sf::Vector2f position, sf::Vector2f size, sf::Color Color) {
        sf::RectangleShape rectangle;
        rectangle.setPosition(position);
        rectangle.setSize(size);
        rectangle.setFillColor(Color);
        window.draw(rectangle);
    }

private:
    sf::RenderWindow& window;
};

#endif