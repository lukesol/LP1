#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

/// @brief Preenche o vetor com valores aleattórios.
/// @param vetor 
/// @param size 
void preencherVetores(vector<int>& vetor,  int size){
    for (int i{0}; i < size; i++){
        vetor[i] = rand()%(2*size);
    }
}

void ordenarVetores(vector<int>& vetor,  int size){
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

int busca_binaria_recursiva(vector<int>& vetor, int inicio_index,  int fim_index, int numero_X){
    
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
        vector<int> vetor(i);
        
        double media_tempo = 0;
        duration<double> duracao;

        preencherVetores(vetor, i);
        ordenarVetores(vetor, i);

        for (int j = 0; j < 100000; j++){
            int numero_X = rand()%(2*i);

            auto start = high_resolution_clock::now();

            int index_numero_X = busca_binaria_recursiva(vetor, 0, vetor.size()-1, numero_X);
            
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