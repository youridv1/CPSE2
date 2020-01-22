#include "game.hpp"
#include "cli.hpp"
#include "gui.hpp"

#define GRAPHICAL false

int main(){
    if(GRAPHICAL){
        sf::RenderWindow window{sf::VideoMode{700, 655}, "Tic Tac Toe"};
        gui gui{window};
        TicTacToe game( gui );
        game.main();
    } else {
        cli commandline;
        TicTacToe game( commandline );
        game.main();
    }
    return 0;
}