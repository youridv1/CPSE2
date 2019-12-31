#include "game.hpp"
#include "cli.hpp"

int main(){
    cli commandline;
    TicTacToe game( commandline );
    game.main();
    return 0;
}