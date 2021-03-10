#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/* ------- Fun��o para verificar se um n�mero � inteiro --------- */
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


//Rotina para identifica��o da dimens�o da matriz
printf(" Digite a dimens�o da Matriz A: ");
fflush(stdin); //Limpa o cache da entrada
scanf("%d",&a); //Adquire a dimens�o da matriz
float matriz[a][a];//Define a matriz dos argumentos "a"
float termos[a]; //Define o vetor de termos independentes "b"
system("cls");

//Rotina para inser��o dos argumentos 'a'
printf(" Digite os respectivos argumentos da Matriz A: \n\n");
for(i=0;i<a;i++){
	for(j=0;j<a;j++){
		printf("a[%d][%d]: ", i+1, j+1);
		fflush(stdin);
		scanf("%f",&matriz[i][j]);
    }
}

//Rotina para inser��o dos termos independentes 'b'
printf("\n Digite os termos independentes: \n\n");
for(i=0;i<a;i++){
    printf("b[%d]", i+1);
    fflush(stdin);
    scanf("%f",&termos[i]);
}

//Rotina para imprimir a matriz inserida
system("cls");
printf("\n");
printf(" Matriz A: \n\n");
for(i=0;i<a;i++){
    for(j=0;j<a;j++){
    printf(" %.2f ",matriz[i][j]);
    }
    printf("| %.2f \n",termos[i]);
}
printf("\n");


//C�lculo Gauss-Seidel
int aux = 0;
float resultados[a]; //vetor de resultados
float res_ant[a];


/* ------ Inicio das itera��es ------ */

//Limpa as vari�veis antes de iniciar
for (i=0;i<a;i++){
    resultados[i] = 0;
    res_ant[i] = 0;
}

//Inicia o Loop
while (aux != 3){

    /* --------- Vari�veis Locais ---------*/
    int n;      //Para contagem de itera��es
    float soma; //Para soma dos argumentos

    /* --------- Repeti��o para calcular a soma dos argumentos ------------------------------- */
    for (i=0;i<a;i++){

        soma = 0; //Zerar a vari�vel de soma

        //Soma dos argumentos
        for (j=0;j<a;j++){
            soma = soma + (matriz[i][j]*resultados[j]);
        }

        soma = (soma - matriz[i][i]*resultados[i]); // Exemplo: a11*x1 + a12*x2 + a13*x3 - a11*x1
        resultados[i] = ((termos[i]-soma)/matriz[i][i]); //

        printf("[%d][%d] : %3.2f \n ", i, j, resultados[i]);
    }

    //Condi��o para verificar a diferen�a entre todos
    //termos calculados em 1 rodada de 'a' argumentos
    if (verifica_int(i/a)){
        aux = 0; //redefine a vari�vel auxiliar que acumula
        printf("\n Verificando diferen�a... \n\n");
        float diferenca[a];


            for (i=0;i<a;i++){
                float n1 = fabs(res_ant[i]);
                float n2 = fabs(resultados[i]);

                printf("M�dulo do res_ant[%d]: %3.2f \n", i, n1);
                printf("M�dulo do resultados[%d]: %3.2f \n", i, n2);

                diferenca[i] = fabs(n1-n2);

                printf("Diferen�a[%d]: %3.2f \n\n", i, diferenca[i]);
            }
            for (i=0;i<a;i++){
                if (diferenca[i] < 0.01){
                    aux++;
                    printf("Aux[%d]: %d \n\n", i, aux);
                }
            }
        //Repeti��o para atualizar o vetor de resultados anteriores.
        for (i=0;i<a;i++){
            res_ant[i] = resultados[i];
        }
    }
    printf("\n");
    n++;

system("PAUSE");
}
printf("\n");

//Resultados
//printf(" N�mero de itera��es: %d \n\n", n);

for (i=0;i<a;i++){
printf(" X_%d = %.2f \n", i, resultados[i]);
}

//finaliza o programa
printf("\n");
system("PAUSE");

}
