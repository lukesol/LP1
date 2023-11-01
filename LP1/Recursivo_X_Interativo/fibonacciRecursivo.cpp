#include <iostream>
#include <ctime>

using namespace std;

// Função para calcular o n-ésimo termo da sequência de Fibonacci de forma recursiva
int fibonacciRecursivo(int n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

int main(){

    clock_t tempo_inicial;
    clock_t tempo_final;
    int fibonacciRec;
    double tempoRecursivo;

    for (int j = 1; j <= 40; j++) {
        double mediaTempo = 0;
        tempo_inicial = clock();

        for(int i = 1; i <= 100; i++){
            fibonacciRec = fibonacciRecursivo(j);
            tempo_final = clock();
            tempoRecursivo = (double)(tempo_final-tempo_inicial)/CLOCKS_PER_SEC;
            mediaTempo+=tempoRecursivo;
        }
        mediaTempo /= (double)100;
        cout << mediaTempo << endl;

    }

    return 0;
}