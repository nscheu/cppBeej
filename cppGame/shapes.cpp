#include <SDL2/SDL.h>
#include <vector>
#include "Piece.h"

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
    
    // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
    SDL_Rect r = makeNewRect(50, 50, 50, 50);
    
    
    // Set render color to blue ( rect will be rendered in this color )
    //SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    
    // Render rect
    SDL_RenderFillRect( renderer, &r );
    
//    SDL_Rect a = makeNewRect(150, 50, 50, 50);
//    SDL_Rect b = makeNewRect(250, 50, 50, 50);
//    SDL_Rect c = makeNewRect(350, 250, 50, 50);
//    SDL_Rect d = makeNewRect(450, 350, 50, 50);

    int hXw = 50;
    int incX = 60;
    int incY = 60;
    int x = 50;
    int y = 50;
    vector<SDL_Rect> rekts;
    vector<Piece> pieces;
    int randomColor = 255;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            rekts.push_back(makeNewRect(x, y, hXw, hXw));
            pieces.push_back(Piece(x, y));
            SDL_SetRenderDrawColor(renderer,
                                   0,
                                   pieces.back().getR(),
                                   pieces.back().getG(),
                                   pieces.back().getB() );
            SDL_RenderFillRect(renderer, &rekts.back());
            y += incY;
        }
        x += incX;
        y = 50;
    }
    
    
    
    
    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
    

//    SDL_RenderFillRect(renderer, &a);
//    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
//    SDL_RenderFillRect(renderer, &b);
//    SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
//    SDL_RenderFillRect(renderer, &c);
//    SDL_SetRenderDrawColor( renderer, 0, 255, 255, 0 );
//    SDL_RenderFillRect(renderer, &d);
    
    //SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
    
    // Render the rect to the screen
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
        
        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            SDL_DestroyWindow(window);
            SDL_Quit();
        }
        
        
       
    }
    
    //SDL_DestroyWindow(window);
    //SDL_Quit();
    
    return EXIT_SUCCESS;
}



