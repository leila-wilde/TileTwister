#ifndef GAME_H
#define GAME_H

#include <array>

class Game {
public:
    static constexpr int GRID_SIZE = 4;
    using Grid = std::array<std::array<int, GRID_SIZE>, GRID_SIZE>;

    // Constructor
    Game();
    
    // Initialize empty grid
    void initialize();
    
    // Accessors
    const Grid& getGrid() const;
    
private:
    Grid grid_;
};

#endif // GAME_H
