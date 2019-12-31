#ifndef GAME_HPP
#define GAME_HPP

#include "move.hpp"
#include <vector>
#include "interface.hpp"
#include <iostream>

class TicTacToe {
private:
    std::vector<myMove> moves;
    myInterface& interface;

public:
    TicTacToe(myInterface& interface):
        interface( interface )
    {}

    void move( const myMove m ){
        moves.push_back(m);
    }

    float checkWin(){
        // Vectors for all possible lines in a game of Tic Tac Toe
        std::vector<bool> leftVert  = {};
        std::vector<bool> midVert   = {};
        std::vector<bool> rightVert = {};
        std::vector<bool> topHor    = {};
        std::vector<bool> midHor    = {};
        std::vector<bool> botHor    = {};
        std::vector<bool> diagUp    = {};
        std::vector<bool> diagDown  = {};

        bool player;
        int x;
        int y;
        for( auto move : moves ){
            player = move.getPlayer();
            x = move.getMove()[0];
            y = move.getMove()[1];
            if(x == 0){leftVert.push_back( player );}
            if(x == 1){midVert.push_back( player );}
            if(x == 2){rightVert.push_back( player );}
            if(y == 0){topHor.push_back( player );}
            if(y == 1){midHor.push_back( player );}
            if(y == 2){botHor.push_back( player );}
            if(x == y){diagDown.push_back( player );}
            if(x == 0 && y == 2 || x == 1 && y == 1 || x == 2 && y == 0){diagUp.push_back(player);}
        }
        std::vector<std::vector<bool>*> pos = {&leftVert, &midVert, &rightVert, &topHor, &midHor, &botHor, &diagUp, &diagDown};
        for(auto p : pos){
            if(p->size() == 3 && p->at(0) == p->at(1) && p->at(0) == p->at(2)){
                return 1;
            }
        }
        if(moves.size() > 8){
            return 0.5;
        }
        return 0;
    }

    bool getLastPlayer(){ return moves.back().getPlayer(); }

    void main(){
        bool player = 0;
        while( checkWin() == 0.0 ){
            move(interface.getMove(player));
            interface.draw(moves);
            player = !player;
        }
        if(checkWin() == 0.5){
            interface.endGame( 0.5 );
        } else {
            interface.endGame(getLastPlayer());
        }   
    }
};

#endif