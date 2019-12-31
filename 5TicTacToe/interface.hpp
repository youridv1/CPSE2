#include "move.hpp"

class myInterface {
public:
    myInterface(){}

    virtual move getMove(){}

    virtual void endGame(const float state){}

    virtual void draw(const std::vector<move> & moves){};
};