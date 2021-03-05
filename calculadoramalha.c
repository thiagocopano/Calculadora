#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{
//Defini��o de linguagem para acentua��o
setlocale(LC_ALL,"Portuguese");


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
int n = 0; //vari�vel de contagem de itera��es
float resultados[a]; //vetor de resultados
float res_ant[a];
float soma = 0;

/* ------ Inicio das itera��es ------ */

//Limpa as vari�veis
for (i=0;i<a;i++){
    resultados[i] = 0;
}

while (n < 1000){
    res_ant[a] = resultados[a];
    for (i=0;i<a;i++){
        soma = 0; //Zerar a vari�vel de soma

        for (j=0;j<a;j++){
            soma = soma + (matriz[i][j]*resultados[j]);
        }

        soma = (soma - matriz[i][i]*resultados[i]); // Exemplo: a11*x1 + a12*x2 + a13*x3 - a11*x1

        resultados[i] = ((termos[i]-soma)/matriz[i][i]);

        printf("[%d][%d] : %3.2f \n ", i, j, resultados[i]);
    }

/* ----- DESENVOLVER RUPTURA DE LOOP QUANDO ATINGIR A PRECIS�O DETERMINADA ----- */
//    if ((abs(res_ant[i])-abs(resultados[i])) < 0,001){
//        break;
//    }

    printf("\n");
    n++;
}
printf("\n");

//Resultados
printf(" N�mero de itera��es: %d \n\n", n);

for (i=0;i<a;i++){
printf(" X_%d = %.2f \n", i, resultados[i]);
}

//finaliza o programa
printf("\n");
system("PAUSE");

}
