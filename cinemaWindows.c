/*
    Titulo: Cinema
    Descrição: Parte do código da P1 de COMP1 do curso Ciência da Computação - UFRJ. Eliminamos certas partes para facilitar entendimento do código.
    Data: 10/06/2022
    Autores:
        Gustavo Villar Marinatto.
        Victor Pereira da Silva dos Santos. 
        Pedro Henrique Lopes Cabral. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INGRESSO 30

/*prototipos*/
void escolhaFilme();
void comprarIngressos(int returnArr[]);
void definirPoltronas(void);
void selecaoPoltrona(int numeroDeIngressos, int numeroDePoltronas);
void mostrarPoltronas();
void telaDePagamento(int preco);

/*variaveis globais*/
int poltronas[25][10];
int v;

/*funcoes*/
int main (void){
    /*variaveis*/
    int numeroDePoltronas;
    int numeroDeIngressos;
    int returnArr[2];
    int preco;
    
    /*codigo*/
    while (1)
    {
        escolhaFilme();
        comprarIngressos(returnArr);
        numeroDeIngressos = returnArr[0];
        preco = returnArr[1];
        
        numeroDePoltronas = numeroDeIngressos;

        definirPoltronas();
        selecaoPoltrona(numeroDeIngressos, numeroDePoltronas);
        telaDePagamento(preco);
    }
    
    return 0;
}

/*---------------------------------------------------*/

void escolhaFilme (){
    int opcao;

    v = system("cls");
    printf("===============Cinema Mariano Pinheiro===============\n\n");
    printf("Bem vindo!\n");
    printf("Selecione o filme que deseja assistir: ");
    printf("\n\n    0- Encerrar\n    1- Sonic 2\n    2- Top Gun\n    3- Jurassic World\n\n");
    v = scanf("%d", &opcao);
    getchar();

    switch (opcao) {

        case 0:
        exit(0);
        
        case 1:
            break;


        case 2:
            break;

        case 3:
            break;

        default:
            printf("Numero invalido. Tente novamente.");
            escolhaFilme();
    }
}

/*---------------------------------------------------*/
void comprarIngressos(int returnArr[]){

    /*variaveis locais*/
    int ingressosTotais;
    int preco;

    printf("\nQuantos ingressos deseja comprar?\n\n");
    
    v = scanf("%d", &ingressosTotais);
    
        while(ingressosTotais<=0 || ingressosTotais>250)
        {
            printf("\nQuantidade impossivel.\nSelecione uma quantidade valida:\n");
            v = scanf("%d", &ingressosTotais);
            fflush(stdin);
        }

    preco = ingressosTotais*INGRESSO;

    /*RETURN*/
    returnArr[0] = ingressosTotais;
    returnArr[1] = preco;
}

/*---------------------------------------------------*/

void selecaoPoltrona(int numeroDeIngressos, int numeroDePoltronas){
   
    int fileira;
    char charColuna;
    int coluna;

    if(numeroDePoltronas>=1){
        mostrarPoltronas();
        printf("\nVoce ainda tem %d ingressos.", numeroDePoltronas);
        

        printf("\nSelecione a poltrona para o ingresso (%d/%d). Exemplo: 2A, 4C, 25J. Insira 0A para retornar.\n", numeroDeIngressos-numeroDePoltronas+1, numeroDeIngressos);
        
        v = scanf(" %d %c", &fileira, &charColuna);
        getchar();
        
        coluna = (int)charColuna;

        if(fileira == 0){
            main();
        }

        if (fileira<1 || fileira>25)
        {
            printf("\nFileira invalida. Pressione ENTER para tentar denovo.\n");
            getchar();
            selecaoPoltrona(numeroDeIngressos, numeroDePoltronas);
        }
        
        if (coluna < 65 || coluna > 74)
        {
            printf("\nColuna invalida. Pressione ENTER para tentar denovo.\n");
            getchar();
            selecaoPoltrona(numeroDeIngressos, numeroDePoltronas);
        }
        
        if (coluna == 65) coluna = 1;
        if (coluna == 66) coluna = 2;
        if (coluna == 67) coluna = 3;
        if (coluna == 68) coluna = 4;
        if (coluna == 69) coluna = 5;
        if (coluna == 70) coluna = 6;
        if (coluna == 71) coluna = 7;
        if (coluna == 72) coluna = 8;
        if (coluna == 73) coluna = 9;
        if (coluna == 74) coluna = 10;

        if(poltronas[fileira][coluna] != 0){
            poltronas[fileira][coluna] = 0;
            numeroDePoltronas--;
            selecaoPoltrona(numeroDeIngressos, numeroDePoltronas);
        }

        else{
            printf("\nEssa poltrona ja foi selecionada, pressione ENTER para selecionar outra.");
            getchar();
            selecaoPoltrona(numeroDeIngressos, numeroDePoltronas);
        }
    }

    else {
        mostrarPoltronas();
        printf("\nVoce selecionou todos os assentos.");
        printf("\nPressione ENTER para prosseguir ao pagamento.");
        getchar();
    }
}

/*---------------------------------------------------*/

void mostrarPoltronas(){
    int i,j;
    char mapaComprado[25][10];

    v = system("cls");
    printf("\n-----------POLTRONAS COM X INDISPONIVEIS-----------\n\n");
    printf("     A  B  C  D  E  F  G  H  I  J\n\n");
    

    /*ASSOCIA O VALOR DAS POLTRONAS COM X E O*/
    for(i=1;i<=25;i++){
        for(j=1;j<10;j++){
            if (poltronas[i][j] == 0){
                mapaComprado[i][j] = 'X';
            }
            else {
                mapaComprado[i][j] = '-';
            }
        }
    }

    /*DESENHA O MAPA*/
    for(i=25;i>0;i--){
        /*margem*/
        if(i>=10) 
            printf("%d   "  ,i);
        else 
            printf("0%d   ", i);
        
        /*imprime os lugares*/
        for(j=1;j<10;j++){
            
            printf("%c  ",mapaComprado[i][j]);
        }
        printf("\n");
    }
}

/*------------------------------------*/


void definirPoltronas (void){
    int i, j;
    /*GERA UM CODIGO PRA CADA POLTRONA*/
    for(i=1;i<=25;i++){
        for(j=1;j<=10;j++){
            if(j == 1)
                poltronas[i][j] = i * 65;
            if(j == 2)
                poltronas[i][j] = i * 66;
            if(j == 3)
                poltronas[i][j] = i * 67;
            if(j == 4)
                poltronas[i][j] = i * 68;
            if(j == 5)
                poltronas[i][j] = i * 69;
            if(j == 6)
                poltronas[i][j] = i * 70;
            if(j == 7)
                poltronas[i][j] = i * 71;
            if(j == 8)
                poltronas[i][j] = i * 72;
            if(j == 9)
                poltronas[i][j] = i * 73;
            if(j == 10)
                poltronas[i][j] = i * 74;
        }
    }    
}

/*---------------------------------------------------*/

void telaDePagamento(int preco){/*Recado fnal ao cliente*/
    printf("\n\n================PAGAMENTO================\n\n");
    printf("Valor total da compra: R$: %d,00",preco);
    printf("\nObrigado por confiar na Mariano Pinheiro!\n");
    printf("Bom Filme! ------------------------------");
    printf("\n\nPressione ENTER para terminar.");
    getchar();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}


/*FIM DO PROGRAMA*/
