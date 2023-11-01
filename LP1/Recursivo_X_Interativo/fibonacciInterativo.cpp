#include <iostream>
#include <ctime>

using namespace std;

// Função para calcular o n-ésimo termo da sequência de Fibonacci de forma iterativa
int fibonacciIterativo(int n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    int a = 0, b = 1, resultado = 0;
    for (int i = 2; i <= n; ++i) {
        resultado = a + b;
        a = b;
        b = resultado;
    }
    return resultado;
}


int main(){

    clock_t tempo_inicial;
    clock_t tempo_final;
    int fibonacciIter;
    double tempoIterativo;

    for (int j = 1; j <= 40; j++) {
        double mediaTempo = 0;
        tempo_inicial = clock();
        
        for(int i = 1; i <= 100; i++){
            fibonacciIter = fibonacciIterativo(j);
            tempo_final = clock();
            tempoIterativo = (double)(tempo_final - tempo_inicial)/CLOCKS_PER_SEC;
            mediaTempo+=tempoIterativo;
        }
        mediaTempo /= (double)100;
        cout << mediaTempo << endl;
    }

    return 0;
}