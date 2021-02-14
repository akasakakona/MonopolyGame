
#include<iostream>
#include"TextureManager.h"
#include "GameObj.h"
#include "Board.h"

GameObj *player1;
//SDL_Texture* boardBackGround;

Board* board;

using namespace std;

Game::Game() {}

Game::~Game() {/*NEED TO BE IMPLEMENTED*/ }

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;

    if (fullscreen) {
        //change the flag to full screen
        flags = SDL_WINDOW_MAXIMIZED;//SDL_WINDOW_FULLSCREEN;
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
            SDL_SetRenderDrawColor(renderer, 160, 175, 238, 255);
            cout << "Renderer created successfully" << endl;
        }

        //set is running to true
        isRunning = true;
    }
    //set is running to false if not init correctly
    else {
        isRunning = false;
    }

    //boardBackGround = TextureManager::LoadTexture("images/board.jpg", renderer);

    //player1 = new GameObj("images/mario.png", renderer, 0,0);

    board = new Board(renderer);

   

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

    //player1->update();
    board->board_update();
    
}

//render our object onto screen
void Game::render() {
    //clear the window so images won't overlap
    //ORDER MATTERS
    SDL_RenderClear(renderer);

    //render the board
    //SDL_RenderCopy(renderer, boardBackGround, NULL, NULL);

    board->render_board();



    //add stuff to renderer
    //player1->render();
    
    SDL_RenderPresent(renderer);

    
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "game cleanerd" << endl;
}
