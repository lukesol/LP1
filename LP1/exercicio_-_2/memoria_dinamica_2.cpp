#include <iostream>
#include <ctime>
#include <cstdlib>

bool verificaMatrizIdentidade(int** matriz, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i == j && matriz[i][j] != 1) {
                return false;
            } else if (i != j && matriz[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int tamanhoMatriz;

    // Solicita ao usuário um número inteiro
    std::cout << "Informe o tamanho da matriz quadrada: ";
    std::cin >> tamanhoMatriz;

    // Aloca dinamicamente a matriz
    int** matriz = new int*[tamanhoMatriz];
    for (int i = 0; i < tamanhoMatriz; i++) {
        matriz[i] = new int[tamanhoMatriz];
    }

    // Preenche a matriz com valores aleatórios entre 0 e 1
    srand(time(0)); // Inicializa a semente para números aleatórios com base no tempo atual
    for (int i = 0; i < tamanhoMatriz; i++) {
        for (int j = 0; j < tamanhoMatriz; j++) {
            matriz[i][j] = rand() % 2; // Gera 0 ou 1 aleatoriamente
        }
    }

    // Verifica se a matriz é uma matriz identidade
    if (verificaMatrizIdentidade(matriz, tamanhoMatriz)) {
        std::cout << "A matriz é uma matriz identidade (1)." << std::endl;
    } else {
        std::cout << "A matriz não é uma matriz identidade (0)." << std::endl;
    }

    // Libera a memória alocada para a matriz
    for (int i = 0; i < tamanhoMatriz; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
