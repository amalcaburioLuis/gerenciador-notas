#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao = 0;

    do {
       printf("\n--- Menu de Opções ---\n");
       printf("1. Cadastrar Aluno\n");
       printf("2. Listar Alunos\n");
       printf("3. Buscar\n");
       printf("4. Estatísticas\n");
       printf("0. Sair\n");
       printf("\nEscolha uma opção: ");
       scanf("%d", &opcao);
       printf("----------------------\n");

       switch (opcao){
        case 1:
            printf("\nSelecionado - Cadastrar aluno\n");
            break;
        case 2:
            printf("\nSelecionado - Listar alunos\n");
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
