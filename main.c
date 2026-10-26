#include <stdio.h>
#include <locale.h>
#include "aluno.h"

int main(){
    setlocale(LC_ALL, "Portuguese");

    struct Aluno turma[MAX_ALUNOS];
    int qtd_alunos = carregarTurma(turma);
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
                if (cadastrarAluno(&turma[qtd_alunos], turma, qtd_alunos)){
                    qtd_alunos++;
                }
            } else {
                printf("Limite de alunos atingido!\n");
            }
            break;
        case 2:
            printf("\nSelecionado - Listar alunos\n");
            ordenarPorMedia(turma, qtd_alunos);
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
            salvarTurma(turma, qtd_alunos);
            printf("Dados salvos. Até logo!\n");
            printf("\nSaindo do programa...\n");
            break;
        default:
            printf("\nOpção Inválida! Por favor, escolha uma opção válida.\n");
       }
       printf("\n----------------------\n");

    } while (opcao != 0);
    return 0;
}