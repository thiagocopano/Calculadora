#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/* ------- Fun��o para verificar se um n�mero � inteiro ------------ */
int verifica_int(float valor){
    if (valor == (int)valor){ //(int)valor -> transforma em inteiro
        return 1;
    } else {
        return 0;
    }
    return 0;
}

/* ------- Fun��o main() -------------------------------------------- */
int main(){

/* ------- Configura��es da calculadora ----------------------------- */
setlocale(LC_ALL,"Portuguese");//Defini��o de linguagem para acentua��o



//Defini��o de vari�veis
int a; //dimens�o da matriz
int i; //contador de linha
int j; //contador de coluna


/* ------- Rotina para identifica��o da dimens�o da matriz ---------- */
printf("\n");      //Vai pra pr�xima linha
printf(" | CALCULADORA DE SISTEMAS LINEARES ");
printf("\n | \n"); //Pula 1 linha
printf(" | Dimens�o da Matriz = ");
fflush(stdin);     //Limpa o cache da entrada
scanf("%d",&a);    //Adquire a dimens�o da matriz
printf(" | \n\n");

float matriz[a][a];//Define a matriz dos argumentos "a"
float termos[a];   //Define o vetor de termos independentes "b"


/* ------- Rotina para inser��o dos argumentos ---------------------- */

printf(" | Digite os argumentos da Matriz ");
printf("\n | \n");

//Imprime o modelo da matriz a ser digitada
for(i=0;i<a;i++){
    printf(" |");
    for(j=0;j<a;j++){
    printf(" a%d%d", i+1, j+1);
    }
    printf(" | b%d |\n",i+1);
}
printf(" | \n\n | Argumentos: \n | \n");

//Rotina para inser��o dos argumentos 'a'
for(i=0;i<a;i++){
	for(j=0;j<a;j++){
		printf(" | a%d%d = ", i+1, j+1);
		fflush(stdin);
		scanf("%f",&matriz[i][j]);
    }
}
printf(" | \n\n | Termos independentes: \n | \n");

//Rotina para inser��o dos termos independentes 'b'
for(i=0;i<a;i++){
    printf(" | b%d = ", i+1);
    fflush(stdin);
    scanf("%f",&termos[i]);
}
printf(" | \n\n");

//Rotina para imprimir a matriz inserida
system("cls"); // Limpa a tela

printf("\n");      //Vai pra pr�xima linha
printf(" | CALCULADORA DE SISTEMAS LINEARES ");
printf("\n | \n"); //Pula 1 linha
printf(" | Matriz informada ");
printf("\n | \n");
for(i=0;i<a;i++){
    printf(" |");
    for(j=0;j<a;j++){
    printf(" %7.2f", matriz[i][j]);
    }
    printf(" | %7.2f |\n", termos[i]);
}
printf(" | \n\n");

/* ------ Defini��o de vari�veis para os c�lculos ---------- */
int aux = 0;
float resultados[a]; //vetor de resultados
float res_ant[a];
int n = 1;      //Para contagem de itera��es
float soma = 0; //Para soma dos argumentos


/* ------------------ Inicio das itera��es ----------------- */
//Limpa as vari�veis antes de iniciar
for (i=0;i<a;i++){
    resultados[i] = 0;
    res_ant[i] = 0;
}

printf(" | Inicio das Itera��es ");
printf("\n | \n"); //Pula 1 linha

//Inicia o Loop
while (aux != a){

    printf(" | Itera��o N� %d \n", n);

    //condi��o para numero m�ximo de itera��es
    if(n >= 1000){
        printf("\n");
        break;
    }


    /* --------- Repeti��o para calcular a soma dos argumentos ------------------------------- */
    for (i=0;i<a;i++){
        soma = 0; //Zerar a vari�vel de soma

        //Soma dos argumentos
        for (j=0;j<a;j++){
            soma = soma + (matriz[i][j]*resultados[j]);
        }
        soma = (soma - matriz[i][i]*resultados[i]); // Exemplo: a11*x1 + a12*x2 + a13*x3 - a11*x1
        resultados[i] = ((termos[i]-soma)/matriz[i][i]); //
    }

    //Condi��o para verificar a diferen�a entre todos
    //termos calculados em 1 rodada de 'a' argumentos
    if (verifica_int(i/a)){
        aux = 0; //redefine a vari�vel auxiliar que acumula
        float diferenca[a];
            for (i=0;i<a;i++){
                float n1 = fabs(res_ant[i]);
                float n2 = fabs(resultados[i]);
                if (fabs(n1-n2) <= 0.001){
                    aux++;
                }
            }
        //Repeti��o para atualizar o vetor de resultados anteriores.
        for (i=0;i<a;i++){
            res_ant[i] = resultados[i];
        }
    }
    n++;
};

/* ------------- Impress�o de resultados ------------- */

printf(" | \n\n | Precis�o do c�lculo = 0.001");
printf(" \n | \n"); //Pula 1 linha

for (i=0;i<a;i++){
printf(" | x%d = %10.5f \n", i+1, resultados[i]);
}

//Menu para finaliza��o do programa ou realizar outro c�lculo
int menu = 0;
printf(" \n | \n | 1. Calcular Novamente \n");
printf(" | 2. Sair \n");
printf(" | \n");
printf(" | Digite o n� da op��o desejada: ");
fflush(stdin);
scanf("%d",&menu);
if(menu == 1){
    main();
}
if(menu == 2){
    printf(" \n | Finalizando o programa... \n");
    exit(0);
}
}
