
#include "Game.h"


Game* g_game = 0;


int main(int argc, char **argv){

    g_game = new Game();
    g_game->init("SDL_INIT", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, false);


    while (g_game->running()) {
        g_game->handleEvents();
        // g_game->update();
        g_game->render();
    }

    g_game->clean();


    return 0;
}
