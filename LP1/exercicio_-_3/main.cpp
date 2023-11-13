#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// Função para calcular o IMC
double calcularIMC(double peso, double altura) {
    return peso / (altura * altura);
}

int main() {
    ifstream arquivoEntrada("entrada.txt");
    ofstream arquivoSaida("saida.txt");

    if (!arquivoEntrada.is_open()) {
        cerr << "Erro ao abrir o arquivo de entrada." << endl;
        return 1;
    }

    if (!arquivoSaida.is_open()) {
        cerr << "Erro ao criar o arquivo de saída." << endl;
        return 1;
    }

    string nome, matricula;
    double peso, altura;

    while (arquivoEntrada >> nome >> matricula >> peso >> altura) {
        // Calcular o IMC
        double imc = calcularIMC(peso, altura);

        // Escrever no arquivo de saída
        arquivoSaida << nome << " " << matricula << " " << fixed << setprecision(2) << peso << " " << altura << " " << imc << endl;
    }

    cout << "Processamento concluído. Verifique o arquivo 'saida.txt'." << endl;

    // Fechar os arquivos
    arquivoEntrada.close();
    arquivoSaida.close();

    return 0;
}
