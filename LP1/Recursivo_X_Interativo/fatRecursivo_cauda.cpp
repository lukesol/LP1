#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

// Função para calcular o fatorial de forma recursiva em cauda
 int fatorialRecursivoCauda( int n, int resultado) {
     if (n <= 1) {
        return resultado;
    } else {
        return fatorialRecursivoCauda(n - 1, n * resultado);
    }
}

int main() {

    
    int fatorialRec;
    double tempoRecursivo;

    for(int j = 5; j<= 10000; j++){
        double mediaTempo = 0;
        duration<double> duracao;
        for(int i = 1; i <= 1000; i++){
            auto start = high_resolution_clock::now();
            fatorialRec = fatorialRecursivoCauda(j,1);
            auto end = high_resolution_clock::now();

            duracao = end - start;

            mediaTempo+=duracao.count();
        }
        cout << j << " " << mediaTempo /1000.0 << endl;
    }

    return 0;
}
