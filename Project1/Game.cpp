
#include<iostream>
#include"TextureManager.h"
#include"Button.h"
#include"Mouse.h"

using namespace std;

Game::Game() {
    player1 = nullptr;
    player2 = nullptr;
    board = nullptr;
    roll_dice = nullptr;
    mouse = nullptr;
    isRunning = false;
    window = nullptr;
    renderer = nullptr;
}

Game::~Game() {
    delete player1;
    //need to add player2 destructor
    delete board;
    delete roll_dice;
    delete mouse;
}

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
    SDL_ShowCursor(false);

    player1 = new Player(20,20,0,0,renderer, "images/mario.png");

    board = new Board(renderer);

    roll_dice = new Button(0,0, renderer, "images/roll.png");
    roll_dice->setXY((796 / 2) - 60, 200);

    mouse = new Mouse(renderer, "images/mouse.png");
   

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
    case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT && roll_dice->get_selected()) {
            player1->update(66, 0);
            break;
        }

    default:
        break;
    }

}

void Game::update() {

    SDL_GetMouseState(&(mouse->cursor.x),&(mouse->cursor.y));
    board->board_update();
    roll_dice->checkSelected(mouse);
    
}

//render our object onto screen
void Game::render() {
    //clear the window so images won't overlap
    //ORDER MATTERS
    SDL_RenderClear(renderer);


    board->render_board();
    roll_dice->render();
    mouse->render();


    //add stuff to renderer
    player1->render();
    
    SDL_RenderPresent(renderer);

    
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "game cleanerd" << endl;
}
