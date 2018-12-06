#include<iostream>
#include<SDL2/SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char **argv){

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "Error while initializing SDL: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }
    std::cout << "SDL Initialized " << std::endl;

    g_pWindow = SDL_CreateWindow("Setting up",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480, SDL_WINDOW_SHOWN);

    if (g_pWindow != 0)
    {
        g_pRenderer = SDL_CreateRenderer(g_pWindow, -1,0);
    }

    // everything succeeded lets draw the window
    // set to black
    SDL_SetRenderDrawColor(g_pRenderer,0,0,0,255);

    // clear window to black
    SDL_RenderClear(g_pRenderer);

    // Show the window
    SDL_RenderPresent(g_pRenderer);

    // set a delay before quitting
    SDL_Delay(5000);
    
    // Clean up 
    SDL_Quit();

    return 0;
}
