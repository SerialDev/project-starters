
#include<iostream>
#include<SDL2/SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

bool init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        // if succeeded create our window
        g_pWindow = SDL_CreateWindow(title,xpos,ypos, height,width,flags);
        if (g_pWindow != 0) {
            g_pRenderer = SDL_CreateRenderer(g_pWindow,-1,0);
        }
    }
    else
    {
        std::cout << "Failed to init SDL" << std::endl;
        return false; // sdl failed to initialize
    }

    return true;
}

void render()
{
    // set to Black
    SDL_SetRenderDrawColor(g_pRenderer,0,0,0,255);

    // clear window to black
    SDL_RenderClear(g_pRenderer);

    // Show the window
    SDL_RenderPresent(g_pRenderer);
}

int main(int argc, char **argv){
    bool g_bRunning = false; // This will create a loop


    if (init("SDL_INIT", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, SDL_WINDOW_SHOWN)) {
        g_bRunning= true;
    }
    else{
        return 1; 
    }

    while (g_bRunning) {
        render();
    }

    // set a delay before quitting
    SDL_Delay(5000);

    // Clean up
    SDL_Quit();

    return 0;
}
