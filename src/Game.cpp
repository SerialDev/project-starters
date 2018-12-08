#include "Game.h"
#include<iostream>

bool Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        std::cout << "SDL init Success" << std::endl;

        int flags = 0;
        if (fullscreen) {
            flags = SDL_WINDOW_FULLSCREEN;
        }

        // if succeeded create our window
        m_pWindow = SDL_CreateWindow(title,xpos,ypos, height,width,flags);

        if (m_pWindow != 0) {
            std::cout << "window creation success" << std::endl;
            m_pRenderer = SDL_CreateRenderer(m_pWindow,-1,0);

            if (m_pRenderer != 0) {
                std::cout << "Renderer creation success" << std::endl;
                SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
            }else{
                std::cout << "renderer init fail" << std::endl;
                return false; // renderer init fail
            }

        } else {
                std::cout << "Window init fail" << std::endl;
                return false; // window init fail
            }
    }
    else
    {
        std::cout << "Failed to init SDL" << std::endl;
        return false; // sdl failed to initialize
    }

    SDL_Surface* pTempSurface = SDL_LoadBMP("../assets/rider.bmp");

    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,pTempSurface);

    SDL_FreeSurface(pTempSurface);

    SDL_QueryTexture(m_pTexture,NULL,NULL,&m_sourceRectangle.w,&m_sourceRectangle.h);

    m_destinationRectangle.x = m_sourceRectangle.x = 0;
    m_destinationRectangle.y = m_sourceRectangle.y = 0;
    m_destinationRectangle.w = m_sourceRectangle.w;
    m_destinationRectangle.h = m_sourceRectangle.h;


    std::cout << "init success" << std::endl;
    m_bRunning = true;
    return true;
}

void Game::render()
{
    // // set to Black
    // SDL_SetRenderDrawColor(g_pRenderer,0,0,0,255);

    // clear window to black
    SDL_RenderClear(m_pRenderer);

    SDL_RenderCopy(m_pRenderer,m_pTexture,&m_sourceRectangle,&m_destinationRectangle);

    // Show the window
    SDL_RenderPresent(m_pRenderer);
}

void Game::handleEvents(){
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        default:
            break;
        }
    }
}



void Game::clean(){
    std::cout << "cleaning game" << "\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);

    // set a delay before quitting
    SDL_Delay(5000);

    // Clean up
    SDL_Quit();
}
