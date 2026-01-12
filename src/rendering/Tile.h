#ifndef TILE_H
#define TILE_H

#include "GameObject.h"

class Tile : public GameObject {
public:
    Tile(int x, int y, int size, int value = 0);
    
    void render(SDL_Renderer* renderer) override;
    void setValue(int value);
    
private:
    int value_;
};

#endif // TILE_H
