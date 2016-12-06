#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "Piece.h"
#include "GameState.h"



using namespace std;

SDL_Rect makeNewRect(int x, int y, int w, int h){
    SDL_Rect a;
    a.x = x;
    a.y = y;
    a.w = w;
    a.h = h;
    return a;
};

int main (int argc, char** argv)
{
    //int SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = NULL;
    window = SDL_CreateWindow
    (
     "CPP BEEJeWeLeD - Shapez", SDL_WINDOWPOS_UNDEFINED,
     SDL_WINDOWPOS_UNDEFINED,
     800,
     600,
     SDL_WINDOW_SHOWN
     );
    
    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
    
    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
    
    // Clear winow
    SDL_RenderClear( renderer );
    
    
    
    // Create a Game State
    GameState gameState;
    
    // Generate the game board UI

    int hXw = 50;
    int incX = 60;
    int incY = 60;
    int x = 300;
    int y = 50;
    // Vector of SDL Rectangles
    vector<SDL_Rect> rekts;
    // Vector of Game Pieces
    vector<Piece> pieces;
    
    // Loops and populates the vectors of Rectangles, and Pieces
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            rekts.push_back(makeNewRect(x, y, hXw, hXw));
            pieces.push_back(Piece(x, y));
            SDL_SetRenderDrawColor(renderer,
                                   pieces.back().getR(),
                                   pieces.back().getG(),
                                   pieces.back().getB(),
                                   255);
            SDL_RenderFillRect(renderer, &rekts.back());
            y += incY;
        }
        x += incX;
        y = 50;
    }
    
    // Render the rects to the screen
    SDL_RenderPresent(renderer);
    
    
    
    // Wait for 5 sec
    //SDL_Delay( 20000 );
    
    bool running = true;
    SDL_Event event;
    
    while(running)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;
            }
        }
        
        if(event.type == SDL_MOUSEBUTTONUP)
        {
            /* If the left button was pressed. */
            if (event.button.button == SDL_BUTTON_LEFT){
                int x, y;
                SDL_GetMouseState(&x, &y);
                std::cout << "x= " << x << " y=" << y << std::endl;
                //std::this_thread::sleep_for (std::chrono::milliseconds(500));
            }
        }
        
        
       
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}



