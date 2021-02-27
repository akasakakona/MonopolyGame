#include"SDL.h"
#include<iostream>
#include"Game.h"

using namespace std;
int main(int argc, char* argv[]) {

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    unsigned int frameStart;
    int frameTime;
    
    Game* game = new Game();

    game->init("monopoly", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 794, 794, false);

    while (game->running()) {
        //get starting frame
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        //see the frame time
        frameTime = SDL_GetTicks() - frameStart;

        //limit frame if its over 60
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

    }

    game->clean();

    return 0;
}