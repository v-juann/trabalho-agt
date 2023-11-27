/*
Universidade do Estado de Santa Catarina
Alunos: Nícolas Vinícius Lobo Morais, Vinicius Juann Pereira
Trabalho Final - Agenda de Contatos
O objetivo deste trabalho consiste em desenvolver um programa para manter as informações de uma agenda de contatos utilizando variáveis compostas. 
A estrutura do contato deve conter um código de identificação, nome, telefone e tipo do contato (pessoal ou trabalho).
O programa deve conter um menu inicial com 5 opções: 
i) incluir um novo contato; 
ii) excluir um contato existente; 
iii) alterar um contato existente; 
iv) listar todos os contatos cadastrados; e 
v) localizar um contato.
Na operação de inclusão de um novo contato, deve ser utilizado um identificador exclusivo para cada contato. 
Uma sugestão é incrementar uma unidade no último identificador válido de um contato. 
As opções de excluir, alterar e localizar um contato deve realizada a partir de um identificador do contato informado pelo usuário. 
A avaliação do trabalho deve levar em conta o atendimento a todos os requisitos funcionais, bem como a organização e uso de boas práticas de desenvolvimento no código.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Enumerador para o tipo de contato
typedef enum{
    pessoal = 1,
    trabalho = 2,
}Tipo;

// Declaração da variável global
Tipo tipo;

//Estrutura do contato
typedef struct{
    int codigo;
    char nome[15];
    int telefone;
    // Tipo tipo;
}Contato;

//Início do programa
int main(){

//Declaração de variáveis
    int opcao, ident, n = 0;
    Contato *contato;

//Estrutura de repetição que mantém o programa rodando até o usuário optar por sair
    do{
        printf("Selecione a opção: \n");
        printf("1 - Incluir novo contato:\n");
        printf("2 - Excluir um contato existente:\n");
        printf("3 - Alterar um contato existente::\n");
        printf("4 - Listar todos os contatos cadastrados:\n");
        printf("5 - Localizar um contato:\n");
        printf("Pressione qualquer outra tecla para encerrar o programa.\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                    contato = (void*) realloc(contato, sizeof(contato)*n);
                    /*printf("Digite o código do contato: \n");
                    scanf("%d", contato[n].codigo);*/

                    printf("Digite o nome do contato: \n");
                    scanf("%s", contato[n].nome);

                    printf("Digite o número de telefone do contato: \n");
                    scanf("%d", contato[n].telefone);

                    //printf("Selecione o tipo de número (pessoal ou trabalho): \n");
                    //scanf("%s", contato[n].tipo);
                n++;
            break;

            case 2:
                printf("Digite o código do contato que deseja excluir: \n");
                scanf("%d", &ident);

            break;

            case 3:
                printf("Digite o código do contato que deseja alterar: \n");
                scanf("%d", &ident);

            case 4:
                for (int x = 1; x < n; x++){
                    printf("Código: %d\n", contato[x].codigo);
                    printf("Código: %s\n", contato[x].nome);  
                    printf("Código: %d\n", contato[x].telefone);
                    //printf("Código: %s\n", contato[x].tipo);                   
                }
            break;

            case 5:
                printf("Digite o código do contato: \n");
                scanf("%d", &ident);
            break;

            default:
                return 0;
        }
    }while(main != 0);
}
