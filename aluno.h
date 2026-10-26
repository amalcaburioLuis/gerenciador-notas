#ifndef ALUNO_H
#define ALUNO_H

#define MAX_ALUNOS 30 // Vetor de alunos com tamanho máximo definido

struct Aluno {
    char nome[50];
    int matricula;
    int idade;
    float notas[3];
    float media;
    char situacao[20]; // situação do aluno: Aprovado, Recuperação ou Reprovado
};

void limparEntrada();
float calcularMedia(struct Aluno *aluno);
void determinarSituacao(struct Aluno *aluno);
int matriculaExiste(struct Aluno *turma, int qtd_alunos, int matricula);
int cadastrarAluno(struct Aluno *aluno, struct Aluno *turma, int qtd_alunos);
void buscarAluno(struct Aluno *turma, int qtd_alunos);
void listarAlunos(struct Aluno *turma, int qtd_alunos);
void ordenarPorMedia(struct Aluno *turma, int qtd_alunos);
float maiorMedia(struct Aluno *turma, int qtd_alunos);
float menorMedia(struct Aluno *turma, int qtd_alunos);
float mediaTurma(struct Aluno *turma, int qtd_alunos);
void salvarTurma(struct Aluno turma[], int qtd_alunos);
int carregarTurma(struct Aluno turma[]);
#endif