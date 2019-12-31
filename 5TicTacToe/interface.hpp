#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "move.hpp"
#include <vector>

class myInterface {
public:
    myInterface(){}

    virtual myMove getMove(const bool player){ return myMove(-1, -1 , -1); };

    virtual void endGame(const float state){}

    virtual void draw(std::vector<myMove> & moves){};
};

#endif