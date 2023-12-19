#ifndef GAME_H //definição de cabeçalho
#define GAME_H

#include "player.h"

static short quantidadePalavras{0};
static short tamanho{10}; // Tamanho inicial
static const short MAX_TENTATIVAS = 5;

class Game
{
private:
    ifstream arquivoPalavras;
    ofstream arquivoHistorico;
    string *palavras{nullptr};
    string letrasTentadas;
    string palavraParaAdivinhar;
    string palavraAdivinhada;
    bool end_game; // Flag para identificar fim de jogo

    Player jogador;
public:
    Game(string name_player);
    Game() = delete;
    
    void Open_create_file();
    void Read_file_words();
    void Play();
    void Write_history();
    void End_game();
    void set_game_over(bool flag){ end_game = flag; };
    void set_game_over(){ end_game = false; };
    bool game_over(){ return end_game; };
};





#endif