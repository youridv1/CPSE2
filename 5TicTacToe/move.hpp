#ifndef MOVE_HPP
#define MOVE_HPP

#include <array>

class myMove {
private:
    bool player;
    std::array<int, 2> coord;

public:
    myMove(const bool& p, const int& x, const int& y):
        player( p ),
        coord( {x, y} )
    {}

    bool getPlayer() const { return player; }

    std::array<int, 2> getMove(){ return coord; }  
};

#endif