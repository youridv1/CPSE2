#include "ball.hpp"
#include "action.hpp"
#include "wall.hpp"
#include "vector"

int main(int argc, char* argv[]) {
    sf::RenderWindow window{sf::VideoMode{640, 480}, "SFML window"};
    ball* ballPtr;
    ball myBall{sf::Vector2f{320.0, 240.0}, sf::Color::Blue};
    ball mySecondBall{sf::Vector2f{240.0, 320.0}, sf::Color::Green, 30.0, sf::Vector2f{1.0, 0.5}};
    wall topWall{sf::Vector2f{0.0, 0.0}, sf::Vector2f{640.0, 20.0}, sf::Color::Yellow};
    wall bottomWall{sf::Vector2f{0.0, 460.0}, sf::Vector2f{640.0, 20.0}, sf::Color::Yellow};
    wall leftWall{sf::Vector2f{0.0, 0.0}, sf::Vector2f{20.0, 480.0}, sf::Color::Yellow};
    wall rightWall{sf::Vector2f{620.0, 0.0}, sf::Vector2f{20.0, 480.0}, sf::Color::Yellow};
    wall block{sf::Vector2f{320.0, 240.0}, sf::Vector2f{30.0, 30.0}, sf::Color::Red};

    action actions[] = {action(sf::Keyboard::Left, [&]() { block.move(sf::Vector2f(-2.0, 0.0)); }),
                        action(sf::Keyboard::Right, [&]() { block.move(sf::Vector2f(+2.0, 0.0)); }),
                        action(sf::Keyboard::Up, [&]() { block.move(sf::Vector2f(0.0, -2.0)); }),
                        action(sf::Keyboard::Down, [&]() { block.move(sf::Vector2f(0.0, +2.0)); }),
                        action(sf::Mouse::Left, [&]() { block.jump(sf::Mouse::getPosition(window)); }),
                        };

    action ballActions[] = {action([&](){return ballPtr->intersect(block.getFloatRekt());}, [&](){ballPtr->bounce(block); }),
                            action([&](){return ballPtr->intersect(bottomWall.getFloatRekt());}, [&](){ballPtr->bounce(bottomWall); }),
                            action([&](){return ballPtr->intersect(topWall.getFloatRekt());}, [&](){ballPtr->bounce(topWall); }),
                            action([&](){return ballPtr->intersect(leftWall.getFloatRekt());}, [&](){ballPtr->bounce(leftWall); }),
                            action([&](){return ballPtr->intersect(rightWall.getFloatRekt());}, [&](){ballPtr->bounce(rightWall); }),
                            action([&](){return ballPtr->intersect(myBall.getFloatRekt());}, [&](){ballPtr->bounce(myBall); }),
                            action([&](){return ballPtr->intersect(mySecondBall.getFloatRekt());}, [&](){ballPtr->bounce(mySecondBall); }),
                            action([&]{ballPtr->move();})
                            };

    ball* balls[] = {&myBall, &mySecondBall};
    std::vector<drawable*> drawables = {&topWall, &bottomWall, &rightWall, &leftWall, &block};
    for(auto* ball : balls){
        drawables.push_back(ball);
    }

    while (window.isOpen()) {
        for (auto& action : actions) {
            action();
        }
        
        for (ball* ball : balls){
            ballPtr = ball;
            for (auto& action : ballActions) {
                action();
            }
        }

        window.clear();

        for(auto* drawable : drawables){
            drawable->draw(window);
        }

        window.display();

        sf::sleep(sf::milliseconds(2));

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
    return 0;
}
