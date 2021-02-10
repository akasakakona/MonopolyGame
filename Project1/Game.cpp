#include "Game.h"
#include<iostream>

SDL_Texture* playerTex;


using namespace std;

Game::Game() {}

Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;

    if (fullscreen) {
        //change the flag to full screen
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        cout << "Subsystems initialised!.." << endl;

        //create window for the game
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        //check window has been created properly
        if (window) {
            cout << "window created successfully" << endl;
        }

        //renderer for the window created above
        renderer = SDL_CreateRenderer(window, -1, 0);

        //check renderer has been created successfuly
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "Renderer created successfully" << endl;
        }

        //set is running to true
        isRunning = true;
    }
    //set is running to false if not init correctly
    else {
        isRunning = false;
    }

    SDL_Surface* temp = IMG_Load("images/mario.png");
    
    playerTex = SDL_CreateTextureFromSurface(renderer, temp);

    SDL_FreeSurface(temp);

}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    //if X is clicked on the window, we will quit the program
    switch (event.type) // check event type
    {
        //if type is equal to quit then isRunning = false
    case SDL_QUIT:
        isRunning = false;
        break;

    default:
        break;
    }

}

void Game::update() {
    
}

//render our object onto screen
void Game::render() {
    SDL_RenderClear(renderer);

    //add stuff to renderer
    SDL_RenderCopy(renderer, playerTex, NULL, NULL);


    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "game cleanerd" << endl;
}
