#include <stdio.h>
#include <locale.h>

#define MAX_ALUNOS 50

struct Aluno {
    char nome[50];
    int matricula;
    int idade;
    float notas[3];
    float media;
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
    printf("Aluno cadastrado com sucesso!\n");
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
    }
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
       if (scanf("%d", &opcao) != 1){ // se a leitura falhar, descarta a entrada e avisa
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
            break;
        case 4:
            printf("\nSelecionado - Estatísticas\n");
            break;
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