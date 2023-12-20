#include "game.h"

/// @brief Inicializa o jogo lendo arquivo de palavras.
/// @param name_player 
Game::Game(string name_player)
{
    jogador.set_name(name_player);

    Open_file();
    
    set_game_over();

    Read_file_words();

    m_game_state = game_state_e::PLAYING;
    
}

/// @brief Abre o arquivo de palavras.
void Game::Open_file(){
    arquivoPalavras.open("palavras.txt");
    
    if (!arquivoPalavras.is_open())
    {
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(EXIT_FAILURE);
    }

}

/// @brief Lê as palavras do arquivo aberto incialmente.
void Game::Read_file_words()
{
        string palavra;

        palavras = new string[tamanho]; // Alocando memória com tamanho inicial

        while (arquivoPalavras >> palavra)
        {
            if (quantidadePalavras == tamanho)
            {
                // Se atingiu o tamanho máximo, realoca o array com o mais 10 do tamanho
                tamanho += 10;

                string *temp = new string[tamanho];

                for (int i = 0; i < quantidadePalavras; i++)
                {
                    temp[i] = palavras[i];
                }

                delete[] palavras; // Libera a memória do array anterior
                palavras = temp;   // Aponta para o novo array
            }
            
            palavras[quantidadePalavras++] = palavra;

        }
        arquivoPalavras.close();
}

/// @brief Executa jogada do Game.
void Game::Play()
{       
        if(m_game_state == game_state_e::PLAYING){
            
            int tentativasIncorretas = 0;
            srand(static_cast<unsigned int>(time(0)));
            int indiceAleatorio = rand() % quantidadePalavras;

            palavraParaAdivinhar = palavras[indiceAleatorio];

            jogador.set_game_played(TurnInfo{palavraParaAdivinhar, false});
            

            palavraAdivinhada.append(palavraParaAdivinhar.length(), '_');


            while (tentativasIncorretas < MAX_TENTATIVAS && palavraAdivinhada != palavraParaAdivinhar)
            {

                cout << "Palavra a ser adivinhada: " << palavraAdivinhada << endl;

                // Exibindo letras tentadas em ordem alfabética
                if (!letrasTentadas.empty())
                {
                    sort(letrasTentadas.begin(), letrasTentadas.end());
                    cout << "Letras já tentadas: ";
                    for (size_t i = 0; i < letrasTentadas.length(); i++)
                    {
                        cout << letrasTentadas[i] << "  ";
                    }
                    cout << endl;
                }

                cout << "Digite uma letra: ";
                char chute;
                cin >> chute;
                cout << "\033[2J\033[1;1H"; // Limpa o terminal

                if (letrasTentadas.find(chute) != string::npos)
                {
                    cout << "Você já tentou essa letra. Tente outra." << endl;
                    continue;
                }

                letrasTentadas += chute;

                bool encontrou = false;
                for (size_t i = 0; i < palavraParaAdivinhar.length(); i++)
                {
                    if (palavraParaAdivinhar[i] == chute)
                    {
                        palavraAdivinhada[i] = chute;
                        encontrou = true;
                    }
                }

                if (!encontrou)
                {
                    ++tentativasIncorretas;
                    cout << "Letra incorreta! Tente novamente. Tentativas restantes: " << MAX_TENTATIVAS - tentativasIncorretas << endl;
                }
            }

            if(palavraAdivinhada != "" and palavraParaAdivinhar != ""){
                if (palavraAdivinhada.compare(palavraParaAdivinhar) == 0)
                {
                    jogador.set_game_played(TurnInfo{palavraParaAdivinhar, true}); 
                    cout << "Parabéns! Você adivinhou a palavra: " << palavraParaAdivinhar << endl;
                }
                else
                    cout << "Você excedeu o número máximo de tentativas. A palavra era: " << palavraParaAdivinhar << endl;
            }

        }

        m_game_state = game_state_e::WRITING;
}

/// @brief Escreve no arquivo saida de historico a palavra sorteada e se advinhou ou não.
void Game::Write_history(){
    if(m_game_state == game_state_e::WRITING){

        TurnInfo info_jogador = jogador.get_turn_info();

        arquivoHistorico.open("historico.txt", std::ofstream::app);

        if (!arquivoHistorico.is_open())
        {
            cerr << "Erro ao abrir o arquivo de histórico." << endl;
            exit(EXIT_FAILURE);
        }

        if (info_jogador.win)
            arquivoHistorico << "Jogador: " << jogador.get_name() << " Palavra: " << palavraParaAdivinhar << " - Resultado: Acertou" << endl;
        else
            arquivoHistorico << "Jogador: " << jogador.get_name() << " Palavra: " << palavraParaAdivinhar << " - Resultado: Errou" << endl;


            arquivoHistorico.close(); // Fecha o arquivo de histórico
    }

        m_game_state = game_state_e::ENDING;

}

/// @brief Pergunta ao jogador se quer continuar ou não.
void Game::End_game()
{

    if(m_game_state == game_state_e::ENDING){
        if(palavraAdivinhada != "" and palavraParaAdivinhar != ""){
            // Pergunta ao usuário se deseja jogar novamente
            cout << "Deseja jogar novamente? (S/N): ";
            char escolha;
            cin >> escolha;

            if (toupper(escolha) != 'S')
            {
                cout << "Obrigado por jogar! Até a próxima." << endl;
                set_game_over(true); // Sai do loop se a escolha não for 'S'
            }
        }

        if(end_game)
            delete[] palavras; // Libera memória utilizada para palavras caso encerre o jogo

        letrasTentadas.clear(); // Limpa letras tentadas

        palavraAdivinhada.clear(); // Limpa palavra que foi gerada na tentativa de advinhação

        palavraParaAdivinhar.clear(); // Palavra sorteada para ser advinhada

    }

    m_game_state = game_state_e::PLAYING;
       
}