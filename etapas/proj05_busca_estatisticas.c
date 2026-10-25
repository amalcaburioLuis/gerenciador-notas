#include <stdio.h>
#include <locale.h>

#define MAX_ALUNOS  // Vetor de alunos com tamanho máximo definido

struct Aluno {
    char nome[50];
    int matricula;
    int idade;
    float notas[3];
    float media;
    char situacao[20]; // situação do aluno: Aprovado, Recuperação ou Reprovado
};

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

void cadastrarAluno(struct Aluno *aluno){
    printf("\n--- Cadastro de Aluno ---\n");
    printf("Informe o nome do aluno: ");
    scanf(" %[^\n]", aluno->nome);
    printf("Informe a matrícula do aluno: ");
    scanf("%d", &aluno->matricula);
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

int main(){
    setlocale(LC_ALL, "Portuguese");

    struct Aluno turma[MAX_ALUNOS];
    int qtd_alunos = 0;
    int opcao = 0;

    do {
       printf("\n--- Menu de Opções ---\n");
       printf("1. Cadastrar Aluno\n");
       printf("2. Listar Alunos\n");
       printf("3. Buscar\n");
       printf("4. Estatísticas\n");
       printf("0. Sair\n");
       printf("\nEscolha uma opção: ");
       if (scanf("%d", &opcao) != 1){
            limparEntrada();
            opcao = -1;
       }
       printf("----------------------\n");

       switch (opcao){
        case 1:
            printf("\nSelecionado - Cadastrar aluno\n");
            if (qtd_alunos < MAX_ALUNOS){
                cadastrarAluno(&turma[qtd_alunos]);
                qtd_alunos++;
            } else {
                printf("Limite de alunos atingido!\n");
            }
            break;
        case 2:
            printf("\nSelecionado - Listar alunos\n");
            listarAlunos(turma, qtd_alunos);
            break;
        case 3:
            printf("\nSelecionado - Buscar\n");
            buscarAluno(turma, qtd_alunos);
            break;
        case 4: {
            int estatistica_opcao = 0;
            printf("\nSelecionado - Estatísticas\n");
            printf("Qual opção deseja visualizar?\n");
            printf("1. Média da turma\n");
            printf("2. Maior média\n");
            printf("3. Menor média\n");
            printf("Escolha uma opção: ");
            if (scanf("%d", &estatistica_opcao) != 1){
                limparEntrada();
                estatistica_opcao = -1;
            }

            switch(estatistica_opcao){
                case 1:
                    printf("A média da turma é: %.2f\n", mediaTurma(turma, qtd_alunos));
                    break;
                case 2:
                    printf("A maior média da turma é: %.2f\n", maiorMedia(turma, qtd_alunos));
                    break;
                case 3:
                    printf("A menor média da turma é: %.2f\n", menorMedia(turma, qtd_alunos));
                    break;
                default:
                    printf("Opção inválida para estatísticas!\n");
            }
            break;
        }
        case 0:
            printf("\nSaindo do programa...\n");
            break;
        default:
            printf("\nOpção Inválida! Por favor, escolha uma opção válida.\n");
       }
       printf("\n----------------------\n");

    } while (opcao != 0);
    return 0;
}