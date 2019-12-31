#include <array>

class move {
private:
    bool player;
    std::array<int, 2> coord;

public:
    move(const bool& p, const int& x, const int& y):
        player( p ),
        coord( {x, y} )
    {}

    bool getPlayer() const { return player; }

    std::array<int, 2> getMove(){ return coord; }  
};