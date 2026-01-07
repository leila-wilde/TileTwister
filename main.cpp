#include <iostream>
#include <SDL.h>
#include <array>

using Grid = std::array<std::array<int, 4>, 4>;

Grid new_grid()
{
    Grid grid{};
    for (int x = 0; x < 4; ++x)
        for (int y = 0; y < 4; ++y)
            grid[x][y] = 0;
    return grid;
}

int main () 
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "2048",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        800,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr)
    {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    const int tileSize = 150;
    const int padding = 10;
    const int offsetX = 100;
    const int offsetY = 100;

    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);

        for (int row = 0; row < 4; ++row)
        {
            for (int col = 0; col < 4; ++col)
            {
                int x = offsetX + col * (tileSize + padding);
                int y = offsetY + row * (tileSize + padding);
                SDL_Rect tileRect = {x, y, tileSize, tileSize};
                SDL_RenderFillRect(renderer, &tileRect);
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}