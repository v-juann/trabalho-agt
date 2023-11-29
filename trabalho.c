/* Universidade do Estado de Santa Catarina
Alunos: Nicolas Vinicius Lobo Morais, Vinicius Juann Pereira
Trabalho Final - Agenda de Contatos
O objetivo deste trabalho consiste em desenvolver um programa para manter as informacoes de uma agenda de contatos utilizando variaveis compostas. 
A estrutura do contato deve conter um codigo de identificacao, nome, telefone e tipo do contato (pessoal ou trabalho).
O programa deve conter um menu inicial com 5 opcoes: 
i) incluir um novo contato; 
ii) excluir um contato existente; 
iii) alterar um contato existente; 
iv) listar todos os contatos cadastrados; e 
v) localizar um contato.
Na operacao de inclusao de um novo contato, deve ser utilizado um identificador exclusivo para cada contato. 
Uma sugestao é incrementar uma unidade no ultimo identificador valido de um contato. 
As opcoes de excluir, alterar e localizar um contato deve realizada a partir de um identificador do contato informado pelo usuario. 
A avaliacao do trabalho deve levar em conta o atendimento a todos os requisitos funcionais, bem como a organizacao e uso de boas praticas de desenvolvimento no codigo.*/

//Cabecalho
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

//Declaracao de funcoes
void listagem();
void localizador();
void alteracao();
void exclusao();
void inclusao();
int validaEnum();
void atualizaN();
const char* exibeTipo();

//Enumerador que define o tipo de contato
typedef enum{
    Pessoal = 0,
    Trabalho = 1
}Tipo;

//Estrutura do contato
typedef struct{
    int codigo;
    char nome[15];
    char telefone[12];
    Tipo tipo;
}Contato;

//Declaracao de variaveis
    int opcao, ident, n = 0, cont = 0, entrada;
    Contato *contato;

//Inicio do programa
int main(){

//Atribui um endereco nao nulo ao ponteiro
    contato = (Contato *) calloc(1, sizeof(Contato));
    
//Estrutura de repeticao que mantém o programa rodando até o usuario optar por sair
    do{
        printf("\nSelecione a opcao: \n");
        printf("1 - Incluir novo contato:\n");
        printf("2 - Excluir um contato existente:\n");
        printf("3 - Alterar um contato existente:\n");
        printf("4 - Listar todos os contatos cadastrados:\n");
        printf("5 - Localizar um contato:\n");
        printf("Pressione qualquer outra tecla para encerrar o programa.\n");
        scanf("%d", &opcao);

        switch(opcao){
            
            case 1:
            //Inclusao de novo contato
                inclusao();
                atualizaN();
            break;

            case 2:
            //Exclusao de contato existente
                if (n > 0) {
                    printf("Contatos existentes:\n");
                    for (int i = 0; i < n; i++) {
                        printf("Codigo: %d\n", contato[i].codigo);
                    }                   
                    printf("Digite o codigo do contato que voce quer excluir: \n");
                    scanf("%d", &ident);
                    
                    exclusao(ident);
                    atualizaN();
                }else {
                    printf("\nNao existem contatos cadastrados.\n");
                }
                break;

            case 3:
            //Alterar um contato existente
                if (n > 0) {
                    printf("Digite o codigo do contato que voce quer alterar: \n");
                    scanf("%d", &ident);

                    alteracao(ident);
                    atualizaN();
                } else{
                    printf("\nNao existem contatos cadastrados.\n");
                }
            break;
            
            case 4:
            //Lista todos os contatos cadastrados
                if (n > 0) {
                    listagem();
                } else{
                    printf("\nNao existem contatos cadastrados.\n");
                }
            break;

            case 5:
            //Localizar um contato
                if (n > 0) {
                    printf("Digite o codigo do contato que voce quer localizar: \n");
                    scanf("%d", &ident);

                    localizador(ident);
                } else{
                    printf("\nNao existem contatos cadastrados.\n");
                }
            break;

            //Opcao padrao para encerrar o programa quando o usuario apertar uma tecla que nao seja de 1 a 5
            default:
                return 0;
        }
    }while(main!=0);
}

//Funcoes
void listagem(){
    for(int w = 0; w < n; w++){
        printf("\n-- Contato %d --\n", w+1);
        printf("Codigo: %d \n", contato[w].codigo);
        printf("Nome: %s \n", contato[w].nome);
        printf("Telefone: %s \n", contato[w].telefone);
        printf("Tipo: %s \n", exibeTipo(contato[w].tipo));
    }
}

void localizador(){
    if(ident > 0 && ident <= cont){
        for (int x = 0; x <= cont; x++){
            if (contato[x].codigo == ident){
                printf("\n-- Contato %d --\n", ident);
                printf("Codigo: %d \n", contato[x].codigo);
                printf("Nome: %s \n", contato[x].nome);
                printf("Telefone: %s \n", contato[x].telefone);
                printf("Tipo: %s \n", exibeTipo(contato[x].tipo));
            }
        }
    }
    else{
        printf("Contato invalido!\n");
    }
}
void alteracao(){
    if(ident > 0 && ident <= cont){   
        for (int x = 0; x <= cont; x++){
            if (contato[x].codigo == ident){                 
                printf("Digite o novo valor para o o nome do contato %d (%s): \n",contato[x].codigo, contato[x].nome);
                scanf("%s", contato[x].nome);
                printf("Digite o novo valor para o telefone do contato %d (%s): \n",contato[x].codigo, contato[x].telefone);
                scanf("%s", contato[x].telefone);
                
                int verificacao = 0;
                do{
                    printf("Digite o novo valor para o tipo do contato %d (%d): \n",contato[x].codigo, contato[x].tipo);
                    scanf("%d", &entrada);
                    verificacao = validaEnum(entrada);
                    if(verificacao == 0){
                        printf("Entrada invalida! Por favor digite novamente:\n");
                }
                }
                while (verificacao == 0);
                contato[x].tipo = entrada;

                printf("Contato alterado com sucesso.\n");
            }
        }
    }
    else{
        printf("Contato invalido!\n");
    }
}
void exclusao(){
    if(ident > 0 && ident <= cont){
        for (int x = 0; x <= cont; x++){
            if (contato[x].codigo == ident){
                for( int e = ident; e <= n; e++){
                    strncpy(contato[e-1].nome, contato[e].nome, sizeof(contato[e].nome));
                    strncpy(contato[e-1].telefone, contato[e].telefone, sizeof(contato[e].telefone));
                    contato[e-1].tipo = contato[e].tipo;
                    contato[e-1].codigo = contato[e].codigo;
                } 

                contato = (Contato *) realloc (contato, (_msize(contato)-sizeof(Contato)));


                printf("Contato excluido com sucesso.\n");
            }
        }
    } else {
        printf("Codigo do contato nao encontrado.\n");
    }
}
void inclusao(){
    contato = (Contato *) realloc (contato, (_msize(contato)+sizeof(Contato)));
    (contato+n)->codigo = cont+1;

    printf("Digite o nome do contato que sera salvo com o codigo %d: \n", cont+1);
    scanf("%s", contato[n].nome);

    printf("Digite o numero de telefone do contato que sera salvo com o codigo %d: \n", cont+1);
    scanf("%s", contato[n].telefone);

    int verificacao = 0;
    do{
        printf("Digite o tipo de contato que sera salvo com o codigo %d (0 para Pessoal, 1 para Trabalho): \n", cont+1);
        scanf("%d", &entrada);
        verificacao = validaEnum(entrada);
        if(verificacao == 0){
            printf("Entrada invalida! Por favor digite novamente:\n");
        }
    }
    while (verificacao == 0);
    contato[n].tipo = entrada;

    printf("Contato incluido com sucesso.\n");

    //"cont" é a contagem de vezes que a inclusão é rodada, e "n" é a posição do último índice do vetor
    cont++;
}
int validaEnum(){
    if(entrada < 0 || entrada > 1){
        return 0;
    }else{
        return 1;
    }
}
const char* exibeTipo(int param){
    if (param == 0){
        return "Pessoal";
    }else{
        return"Trabalho";
    }
}
void atualizaN(){
    n = (_msize(contato) - sizeof(Contato)) / sizeof(Contato);
}