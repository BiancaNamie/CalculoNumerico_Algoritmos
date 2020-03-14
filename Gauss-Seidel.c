#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MODULO(x) ((x)>=0?(x):-(x))     // modulo, se o valor for negativo, se torna positivo

int main(void){
	int TAM;        /// tamanho da matriz
    int n, k=0;     ///iteracoes
    float soma;
    float Mr = 999.99, delta, maior1, maior2;    ///criterio de parada

	printf("Tamanho da matriz A: ");
	scanf("%d", &TAM);
	TAM = TAM + 1;

	float A[TAM][TAM]; // Matriz dos coeficientes
	float B[TAM]; // Matriz de constantes
	float AB[TAM][TAM+1]; // Matriz aumentada

	float X[TAM];
	float X0[TAM];


    printf("Digite os valores da matriz A: ");
    for(int i = 1; i < TAM; i++) {
        for(int j = 1; j < TAM; j++) {
           scanf("%f", &A[i][j]);
        }
    }

    printf("Digite os valores do Vetor B: ");
    for(int i = 1; i < TAM; i++) {
         scanf("%f", &B[i]);
    }

    printf("Digite os valores de x0: ");
    for(int i = 1; i < TAM; i++) {
         scanf("%f", &X[i]);
    }

    printf("Valor de Delta: ");
    scanf("%f", &delta);

    printf("Numero maximo de iteracoes: ");
    scanf("%d", &n);

    while(Mr > delta && k<n){
        maior1 = 0.0;
        maior2 = 0.0;

        for(int i=1; i<TAM; i++){   ///copia x em vetor aux p usar no criterio de parada
            X0[i] = X[i];
        }

        for(int i=1; i<TAM; i++){
            soma = 0.0;
            for(int j=1; j<TAM; j++){
                soma = soma + A[i][j]*X[j];
            }
            X[i] = (B[i] - soma + A[i][i]*X[i])/A[i][i];

            if (MODULO(X[i]) > maior1){
                maior1 = MODULO(X[i]);
            }
        }

        for(int i=1; i<TAM; i++){
            X0[i] = MODULO( X[i] - X0[i]);

            if (X0[i] > maior2){
                maior2 = X0[i];
            }
        }

        Mr = maior2/maior1;         ///criterio de parada
        k++;

    }

    printf("\n\nx = ");
    for(int i=1; i<TAM; i++){
        printf("\t%f \n", X[i]);
    }
    printf("\nIterações utilizadas: %d\n", k);

}
