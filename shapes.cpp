#include <SDL2/SDL.h>

int main (int argc, char** argv)
{
    SDL_Window* window = NULL;
    window = SDL_CreateWindow
    (
     "there was text here in the code i copeid off of stackoverflow", SDL_WINDOWPOS_UNDEFINED,
     SDL_WINDOWPOS_UNDEFINED,
     640,
     480,
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
    SDL_Rect r;
    r.x = 50;
    r.y = 50;
    r.w = 50;
    r.h = 50;
    
    
    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    
    // Render rect
    SDL_RenderFillRect( renderer, &r );
    
    SDL_Rect a;
    a.x = 150;
    a.y = 50;
    a.w = 50;
    a.h = 50;
    
    
    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
    

    SDL_RenderFillRect(renderer, &a);
    
    // Render the rect to the screen
    
    SDL_RenderPresent(renderer);
    
    // Wait for 5 sec
    SDL_Delay( 2000 );
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}

