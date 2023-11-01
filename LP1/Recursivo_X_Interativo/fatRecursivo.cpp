#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

// Função para calcular o fatorial de forma recursiva
 int fatorialRecursivo( int n) {
    if (n <= 1) {
        return 1;
    }
    return n * fatorialRecursivo(n - 1);
}

int main() {

    
    int fatorialRec;
    double tempoRecursivo;

    for(int j = 5; j<= 10000; j++){
        double mediaTempo = 0;
        duration<double> duracao;
        for(int i = 1; i <= 1000; i++){
            auto start = high_resolution_clock::now();
            fatorialRec = fatorialRecursivo(j);
            auto end = high_resolution_clock::now();

            duracao = end - start;

            mediaTempo+=duracao.count();
        }
        cout << j << " " << mediaTempo /1000.0 << endl;
    }

    return 0;
}
