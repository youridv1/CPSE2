#include "game.hpp"
#include "cli.hpp"
#include "gui.hpp"
#include "string"

int main(int argc, char *argv[]){
    std::string argument = "default";
    if(argc == 2){
        argument = argv[1];
    }
    if(argument == "graphical"){
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