#include "Game.h"
#include <SDL.h>
#include <iostream>

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow(
        "2048",
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

        // Set color to grey for tiles
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);

        // Draw 4x4 grid of empty tiles
        for (int row = 0; row < Game::GRID_SIZE; ++row) {
            for (int col = 0; col < Game::GRID_SIZE; ++col) {
                // Calculate position for this tile
                int x = offsetX + col * (tileSize + padding);
                int y = offsetY + row * (tileSize + padding);

                // Create rectangle for this tile
                SDL_Rect tileRect = {x, y, tileSize, tileSize};

                // Draw filled rectangle
                SDL_RenderFillRect(renderer, &tileRect);
            }
        }

        // Present the rendered frame
        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
