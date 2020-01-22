#include "game.hpp"
#include "cli.hpp"
#include "gui.hpp"

int main(){
    sf::RenderWindow window{sf::VideoMode{655, 700}, "Tic Tac Toe"};
    cli commandline;
    gui gui{window};
    TicTacToe game( gui );
    game.main();
    return 0;
}