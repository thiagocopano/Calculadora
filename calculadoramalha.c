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
printf(" Digite a dimensão da Matriz A: ");
fflush(stdin); //Limpa o cache da entrada
scanf("%d",&a); //Adquire a dimensão da matriz
float matriz[a][a];//Define a matriz dos argumentos "a"
float termos[a]; //Define o vetor de termos independentes "b"
system("cls");

//Rotina para inserção dos argumentos 'a'
printf(" Digite os respectivos argumentos da Matriz A: \n\n");
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
printf(" Matriz A: \n\n");
for(i=0;i<a;i++){
    for(j=0;j<a;j++){
    printf(" %.2f ",matriz[i][j]);
    }
    printf("| %.2f \n",termos[i]);
}
printf("\n");


//Cálculo Gauss-Seidel
int n = 0; //variável de contagem de iterações
float resultados[a]; //vetor de resultados
float res_ant[a];
float soma = 0;

/* ------ Inicio das iterações ------ */

//Limpa as variáveis
for (i=0;i<a;i++){
    resultados[i] = 0;
}

while (n < 1000){
    res_ant[a] = resultados[a];
    for (i=0;i<a;i++){
        soma = 0; //Zerar a variável de soma

        for (j=0;j<a;j++){
            soma = soma + (matriz[i][j]*resultados[j]);
        }

        soma = (soma - matriz[i][i]*resultados[i]); // Exemplo: a11*x1 + a12*x2 + a13*x3 - a11*x1

        resultados[i] = ((termos[i]-soma)/matriz[i][i]);

        printf("[%d][%d] : %3.2f \n ", i, j, resultados[i]);
    }

/* ----- DESENVOLVER RUPTURA DE LOOP QUANDO ATINGIR A PRECISÃO DETERMINADA ----- */
//    if ((abs(res_ant[i])-abs(resultados[i])) < 0,001){
//        break;
//    }

    printf("\n");
    n++;
}
printf("\n");

//Resultados
printf(" Número de iterações: %d \n\n", n);

for (i=0;i<a;i++){
printf(" X_%d = %.2f \n", i, resultados[i]);
}

//finaliza o programa
printf("\n");
system("PAUSE");

}
