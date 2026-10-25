#include <stdio.h>
#include "aluno.h"

void limparEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // descarta o que sobrou no teclado
}

float calcularMedia(struct Aluno *aluno){
    float soma = 0;
    for(int i = 0; i < 3; i++){
        soma += aluno->notas[i];
    }
    return soma / 3;
}

void determinarSituacao(struct Aluno *aluno){
    if (aluno->media >= 7.0){
        snprintf(aluno->situacao, sizeof(aluno->situacao), "Aprovado");
    } else if (aluno->media >= 4.0){
        snprintf(aluno->situacao, sizeof(aluno->situacao), "Recuperação");
    } else {
        snprintf(aluno->situacao, sizeof(aluno->situacao), "Reprovado");
    }
}

int matriculaExiste(struct Aluno *turma, int qtd_alunos, int matricula){
    for (int i = 0; i < qtd_alunos; i++){
        if (turma[i].matricula == matricula){
            return 1; // matrícula já existe
        }
    }
    return 0; // matrícula não existe
}

int cadastrarAluno(struct Aluno *aluno, struct Aluno *turma, int qtd_alunos){
    int matricula;
    printf("\n--- Cadastro de Aluno ---\n");
    printf("Informe o nome do aluno: ");
    scanf(" %[^\n]", aluno->nome);

    printf("Informe a matrícula do aluno: ");
    scanf("%d", &matricula);
    if (matriculaExiste(turma, qtd_alunos, matricula)){
        printf("Matrícula %d já exsite! Cadastro cancelado.\n",matricula);
        return 0; // Cancelar cadastro se matrícula já existe
    }
    aluno->matricula = matricula;
    
    
    printf("Informe a idade do aluno: ");
    scanf("%d", &aluno->idade);

    printf("Informe as notas do aluno (3 notas):\n");
    for(int i = 0; i < 3; i++){
        printf("Nota %d: ", i+1);
        scanf("%f", &aluno->notas[i]);
    }
    limparEntrada(); // esvazia o teclado após as notas
    aluno->media = calcularMedia(aluno);
    determinarSituacao(aluno);
    printf("Aluno cadastrado com sucesso!\n");
    return 1; // Cadastro realizado com sucesso
}

void buscarAluno(struct Aluno *turma, int qtd_alunos){
    if (qtd_alunos == 0){
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("\n--- Busca de Aluno ---\n");
    int matricula;
    printf("Matrícula do aluno a ser buscado: ");
    if (scanf("%d", &matricula) != 1){
        limparEntrada();
        printf("Entrada inválida! Por favor, insira um número válido.\n");
        return;
    }
    for(int i = 0; i < qtd_alunos; i++){
        if(turma[i].matricula == matricula){
            printf("\nAluno encontrado:\n");
            printf("Nome: %s\n", turma[i].nome);
            printf("Matrícula: %d\n", turma[i].matricula);
            printf("Idade: %d\n", turma[i].idade);
            printf("Notas: %.2f, %.2f, %.2f\n", turma[i].notas[0], turma[i].notas[1], turma[i].notas[2]);
            printf("Média: %.2f\n", turma[i].media);
            printf("Situação: %s\n", turma[i].situacao);
            return;
        }
    }
    printf("Aluno com matrícula %d não encontrado.\n", matricula);
}

void listarAlunos(struct Aluno *turma, int qtd_alunos){
    printf("\n--- Listagem de Alunos ---\n");
    if (qtd_alunos == 0){
        printf("Nenhum aluno cadastrado.\n");
    }

    for(int i = 0; i < qtd_alunos; i++){
        printf("\nAluno %d: \n", i+1);
        printf("Nome: %s\n", turma[i].nome);
        printf("Matrícula: %d\n", turma[i].matricula);
        printf("Idade: %d\n", turma[i].idade);
        printf("Notas: %.2f, %.2f, %.2f\n", turma[i].notas[0], turma[i].notas[1], turma[i].notas[2]);
        printf("Média: %.2f\n", turma[i].media);
        printf("Situação: %s\n", turma[i].situacao);
    }
}

float maiorMedia(struct Aluno *turma, int qtd_alunos){
    if (qtd_alunos == 0) return 0.0;
    float maior = turma[0].media;
    for(int i = 1; i < qtd_alunos; i++){
        if(turma[i].media > maior){
            maior = turma[i].media;
        }
    }
    return maior;
}

float menorMedia(struct Aluno *turma, int qtd_alunos){
    if(qtd_alunos == 0) return 0.0;
    float menor = turma[0].media;
    for (int i = 1; i < qtd_alunos; i++){
        if(turma[i].media < menor){
            menor = turma[i].media;
        }
    }
    return menor;
}

float mediaTurma(struct Aluno *turma, int qtd_alunos){
    if (qtd_alunos == 0) return 0.0;
    float soma = 0;
    for(int i = 0; i < qtd_alunos; i++){
        soma += turma[i].media;
    }
    return soma / qtd_alunos;
}

void ordenarPorMedia(struct Aluno *turma, int qtd_alunos){
    for (int i = 0; i < qtd_alunos - 1; i++){
        for (int j = 0; j < qtd_alunos - 1 - i; j++){
            if (turma[j].media < turma[j+1].media){
                struct Aluno aux = turma[j];
                turma[j] = turma[j+1];
                turma[j+1] = aux;
            }
        }
    }
}