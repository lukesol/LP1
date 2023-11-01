#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

/// @brief Preenche o vetor com valores aleatórios.
/// @param vetor 
/// @param size 
void preencherVetores(int* vetor,  int size){
    for (int i{0}; i < size; i++){
        vetor[i] = rand()%(2*size);
    }
}

// void ordenarVetores(vector<int>& vetor,  int size){
// //Ordenando valores do vetor
//     for (int i{0}; i < size; i++){
//         for (int j{0}; j < size; j++){
//             if(vetor[i] < vetor[j]){
//                 int aux = 0;
//                 aux = vetor[i];
//                 vetor[i] = vetor[j];
//                 vetor[j] = aux;
//             }
//         }
//     }
// }

/// @brief Realiza a busca do numero_X no vetor utilizando dois índices, um que caminha para esquerda e outro para direta até o tamanho inicial e máximo do vetor respectivamente.
/// @param vetor 
/// @param inicio_index 
/// @param index_esquerda 
/// @param meio 
/// @param index_direita 
/// @param fim_index 
/// @param numero_X 
/// @return O índice onde se encontra o numero_x dentro do vetor, caso não esteja presente retorna -1.
int busca_binaria_recursiva(int* vetor, const int inicio_index, int index_esquerda, const int meio , int index_direita, const int fim_index, int numero_X){
    
    if(index_esquerda == meio - 1)
        if(vetor[meio] == numero_X)
            return meio;

    if(index_esquerda == inicio_index and index_direita == fim_index)
        if(vetor[index_esquerda] != numero_X and vetor[index_direita] != numero_X)
            return -1;

    if(index_esquerda != inicio_index)
        index_esquerda--;

    if(index_direita != fim_index)
        index_direita++;

    if (vetor[index_esquerda] == numero_X)
        return index_esquerda;
    else if(vetor[index_direita] == numero_X)
        return index_direita;
    
    // return NULL;
    return busca_binaria_recursiva(vetor, inicio_index, index_esquerda, meio, index_direita, fim_index, numero_X);
}    

/// @brief Cria vetores de tamanho increment até n com valores aleatórios, variando de increment em increment.
/// @param n 
/// @param increment 
void gerarVetores_RealizarBusca(int n,  int increment){

    for (int i{increment}; i <= n; i+=increment){
        srand(0);
        int* vetor = new int[i];
        
        double media_tempo = 0;
        duration<double> duracao;
        int meio = (0+(i-1))/2;

        preencherVetores(vetor, i);
        // ordenarVetores(vetor, i);

        for (int j = 0; j < 1000; j++){
            int numero_X = rand()%(2*i);

            auto start = high_resolution_clock::now();
            
            int index_numero_X = busca_binaria_recursiva(vetor, 0, meio-1, meio, meio+1 , i-1, numero_X);
            
            auto end = high_resolution_clock::now();

            duracao = end - start;

            media_tempo+=duracao.count();

            // cout << ">>> Numero X: " << numero_X << endl
            //      << ">>> Numero encontrado: " << vetor[index_numero_X] << endl
            //      << ">>> Index encontrado: " << index_numero_X << endl;
        }

        cout << i << " " << media_tempo/1000.0 << endl;

        delete [] vetor;
    }
}

int main(){
    
    gerarVetores_RealizarBusca(5000, 10);

    return 0;
}