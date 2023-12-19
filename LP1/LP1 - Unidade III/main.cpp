#include "game.h"

int main()
{
    Game game("Humano"); // Inicializando

    while(!game.game_over())
    {
        game.Play();
    }

    return EXIT_SUCCESS;
}
