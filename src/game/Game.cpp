#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <vector>

Game::Game() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    initialize();
}

void Game::initialize() {
    grid_ = {};  // Initialize all to 0
    addRandomTile();
    addRandomTile();
}

void Game::addRandomTile() {
    std::vector<std::pair<int, int>> emptyCells;
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (grid_[row][col] == 0) {
                emptyCells.push_back({row, col});
            }
        }
    }
    
    // If no empty cells, return
    if (emptyCells.empty()) {
        return;
    }
    
    // Pick a random empty cell
    int randomIndex = std::rand() % emptyCells.size();
    int row = emptyCells[randomIndex].first;
    int col = emptyCells[randomIndex].second;
    
    grid_[row][col] = (std::rand() % 2 == 0) ? 2 : 4;
}

const Game::Grid& Game::getGrid() const {
    return grid_;
}
