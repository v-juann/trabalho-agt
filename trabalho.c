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

//Declaração de funções
void listagem();
void localizador();
void alteracao();
void exclusao();
void inclusao();

//Cabeçalho
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

//Enumerador que define o tipo de contato
typedef enum{
    Pessoal,
    Trabalho
}Tipo;

//Estrutura do contato
typedef struct{
    int codigo;
    char nome[15];
    char telefone[12];
    Tipo tipo;
}Contato;

//Declaração de variáveis
    int opcao, ident, n = 0;
    Contato *contato;

//Início do programa
int main(){

//Atribui um endereço não nulo ao ponteiro
    contato = (Contato *) calloc(1, sizeof(Contato));
    
//Estrutura de repetição que mantém o programa rodando até o usuário optar por sair
    do{
        printf("\nSelecione a opção: \n");
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
                inclusao();

            break;

            case 2:
            //Exclusão de contato existente
                if (n > 0) {
                    printf("Contatos existentes:\n");
                    for (int i = 0; i < n; i++) {
                        printf("Código: %d\n", contato[i].codigo);
                    }                   
                    printf("Digite o código do contato que você quer excluir: \n");
                    scanf("%d", &ident);
                    
                    exclusao(ident);
                    
                }else {
                    printf("Não existem contatos cadastrados.");
                }
                break;

            case 3:
            //Alterar um contato existente
                printf("Digite o código do contato que você quer alterar: \n");
                scanf("%d", &ident);

                alteracao(ident);

            break;
            
            case 4:
            //Lista todos os contatos cadastrados
                listagem();
                
            break;

            case 5:
            //Localizar um contato
                printf("Digite o código do contato que você quer localizar: \n");
                scanf("%d", &ident);

                localizador(ident);
                
            break;

            //Opção padrão para encerrar o programa quando o usuário apertar uma tecla que não seja de 1 a 5
            default:
                return 0;
        }
    }while(main!=0);
}

//Funções
void listagem(){
    for(int w = 0; w < n; w++){
        printf("\n-- Contato %d --\n", w+1);
        printf("Código: %d \n", contato[w].codigo);
        printf("Nome: %s \n", contato[w].nome);
        printf("Telefone: %s \n", contato[w].telefone);
    }
}

void localizador(){
    if(ident > 0 && ident <= n){
        printf("\n-- Contato %d --\n", ident);
        printf("Código: %d \n", contato[ident-1].codigo);
        printf("Nome: %s \n", contato[ident-1].nome);
        printf("Telefone: %s \n", contato[ident-1].telefone);
    }
    else{
        printf("Contato inválido!\n");
    }
}
void alteracao(){
    if(ident > 0 && ident <= n){                    
        printf("Digite o novo valor para o o nome do contato %d (%s): \n",contato[ident-1].codigo, contato[ident-1].nome);
        scanf("%s", contato[ident-1].nome);
        printf("Digite o novo valor para o telefone do contato %d (%s): \n",contato[ident-1].codigo, contato[ident-1].telefone);
        scanf("%s", contato[ident-1].telefone);

        printf("Contato alterado com sucesso.\n");
    }
    else{
        printf("Contato inválido!\n");
    }
}
void exclusao(){
    if(ident > 0 && ident <= n){
        for( int e = ident; e < n; e++){
            strncpy(contato[ident-1].nome, contato[ident].nome, sizeof(contato[ident].nome));
            strncpy(contato[ident-1].telefone, contato[ident].telefone, sizeof(contato[ident].telefone));
            //contato[ident].tipo = contato[ident+1].tipo;
            contato[ident-1].codigo = contato[ident].codigo;
        } 
        n = n - 1;
        //contato = realloc (contato, (sizeof(Contato)*(n)));
        printf("Contato excluído com sucesso.\n");
    } else {
        printf("Código do contato não encontrado.\n");
    }
}
void inclusao(){
    contato = realloc (contato, (sizeof(Contato)*(n+1)));
    (contato+n)->codigo = n+1;

    printf("Digite o nome do contato que será salvo com o código %d: \n",contato[n].codigo);
    scanf("%s", contato[n].nome);

    printf("Digite o número de telefone do contato que será salvo com o código %d: \n",contato[n].codigo);
    scanf("%s", contato[n].telefone);

    printf("Contato incluído com sucesso.\n");

    n++;
}