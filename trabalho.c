/* Universidade do Estado de Santa Catarina
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

//Cabeçalho
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

//Estrutura do contato
typedef struct{
    int codigo;
    char nome[15];
    char telefone[12];
    char tipo[15];
}Contato;

//Início do programa
int main(){

//Declaração de variáveis
    int opcao, ident, n = 0;
    //Atribui um endereço não nulo ao ponteiro
    Contato *contato = (Contato *) calloc(1, sizeof(Contato));
    
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
            //Inclusão de novo contato                    
                    contato = realloc (contato, (sizeof(Contato)*(n+1)));
                    (contato+n)->codigo = n+1;

                    printf("Digite o nome do contato que será salvo com o código %d: \n",contato[n].codigo);
                    scanf("%s", contato[n].nome);

                    printf("Digite o número de telefone do contato que será salvo com o código %d: \n",contato[n].codigo);
                    scanf("%s", contato[n].telefone);

                    printf("Digite o tipo de telefone (pessoal ou trabalho): \n");
                    scanf("%s", contato[n].tipo);
                
                    n++;

                    printf("Contato adicionado com sucesso.\n");
            break;

            case 2:
                // Verifica se tem contatos cadastrados
                if (n > 0) {
                    printf("Contatos existentes:\n");
                    for (int i = 0; i < n; i++) {
                        printf("Código: %d\n", contato[i].codigo);
                    }

                    int excluircod; // Excluir código
                    printf("Digite o código do contato que você quer excluir: \n");
                    scanf("%d", &excluircod);

                    int excluirposi = -1; // Excluir a posição no vetor
                    for (int i = 0; i < n; i++) {
                        if (contato[i].codigo == excluircod) {
                            excluirposi = i;
                            break;
                        }
                    }

                    if (excluirposi != -1) {
                        for (int i = excluirposi; i < n - 1; i++) {
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
                printf("Digite o código do contato que você quer alterar: \n");
                scanf("%d", &ident);

                if(ident > 0 && ident <= n){                    
                    printf("Digite o novo valor para o o nome do contato %d (%s): \n",contato[ident-1].codigo, contato[ident-1].nome);
                    scanf("%s", contato[ident].nome);
                    printf("Digite o novo valor para o telefone do contato %d (%s): \n",contato[ident-1].codigo, contato[ident-1].telefone);
                    scanf("%s", contato[ident].telefone);
                    printf("Contato alterado com sucesso.\n");
                }
                else{
                    printf("Contato inválido!\n");
                }
            break;
            
            case 4:
            //Lista todos os contatos cadastrados
                for(int w = 0; w < n; w++){
                    printf("\n-- Contato %d --\n", w+1);
                    printf("Código: %d \n", contato[w].codigo);
                    printf("Nome: %s \n", contato[w].nome);
                    printf("Telefone: %s \n", contato[w].telefone);
                    printf("Tipo: %s \n", contato[w].tipo);
                    printf("-----------------\n");

                }
            break;

            case 5:
            //Localizar um contato
                printf("Digite o código do contato que você quer localizar: \n");
                scanf("%d", &ident);

                if(ident > 0 && ident <= n){
                    printf("\n-- Contato %d --\n", ident);
                    printf("Código: %d \n", contato[ident-1].codigo);
                    printf("Nome: %s \n", contato[ident-1].nome);
                    printf("Telefone: %s \n", contato[ident-1].telefone);
                }
                else{
                    printf("Contato inválido!\n");
                }
            break;

            //Opção padrão para encerrar o programa quando o usuário apertar uma tecla que não seja de 1 a 5
            default:
                return 0;
        }
    }while (opcao!=0);

    free(contato);

    return 0;
}
