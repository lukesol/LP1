#include <iostream>

int main(int argc, char* argv[]){
    int size;
    
    std::cout << "Insira o tamanho do vetor para ser alocado na memória: \n";

    std::cin >> size;

    int* vetor = new int[size];

    for(size_t i = 0; i < size; i++)
        std::cin >> vetor[i];

    for(size_t i = 0; i < size; i++)
        std::cout << ">>> " << vetor[i] << std::endl;

    delete [] vetor;
    
    return 0;
}