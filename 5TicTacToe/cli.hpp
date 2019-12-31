#ifndef CLI_HPP
#define CLI_HPP

#include "interface.hpp"
#include <iostream>

class cli : public myInterface {
public:
    void draw(std::vector<myMove> & moves) override {
        bool found = false;
        for(int y = 0; y < 3; y++){
            for(int x = 0; x < 3; x++){
                found = false;
                for(auto move : moves){
                    if(move.getMove()[0] == x && move.getMove()[1] == y){
                        found = true;
                        if(move.getPlayer()){
                            std::cout << " X ";
                        } else {
                            std::cout << " O ";
                        }
                    }
                }
                if(!found){
                    std::cout << "   ";
                }
                if( x < 2 ){
                    std::cout << '|';
                }
            }
            if( y < 2 ){
                std::cout << '\n' << "-----------" << '\n';
            }
        }
    }

    myMove getMove(const bool player) override {
        int x, y;
        std::cout << "\nGive X coordinate: ";
        std::cin >> x;
        std::cout << "\nGive Y coordinate: ";
        std::cin >> y;
        myMove playedMove(player, x, y);
        return playedMove;
    }

    void endGame(const float state) override {
        if(state == 0.5){
            std::cout << "\ndraw!\n";
        } else {
            std::cout << "\nplayer " << state + 1 << " wins!\n";
        }
    }
};

#endif