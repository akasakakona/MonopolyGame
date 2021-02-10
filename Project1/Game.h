#ifndef GAME_HPP
#define GAME_HPP

#include<iostream>
#include"SDL.h"
#include"SDL_image.h"

#include<string>

using namespace std;

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; }

private:


    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;


};

#endif
