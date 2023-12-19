#include "game.h"

int main()
{
    Game game("Humano");

    while(!game.game_over())
    {
        game.Play();
        game.Write_history();
        game.End_game();
    }

    return EXIT_SUCCESS;
}
