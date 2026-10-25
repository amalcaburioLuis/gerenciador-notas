# Gerenciador de Notas da Turma

Programa de console em C para cadastrar alunos e acompanhar as notas de uma turma. Desenvolvido como projeto de estudo na disciplina Técnicas de Programação II (Sistemas de Informação, UFRA).

## O que o programa faz

- **Cadastrar aluno**: nome, matrícula, idade e 3 notas. Não permite matrículas repetidas.
- **Listar alunos**: mostra todos os dados, ordenados pela média, da maior para a menor.
- **Buscar**: encontra um aluno pela matrícula.
- **Estatísticas**: média da turma, maior média e menor média.

A média é a média aritmética das 3 notas. A situação é definida assim:

| Média | Situação |
|---|---|
| 7,0 ou mais | Aprovado |
| de 4,0 até menos de 7,0 | Recuperação |
| menos de 4,0 | Reprovado |

A turma comporta até 30 alunos.

## Estrutura do projeto

| Arquivo | Conteúdo |
|---|---|
| `main.c` | Função principal, menu e submenu de estatísticas |
| `aluno.h` | Definição da `struct Aluno` e protótipos das funções |
| `aluno.c` | Implementação das funções (cadastro, busca, listagem, ordenação e estatísticas) |

## Como compilar

É necessário ter o compilador GCC instalado. Na pasta do projeto, execute:

```
gcc main.c aluno.c -o gerenciador
```

## Como executar

```
./gerenciador
```

No Windows, se estiver usando o PowerShell ou o Prompt de Comando, use `gerenciador.exe`.

## Exemplo de uso

1. Escolha a opção `1` e cadastre alguns alunos.
2. Escolha a opção `2` para ver a listagem ordenada por média.
3. Escolha a opção `3` para buscar um aluno pela matrícula.
4. Escolha a opção `4` para ver as estatísticas da turma.
5. Escolha a opção `0` para sair.

## Autor

Luís Amalcaburio - Sistemas de Informação - Ufra

## Autor

Luís
