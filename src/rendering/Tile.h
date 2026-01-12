#ifndef TILE_H
#define TILE_H

#include "GameObject.h"

class Tile : public GameObject {
public:
    // Constructor
    Tile(int x, int y, int size);
    
    // Override render method - renders as a geometric shape (rectangle)
    void render(SDL_Renderer* renderer) override;
    
    // Set color
    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
    
private:
    SDL_Color color_;
};

#endif // TILE_H
