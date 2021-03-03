#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{
//Definição de linguagem para acentuação
setlocale(LC_ALL,"Portuguese");


//Definição de variáveis
int a; //dimensão da matriz
int i; //contador de linha
int j; //contador de coluna


//Rotina para identificação da dimensão da matriz
printf("Digite a dimensão da Matriz A: ");
fflush(stdin); //Limpa o cache da entrada
scanf("%d",&a); //Adquire a dimensão da matriz
float matriz[a][a];//Define a matriz dos argumentos "a"
float termos[a]; //Define o vetor de termos independentes "b"
system("cls");

//Rotina para inserção dos argumentos 'a'
printf("Digite os respectivos argumentos da Matriz A: \n\n");
for(i=0;i<a;i++){
	for(j=0;j<a;j++){
		printf("a[%d][%d]: ", i+1, j+1);
		fflush(stdin);
		scanf("%f",&matriz[i][j]);
    }
}

//Rotina para inserção dos termos independentes 'b'
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

//Cálculo Gauss-Seidel
int n = 0; //variável de contagem de iterações
float resultados[a]; //vetor de resultados

//Inicio das iterações
while (n < 100){
    for (i=0;i<a;i++){
    resultados[i] = (1/matriz[i][i])*(termos[i]-);
    }
    n++;
}
printf("Número de iterações: %d \n\n", n);
printf("%.2f",resultados[0]);


//finaliza o programa
printf("\n");
system("PAUSE");

}
