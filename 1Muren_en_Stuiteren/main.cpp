#include "ball.hpp"
#include "action.hpp"
#include "wall.hpp"

int main(int argc, char* argv[]) {
    sf::RenderWindow window{sf::VideoMode{640, 480}, "SFML window"};
    ball my_ball{sf::Vector2f{320.0, 240.0}, sf::Color::Blue};
    wall top_wall{sf::Vector2f{0.0, 0.0}, sf::Vector2f{640.0, 20.0}, sf::Color::Yellow};
    wall bottom_wall{sf::Vector2f{0.0, 460.0}, sf::Vector2f{640.0, 20.0}, sf::Color::Yellow};
    wall left_wall{sf::Vector2f{0.0, 0.0}, sf::Vector2f{20.0, 480.0}, sf::Color::Yellow};
    wall right_wall{sf::Vector2f{620.0, 0.0}, sf::Vector2f{20.0, 480.0}, sf::Color::Yellow};
    wall blokje{sf::Vector2f{320.0, 240.0}, sf::Vector2f{30.0, 30.0}, sf::Color::Red};

    action actions[] = {action(sf::Keyboard::Left, [&]() { blokje.move(sf::Vector2f(-2.0, 0.0)); }),
                        action(sf::Keyboard::Right, [&]() { blokje.move(sf::Vector2f(+2.0, 0.0)); }),
                        action(sf::Keyboard::Up, [&]() { blokje.move(sf::Vector2f(0.0, -2.0)); }),
                        action(sf::Keyboard::Down, [&]() { blokje.move(sf::Vector2f(0.0, +2.0)); }),
                        action(sf::Mouse::Left, [&]() { blokje.jump(sf::Mouse::getPosition(window)); })};

    while (window.isOpen()) {
        for (auto& action : actions) {
            action();
        }

        window.clear();
        my_ball.draw(window);
        top_wall.draw(window);
        bottom_wall.draw(window);
        left_wall.draw(window);
        right_wall.draw(window);
        blokje.draw(window);
        window.display();

        sf::sleep(sf::milliseconds(20));

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
    return 0;
}
