#include "game.h"

int main()
{
    string player_name;
    cout << "Escolha o nome do jogador: ";
    cin >> player_name;
    
    Game game(player_name); // Inicializando com jogador de nome escrito

    while( not game.game_over())
    {
        game.Play();
        game.Write_history();
        game.End_game();
    }

    game.~Game();

    return EXIT_SUCCESS;
}