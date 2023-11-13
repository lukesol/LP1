#include <iostream>
#include <string>

struct Aluno { std::string nome; float *notas; float media; std::string situacao; };

int main() {
    Aluno aluno;
    aluno.notas = new float[3];

    std::cout << "Nome do aluno: ";
    std::cin >> aluno.nome;

    for (int i = 0; i < 3; i++) {
        std::cout << "Digite a nota " << i + 1 << ": ";
        std::cin >> aluno.notas[i];
    }
    aluno.media = (aluno.notas[0] + aluno.notas[1] + aluno.notas[2]) / 3.0;

    if (aluno.media >= 7.0) {
        aluno.situacao = "Aprovado";
    } else if (aluno.media >= 4.0) {
        aluno.situacao = "Reposição";

        // Em caso de reposição, lê a nota de reposição
        float notaReposicao;
        std::cout << "Digite a nota de reposição: ";
        std::cin >> notaReposicao;

        // Alocando memória dinamicamente para um novo vetor com 4 posições
        float *novasNotas = new float[4];

        // Copiando as três notas originais para o novo vetor
        for (int i = 0; i < 3; i++) {
            novasNotas[i] = aluno.notas[i];
        }

        // Inserindo a nota de reposição no novo vetor
        novasNotas[3] = notaReposicao;

        // Calculando a média das novas notas
        aluno.media = (novasNotas[0] + novasNotas[1] + novasNotas[2] + novasNotas[3]) / 4.0;

        delete[] aluno.notas;  // Liberando a memória do vetor de notas original
        aluno.notas = novasNotas;  // Atualizando o ponteiro para o novo vetor de notas
    } else {
        aluno.situacao = "Reprovado";
    }

    // Exibindo os resultados
    std::cout << "Nome do aluno: " << aluno.nome << std::endl;
    std::cout << "Média das notas: " << aluno.media << std::endl;
    std::cout << "Situação: " << aluno.situacao << std::endl;

    // Liberando a memória alocada dinamicamente
    delete[] aluno.notas;

    return 0;
}
