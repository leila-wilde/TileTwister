#include "game/Game.h"
#include "rendering/GameObject.h"
#include "rendering/Tile.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>
#include <memory>

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        std::cerr << "TTF_Init error: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow(
        "Tile Twister",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        800,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Create game instance
    Game game;

    // Grid drawing constants
    const int tileSize = 150;
    const int padding = 10;
    const int offsetX = 100;
    const int offsetY = 100;

    // Create tiles using GameObject pattern, reading values from game grid
    std::vector<std::unique_ptr<GameObject>> tiles;
    const Game::Grid& grid = game.getGrid();
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            int x = offsetX + col * (tileSize + padding);
            int y = offsetY + row * (tileSize + padding);
            int value = grid[row][col];
            tiles.push_back(std::make_unique<Tile>(x, y, tileSize, value));
        }
    }

    // Main loop
    SDL_Event e;
    bool quit = false;
    while (!quit) {
        // Handle events
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear screen with white background
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Render all tiles using GameObject interface
        for (auto& tile : tiles) {
            tile->render(renderer);
        }

        // Present the rendered frame
        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    // Cleanup
    tiles.clear();  // Destroy all GameObject instances
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    
    return 0;
}
