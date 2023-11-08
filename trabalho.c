/*O objetivo deste trabalho consiste em desenvolver um programa para manter as informações de uma agenda de contatos utilizando variáveis compostas. 
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
#include<string.h>

//Estrutura do contato
typedef struct{
    int codigo;
    char nome[15];
    int telefone;
    char tipo[8];
}Contato;

//Início do programa
int main(){

//Declaração de variáveis
    int opcao, n = 0;

//Estrutura de repetição que mantém o programa rodando até o usuário optar por sair
    do{
        printf("Selecione a opção: \n");
        printf("1 - Incluir novo contato:\n");
        printf("2 - Excluir um contato existente:\n");
        printf("3 - Alterar um contato existente::\n");
        printf("4 - Listar todos os contatos cadastrados:\n");
        printf("5 - Localizar um contato:\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                n++;
                    printf("Digite a placa do veículo: \n");
                    scanf("%s", veiculo[n].placa);

                    printf("Digite a categoria do veículo: \n");
                    scanf("%s", veiculo[n].tipo);

                    printf("Digite o modelo do veículo: \n");
                    scanf("%s", veiculo[n].modelo);

                    printf("Digite o ano do veículo: \n");
                    scanf("%d", &veiculo[n].ano);
            break;
            case 2:
                for (int n = 0; n < 3; n++){
                    printf("Veículo %d :\n", n + 1);
                    printf("Modelo: %s\n", veiculo[n].modelo);
                    printf("Ano: %d\n", veiculo[n].ano);                
                    printf("Categoria: %s\n", veiculo[n].tipo);
                    printf("Placa: %s\n", veiculo[n].placa);                
                }
            break;
            case 3:
                return 0;
            default:
                printf("Opção inválida!\n");
            break;
        }
    }while(main != 0);
}