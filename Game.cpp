#include "Game.h"

Game::Game() {
    initialize();
}

void Game::initialize() {
    // Initialize empty grid with zeros
    for (int row = 0; row < GRID_SIZE; ++row) {
        for (int col = 0; col < GRID_SIZE; ++col) {
            grid_[row][col] = 0;
        }
    }
}

const Game::Grid& Game::getGrid() const {
    return grid_;
}