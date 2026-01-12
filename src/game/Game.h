#ifndef GAME_H
#define GAME_H

#include <array>

class Game {
public:
    using Grid = std::array<std::array<int, 4>, 4>;

    Game();
    void initialize();
    const Grid& getGrid() const;
    
private:
    Grid grid_;
    void addRandomTile();
};

#endif // GAME_H
