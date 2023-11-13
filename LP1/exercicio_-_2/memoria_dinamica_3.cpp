#include <iostream>

void preencherVetor(int*& vetor, int& tamanho, int& capacidade) {
    if (tamanho >= capacidade) {
        std::cout << "O vetor atingiu sua capacidade máxima. Deseja aumentar o tamanho? (S/N): ";
        char resposta;
        std::cin >> resposta;

        if (resposta == 'S' || resposta == 's') {
            int novaCapacidade = capacidade * 2;
            int* novoVetor = new int[novaCapacidade];

            for (int i = 0; i < tamanho; i++) {
                novoVetor[i] = vetor[i];
            }

            delete[] vetor;
            vetor = novoVetor;
            capacidade = novaCapacidade;
        } else {
            std::cout << "Tamanho do vetor não será aumentado. O vetor atual será mantido." << std::endl;
            return;
        }
    }

    std::cout << "Digite um valor para o vetor: ";
    int valor;
    std::cin >> valor;

    vetor[tamanho] = valor;
    tamanho++;

    preencherVetor(vetor, tamanho, capacidade);
}

int main() {
    int capacidade = 10;
    int tamanho = 0;
    int* vetor = new int[capacidade];

    preencherVetor(vetor, tamanho, capacidade);

    std::cout << "Vetor final:" << std::endl;
    for (int i = 0; i < tamanho; i++) {
        std::cout << vetor[i] << " ";
    }
    std::cout << std::endl;

    delete[] vetor;

    return 0;
}
