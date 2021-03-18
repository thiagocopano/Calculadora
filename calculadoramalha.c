#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/* ------- Função para verificar se um número é inteiro ------------ */
int verifica_int(float valor){
    if (valor == (int)valor){ //(int)valor -> transforma em inteiro
        return 1;
    } else {
        return 0;
    }
    return 0;
}

/* ------- Função main() -------------------------------------------- */
int main(){

/* ------- Configurações da calculadora ----------------------------- */
setlocale(LC_ALL,"Portuguese");//Definição de linguagem para acentuação



//Definição de variáveis
int a; //dimensão da matriz
int i; //contador de linha
int j; //contador de coluna
int erro = 0; //auxiliar de erro de cálculo

/* ------- Rotina para identificação da dimensão da matriz ---------- */
printf("\n");      //Vai pra próxima linha
printf(" | CALCULADORA DE SISTEMAS LINEARES ");
printf("\n | \n"); //Pula 1 linha
printf(" | Dimensão da Matriz = ");
fflush(stdin);     //Limpa o cache da entrada
scanf("%d",&a);    //Adquire a dimensão da matriz
printf(" | \n\n");

float matriz[a][a];//Define a matriz dos argumentos "a"
float termos[a];   //Define o vetor de termos independentes "b"


/* ------- Rotina para inserção dos argumentos ---------------------- */

printf(" | Digite os argumentos da Matriz ");
printf("\n | \n");

//Imprime o modelo da matriz a ser digitada
for(i=0;i<a;i++){ //repetição responsável pelas LINHAS 
    printf(" |");
    for(j=0;j<a;j++){ //repetição responsável pelas COLUNAS
    printf(" a%d%d", i+1, j+1);
    }
    printf(" | b%d |\n",i+1);
}
printf(" | \n\n | Argumentos: \n | \n");

/* ----- Rotina para inserção dos argumentos 'a' ----- */
for(i=0;i<a;i++){//repetição responsável pelas LINHAS 
	
	for(j=0;j<a;j++){{//repetição responsável pelas COLUNAS
		printf(" | a%d%d = ", i+1, j+1);
		fflush(stdin);
		scanf("%f",&matriz[i][j]);
  	}
			 
}
	
printf(" | \n\n | Termos independentes: \n | \n");

//Rotina para inserção dos termos independentes 'b'
for(i=0;i<a;i++){
    printf(" | b%d = ", i+1);
    fflush(stdin);
    scanf("%f",&termos[i]);
}
printf(" | \n\n");

//Rotina para imprimir a matriz inserida
system("cls"); // Limpa a tela

printf("\n");      //Vai pra próxima linha
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

/* ------ Definição de variáveis para os cálculos ---------- */
int aux = 0;
float resultados[a]; //vetor de resultados
float res_ant[a];
int n = 1;      //Para contagem de iterações
float soma = 0; //Para soma dos argumentos


/* ------------------ Inicio das iterações ----------------- */
//Limpa as variáveis antes de iniciar
for (i=0;i<a;i++){
    resultados[i] = 0;
    res_ant[i] = 0;
}

printf(" | Inicio das Iterações ");
printf("\n | \n"); //Pula 1 linha

//Inicia o Loop
while (aux != a){

    //printf(" | Iteração Nº %d \n", n);

    //condição para numero máximo de iterações
    if(n >= 1000){
        printf("\n");
        erro =1;
        break;
    }


    /* --------- Repetição para calcular a soma dos argumentos ------------------------------- */
    for (i=0;i<a;i++){
        soma = 0; //Zerar a variável de soma

        //Soma de todos os argumentos "a" da linha
        for (j=0;j<a;j++){
            soma = soma + (matriz[i][j]*resultados[j]);
        }
	
	//remoção do argumento que acompanha x_1
        soma = ((soma) - matriz[i][i]*resultados[i]); // Exemplo: (a11*x1 + a12*x2 + a13*x3) - a11*x1
	    
        resultados[i] = ((termos[i]-soma)/matriz[i][i]); //Calcula o resultado para x_i
    }

/* ----- Condição para verificar a diferença entre todos -----
   ----- termos calculados em 1 rodada de 'a' argumentos ----- */
	
    if (verifica_int(i/a)){//verifica se 'i' é múltiplo de 'a'
        aux = 0; //redefine a variável auxiliar que acumula
        float diferenca[a];
            for (i=0;i<a;i++){
                float n1 = fabs(res_ant[i]);
                float n2 = fabs(resultados[i]);
                if (fabs(n1-n2) <= 0.001){
                    aux++;
                }
            }
        //Repetição para atualizar o vetor de resultados anteriores.
        for (i=0;i<a;i++){
            res_ant[i] = resultados[i];
        }
    }
    n++;//contador de iterações
};

/* ------------- Impressão de resultados ------------- */
if (erro == 1){
    printf(" | ERRO DE CÁLCULO: \n | \n");
    printf(" | Matriz informada inconsistente \n | \n");

}else{
printf(" | \n\n | Precisão  = 0.001");
printf(" \n | Iterações = %5.d", n);
printf(" \n | \n", n); //Pula 1 linha

for (i=0;i<a;i++){
printf(" | x%d = %10.5f \n", i+1, resultados[i]);
}
}

//Menu para finalização do programa ou realizar outro cálculo
int menu = 0;
printf(" \n | \n | 1. Calcular Novamente \n");
printf(" | 2. Sair \n");
printf(" | \n");
printf(" | Digite o nº da opção desejada: ");
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
