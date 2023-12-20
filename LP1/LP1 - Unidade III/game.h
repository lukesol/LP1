#ifndef GAME_H //definição de cabeçalho
#define GAME_H

#include "player.h"

static short quantidadePalavras{0};
static short tamanho{10}; // Tamanho inicial
static const short MAX_TENTATIVAS = 5;

class Game
{
private:
    enum class game_state_e : unsigned int { // Controle de estados para funções paralelas
        PLAYING=0,
        WRITING,
        ENDING,
    };

    game_state_e m_game_state;
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
    Game() = delete; // Deleta o construtor que não seja instanciado com o nome do jogador
    ~Game() = default; // Destruto padrão
    
    void Open_file();
    void Read_file_words();
    void Play();
    void Write_history();
    void End_game();
    void set_game_over(){ end_game = false; }; // Setar flag do game_over para false como valor inicial
    void set_game_over(bool flag){ end_game = flag; }; // Setar flag do game_over para true com sobrecarga
    bool game_over(){ return end_game; };
};





#endif