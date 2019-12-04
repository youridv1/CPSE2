#include "circle.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include "picture.hpp"
#include "factory.hpp"
#include <iostream>

int main(){
    std::vector<std::unique_ptr<drawable>> drawables;
    std::ifstream input("factory.txt");
    try {
        for(;;){
            drawables.push_back(drawable_read(input));
        }
    }catch(end_of_file &){
        // do nothing
    }catch(std::exception & error){
        std::cerr << error.what();
    }

    sf::RenderWindow window{sf::VideoMode{640, 480}, "SFML window"};

    while(window.isOpen()){
        for(auto & obj : drawables){        
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && obj->contains(sf::Mouse::getPosition())){
                obj->jump(sf::Mouse::getPosition(window));
            }
        }

        window.clear();
        for(auto & object : drawables){
            object->draw(window);
        }
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