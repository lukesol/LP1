#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

/// @brief Preenche o vetor com valores aleattórios.
/// @param vetor 
/// @param size 
void preencherVetores(vector<unsigned int> vetor, unsigned int size){
    for (int i{0}; i < size; i++){
        vetor[i] = rand()%(2*size);
    }
}

void ordenarVetores(vector<unsigned int> vetor, unsigned int size){
//Ordenando valores do vetor
    for (int i{0}; i < size; i++){
        for (int j{0}; j < size; j++){
            if(vetor[i] < vetor[j]){
                int aux = 0;
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

int busca_linear_interativa(vector<unsigned int> vetor, unsigned int size,  int numero_X) {
     int i;
     for (i = 0; i < size; i++) {
         if (vetor[i] == numero_X) {
             return i;
         }
     }

     return -1;
 }

/// @brief Cria vetores de tamanho increment até n com valores aleatórios, variando de increment em increment.
/// @param n 
/// @param increment 
void gerarVetores_RealizarBusca(unsigned int n, unsigned int increment){

    for (unsigned int i{increment}; i <= n; i+=increment){
        srand(0);
        vector<unsigned int> vetor(i);

        preencherVetores(vetor, i);
        ordenarVetores(vetor, i);

        duration<double> duracao;
        double media_tempo = 0;

        for (int j = 0; j < 100000; j++){
            int numero_X = rand()%(2*i);
            
            auto start = high_resolution_clock::now();

            int index_numero_X = busca_linear_interativa(vetor, vetor.size()-1, numero_X);
            
            auto end = high_resolution_clock::now();

            duracao = end - start;
            
            media_tempo+=duracao.count();
        }
            cout << i << " " << media_tempo/100000.0 << endl;
        

    }
}

int main(){
    
    gerarVetores_RealizarBusca(10000, 10);

    return 0;
}