#include "Tile.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

Tile::Tile(int x, int y, int size, int value)
    : GameObject(x, y, size, size), value_(value) {
}

void Tile::render(SDL_Renderer* renderer) {
    SDL_Rect rect = {x_, y_, width_, height_};
    
    SDL_SetRenderDrawColor(renderer, value_ == 0 ? 200 : 220, 200, 200, 255);
    SDL_RenderFillRect(renderer, &rect);
    
    SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
    SDL_RenderDrawRect(renderer, &rect);
    
    if (value_ != 0) {
        static TTF_Font* font = nullptr;
        static bool font_loaded = false;
        
        if (!font_loaded) {
            font = TTF_OpenFont("/System/Library/Fonts/Helvetica.ttc", 48);
            if (!font) font = TTF_OpenFont("/System/Library/Fonts/Supplemental/Arial.ttf", 48);
            if (!font) font = TTF_OpenFont("/Library/Fonts/Arial.ttf", 48);
            font_loaded = true;
        }
        
        if (font) {
            std::string valueStr = std::to_string(value_);
            SDL_Color textColor = {50, 50, 50, 255};
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, valueStr.c_str(), textColor);
            
            if (textSurface) {
                SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                if (textTexture) {
                    SDL_Rect textRect = {x_ + (width_ - textSurface->w) / 2,
                                        y_ + (height_ - textSurface->h) / 2,
                                        textSurface->w, textSurface->h};
                    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
                    SDL_DestroyTexture(textTexture);
                }
                SDL_FreeSurface(textSurface);
            }
        }
    }
}

void Tile::setValue(int value) {
    value_ = value;
}
