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
printf("Digite a dimens�o da Matriz A: ");
fflush(stdin); //Limpa o cache da entrada
scanf("%d",&a); //Adquire a dimens�o da matriz
float matriz[a][a];//Define a matriz dos argumentos "a"
float termos[a]; //Define o vetor de termos independentes "b"
system("cls");

//Rotina para inser��o dos argumentos 'a'
printf("Digite os respectivos argumentos da Matriz A: \n\n");
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
printf("Matriz A: \n\n");
for(i=0;i<a;i++){
    for(j=0;j<a;j++){
    printf(" %.2f ",matriz[i][j]);
    }
    printf("| %.2f \n",termos[i]);
}

//C�lculo Gauss-Seidel
int n = 0; //vari�vel de contagem de itera��es
float resultados[a]; //vetor de resultados

//Inicio das itera��es
while (n < 100){
    for (i=0;i<a;i++){
    resultados[i] = (1/matriz[i][i])*(termos[i]-);
    }
    n++;
}
printf("N�mero de itera��es: %d \n\n", n);
printf("%.2f",resultados[0]);


//finaliza o programa
printf("\n");
system("PAUSE");

}
