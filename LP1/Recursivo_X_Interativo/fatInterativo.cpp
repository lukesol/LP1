#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

// Função para calcular o fatorial de forma iterativa
 int fatorialIterativo(int n) {
     int resultado = 1;
    for ( int i = 1; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    
    clock_t tempo_inicial;
    clock_t tempo_final;
    int fatorialIter;
    double tempoIterativo;

    for(int j = 5; j<= 1000; j++){
        double mediaTempo = 0;
        tempo_inicial = clock();

        for(int i = 1; i <= 100; i++){
            fatorialIter = fatorialIterativo(j);
            tempo_final = clock();
            tempoIterativo = (double)(tempo_final-tempo_inicial)/CLOCKS_PER_SEC;
            mediaTempo+=tempoIterativo;
        }
        mediaTempo /= (double)100;
        cout << mediaTempo << endl;
    }

    return 0;
}