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

//Estrutura do contato
typedef struct{
    int codigo;
    char nome[50];
    int telefone;
    char tipo[15];
}Contato;

//Início do programa
int main(){

//Declaração de variáveis
    int opcao, n = 0;
    Contato *contato = NULL;

//Estrutura de repetição que mantém o programa rodando até o usuário optar por sair
    do{
        printf("Selecione a opção: \n");
        printf("1 - Incluir novo contato:\n");
        printf("2 - Excluir um contato existente:\n");
        printf("3 - Alterar um contato existente:\n");
        printf("4 - Listar todos os contatos cadastrados:\n");
        printf("5 - Localizar um contato:\n");
        printf("Pressione qualquer outra tecla para encerrar o programa.\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                    contato = (Contato *)realloc(contato, n* sizeof(Contato));
                    printf("Digite o código do contato: \n");
                    scanf("%d", contato[n].codigo);

                    printf("Digite o nome do contato: \n");
                    scanf("%s", contato[n].nome);

                    printf("Digite o número de telefone do contato: \n");
                    scanf("%d", contato[n].telefone);

                    printf("Selecione o tipo de número (pessoal ou trabalho): \n");
                    scanf("%s", contato[n].tipo);
                n++;
            break;
            case 2:
                if (n > 0) {
                    printf("Contatos existentes:\n");
                    for (int i = 0; i < n; i++) {
                        printf("Código: %d\n", contato[i].codigo);
                    }

                    int excluir2;
                    printf("Digite o código do contato que você quer excluir: \n");
                    scanf("%d", &excluir2);

                    int excluir = -1;
                    for (int i = 0; i < n; i++) {
                        if (contato[i].codigo == excluir) {
                            excluir = i;
                            break;
                        }
                    }

                    if (excluir != -1) {
                        for (int i = excluir; i < n - 1; i++) {
                            contato[i] = contato[i + 1];
                        }

                        n--;

                        printf("Contato excluído com sucesso.\n");
                    } else {
                        printf("Código do contato não encontrado.\n");
                    }
                } else {
                    printf("Nenhum contato cadastrado para excluir.\n");
                }
                break;
            case 3:
                //Alterar um contato existente
            case 4:
                // Listar todos os contatos cadastrados
            break;
            case 5:
                //Localizar um contato
            break;
            default:
                printf("Opção inválida. Por favor, insira um número entre 1 e 5.\n");
            break;
        }
    }while (opcao >= 1 && opcao <= 5);;
}
