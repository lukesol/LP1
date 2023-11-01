#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace chrono;

/// @brief Preenche o vetor com valores aleattórios.
/// @param vetor 
/// @param size 
void preencherVetores(int* vetor,  int size){
    for (int i{0}; i < size; i++){
        vetor[i] = rand()%(2*size);
    }
}

// void ordenarVetores(int* vetor,  int size){
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


/// @brief Realiza a busca binaria recursiva padrão.
/// @param vetor 
/// @param inicio_index 
/// @param fim_index 
/// @param numero_X 
/// @return Retorna o índice dentro do vetor com o valor de numero_X, caso não encontre retonra -1.
int busca_binaria_recursiva(int* vetor, int inicio_index,  int fim_index, int numero_X){
    
    int i = (inicio_index + fim_index) / 2;

    if (inicio_index > fim_index){
        return -1;
    }

    if (vetor[i] == numero_X){
        return i;
    }

    if (vetor[i] < numero_X){
        return busca_binaria_recursiva(vetor, i + 1, fim_index, numero_X);
    }else{
        return busca_binaria_recursiva(vetor, inicio_index, i - 1, numero_X);
    }
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
        int n = sizeof(vetor) / sizeof(int);

        preencherVetores(vetor, i);

        auto start = high_resolution_clock::now(); // obtendo tempo inicial antes da ordenação do vetor.
        sort(vetor, vetor + n); // Ordenando vetor com função sort do #include <algorithm>.
        // ordenarVetores(vetor, i);

        for (int j = 0; j < 1000; j++){
            int numero_X = rand()%(2*i);

            int index_numero_X = busca_binaria_recursiva(vetor, 0, i-1, numero_X);
            
            auto end = high_resolution_clock::now();

            duracao = end - start;

            media_tempo+=duracao.count();

        }

        cout << i << " " << media_tempo/1000.0 << endl;

        delete [] vetor;
    }
}

int main(){
    
    gerarVetores_RealizarBusca(5000, 10);

    return 0;
}