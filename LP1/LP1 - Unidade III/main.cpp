#include "player.h"

int main()
{
    do
    {
        ifstream arquivoPalavras("palavras.txt");
        if (!arquivoPalavras)
        {
            cerr << "Erro ao abrir o arquivo." << endl;
            return 1;
        }

        ofstream arquivoHistorico("historico.txt");
        if (!arquivoHistorico)
        {
            cerr << "Erro ao abrir o arquivo de histórico." << endl;
            return 1;
        }

        string *palavras = nullptr;
        int tamanho = 10; // Tamanho inicial
        int quantidadePalavras = 0;

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
        arquivoPalavras.close();

        srand(static_cast<unsigned int>(time(0)));
        int indiceAleatorio = rand() % quantidadePalavras;
        string palavraParaAdivinhar = palavras[indiceAleatorio];

        const int MAX_TENTATIVAS = 5;
        int tentativasIncorretas = 0;
        string palavraAdivinhada(palavraParaAdivinhar.length(), '_');
        string letrasTentadas;

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
            cout << "Parabéns! Você adivinhou a palavra: " << palavraParaAdivinhar << endl;
            arquivoHistorico << "Palavra: " << palavraParaAdivinhar << " - Resultado: Acertou" << endl;
        }
        else
        {
            cout << "Você excedeu o número máximo de tentativas. A palavra era: " << palavraParaAdivinhar << endl;
            arquivoHistorico << "Palavra: " << palavraParaAdivinhar << " - Resultado: Errou" << endl;
        }

        arquivoHistorico.close(); // Fecha o arquivo de histórico

        delete[] palavras;

        // Pergunta ao usuário se deseja jogar novamente
        cout << "Deseja jogar novamente? (S/N): ";
        char escolha;
        cin >> escolha;

        if (toupper(escolha) != 'S')
        {
            cout << "Obrigado por jogar! Até a próxima." << endl;
            break; // Sai do loop se a escolha não for 'S'
        }

    } while (true);

    return 0;
}
