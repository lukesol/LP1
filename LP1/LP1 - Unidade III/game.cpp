#include "game.h"

Game::Game(string name_player)
{
    jogador.set_name(name_player);

    Open_create_file();
    
    set_game_over();
    
}

void Game::Open_create_file(){
    /* this-> */arquivoPalavras.open("palavras.txt");
    
    if (!arquivoPalavras.is_open())
    {
        cerr << "Erro ao abrir o arquivo." << endl;
        exit(EXIT_FAILURE);
    }

    /* this-> */arquivoHistorico.open("historico.txt", std::ofstream::app);

    if (!arquivoHistorico.is_open())
    {
        cerr << "Erro ao abrir o arquivo de histórico." << endl;
        exit(EXIT_FAILURE);
    }
}

void Game::Read_file_words()
{
    // string *palavras = nullptr;string *palavras = nullptr;

        palavras = new string[tamanho]; // Alocando memória inicialmente

        string palavra;
        while (arquivoPalavras >> palavra)
        {
            if (quantidadePalavras == tamanho)
            {
                // Se atingiu o tamanho máximo, realoca o array com o dobro do tamanho
                tamanho *= 2;
                string *temp = new string[tamanho];

                for (int i = 0; i < quantidadePalavras; ++i)
                {
                    temp[i] = palavras[i];
                }

                delete[] palavras; // Libera a memória do array anterior
                palavras = temp;   // Aponta para o novo array
            }

            palavras[quantidadePalavras++] = palavra;
        }
        /* this-> */arquivoPalavras.close();
}

void Game::Play()
{   
        delete[] palavras; // Libera memória utilizada para palavras

        tamanho = 10; // Reseta tamanho

        letrasTentadas.clear(); // Limpa letras tentadas

        palavraAdivinhada.clear();

        palavraParaAdivinhar.clear();


        Read_file_words();

        srand(static_cast<unsigned int>(time(0)));
        int indiceAleatorio = rand() % quantidadePalavras;
        palavraParaAdivinhar = palavras[indiceAleatorio];
        jogador.set_game_played(TurnInfo{palavraParaAdivinhar, false});
        
        int tentativasIncorretas = 0;
        palavraAdivinhada.append(palavraParaAdivinhar.length(), '_');


        while (tentativasIncorretas < MAX_TENTATIVAS && palavraAdivinhada != palavraParaAdivinhar)
        {

            cout << "Palavra a ser adivinhada: " << palavraAdivinhada << endl;

            // Exibindo letras tentadas em ordem alfabética
            if (!letrasTentadas.empty())
            {
                sort(letrasTentadas.begin(), letrasTentadas.end());
                cout << "Letras já tentadas: ";
                for (size_t i = 0; i < letrasTentadas.length(); ++i)
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
            for (size_t i = 0; i < palavraParaAdivinhar.length(); ++i)
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


        if (palavraAdivinhada == palavraParaAdivinhar)
        {
            jogador.set_game_played(TurnInfo{palavraParaAdivinhar, true}); 
            cout << "Parabéns! Você adivinhou a palavra: " << palavraParaAdivinhar << endl;
        }
        else
            cout << "Você excedeu o número máximo de tentativas. A palavra era: " << palavraParaAdivinhar << endl;

}

void Game::Write_history(){
    TurnInfo info_jogador = jogador.get_turn_info();

    if (info_jogador.win)
        arquivoHistorico << "Jogador: " << jogador.get_name() << " Palavra: " << info_jogador.word << " - Resultado: Acertou" << endl;
    else
        arquivoHistorico << "Jogador: " << jogador.get_name() << " Palavra: " << info_jogador.word << " - Resultado: Errou" << endl;


        arquivoHistorico.close(); // Fecha o arquivo de histórico

}
        

void Game::End_game()
{
    
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