#include "Tile.h"
#include <SDL.h>

Tile::Tile(int x, int y, int size)
    : GameObject(x, y, size, size), color_{200, 200, 200, 255} {
    // Default grey color
}

void Tile::render(SDL_Renderer* renderer) {
    // Create rectangle for this tile
    SDL_Rect rect = {x_, y_, width_, height_};
    
    // Set render color
    SDL_SetRenderDrawColor(renderer, color_.r, color_.g, color_.b, color_.a);
    
    // Draw filled rectangle
    SDL_RenderFillRect(renderer, &rect);
}

void Tile::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    color_.r = r;
    color_.g = g;
    color_.b = b;
    color_.a = a;
}
