/**
  * Game.h
  *
  * Author: SerialDev
  * Modified: 2018-12-07
  * Licence: GNU GPL
  */
#ifndef __Game__
#define __Game__
#include<SDL2/SDL.h>

class Game
{
  public:
    Game() {};
    ~Game() {};
    // void init() { m_bRunning = true;}
    bool init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);

    void render();
    void handleEvents();
    // void update();
    void clean();

    // A Function to access the private running variable
    bool running() { return m_bRunning; }

private:

    SDL_Window* m_pWindow = 0;
    SDL_Renderer* m_pRenderer = 0;

    SDL_Texture* m_pTexture;
    SDL_Rect m_sourceRectangle;
    SDL_Rect m_destinationRectangle;
    
    bool m_bRunning;
};



#endif

