#include <string.h>
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

void salvarTurma(struct Aluno turma[], int qtd_alunos) {
    FILE *arq = fopen("dadosTurma.txt", "w"); // cria o arquivo de dados da turma.

    if (arq == NULL){
        printf("Erro ao salvar os dados.\n");
        return;
    }

    // Percorre os alunos, do índice 0 até qtd_alunos - 1.
    for (int i = 0; i < qtd_alunos; i++){
        fprintf(arq, "%s; %d; %d; %.2f; %.2f; %.2f\n",
            turma[i].nome,
            turma[i].matricula,
            turma[i].idade,
            turma[i].notas[0],
            turma[i].notas[1],
            turma[i].notas[2]);
    }

    // Fecha o arquivo e garante que tudo foi gravado.
    fclose(arq);
}

int carregarTurma(struct Aluno turma[]){
    // Abre o arquivo para leitura
    FILE *arq = fopen("dadosTurma.txt", "r");

    
    if (arq == NULL){
        return 0;
    }

    int qtd = 0; // quantos alunos já foram lidos

    // fscanf devolve quantos campos leu. 6 = linha completa.
    while (qtd < MAX_ALUNOS &&
        fscanf(arq, " %49[^;]; %d; %d; %f; %f; %f",
            turma[qtd].nome,          // vetor: sem &
            &turma[qtd].matricula,
            &turma[qtd].idade,
            &turma[qtd].notas[0],
            &turma[qtd].notas[1],
            &turma[qtd].notas[2]) == 6) {

        // As funções recebem o endereço do aluno, então usamos &
        turma[qtd].media = calcularMedia(&turma[qtd]);

        // determinarSituacao não devolve valor: ela grava em turma[qtd].situacao.
        // Precisa vir depois do cálculo da média, porque ela lê aluno->media.
        determinarSituacao(&turma[qtd]);

        qtd++; // próxima posição do vetor
    }

    fclose(arq);
    return qtd; // total de alunos lidos
}