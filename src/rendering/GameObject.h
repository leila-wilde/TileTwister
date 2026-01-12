#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>

class GameObject {
public:
    // Constructor
    GameObject(int x, int y, int width, int height);
    
    // Virtual destructor (important for inheritance)
    virtual ~GameObject() = default;
    
    // Pure virtual render method - must be implemented by derived classes
    virtual void render(SDL_Renderer* renderer) = 0;
    
    // Accessors
    int getX() const { return x_; }
    int getY() const { return y_; }
    int getWidth() const { return width_; }
    int getHeight() const { return height_; }
    
    // Setters
    void setX(int x) { x_ = x; }
    void setY(int y) { y_ = y; }
    void setPosition(int x, int y) { x_ = x; y_ = y; }
    void setSize(int width, int height) { width_ = width; height_ = height; }
    
protected:
    // Protected so derived classes can access them
    int x_;
    int y_;
    int width_;
    int height_;
};

#endif // GAMEOBJECT_H
