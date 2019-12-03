#include "circle.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include "picture.hpp"
#include "factory.hpp"


int main(){
    sf::RenderWindow window{sf::VideoMode{640, 480}, "SFML window"};
    rectangle Rekt(sf::Vector2f(320.0, 240.0));

    while(window.isOpen()){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && Rekt.contains(sf::Mouse::getPosition())){
            Rekt.jump(sf::Mouse::getPosition(window));
        }
        window.clear();
        Rekt.draw(window);
        window.display();

        sf::sleep(sf::milliseconds(1));

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
}