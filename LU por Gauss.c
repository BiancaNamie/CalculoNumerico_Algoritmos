#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N;  // tamanho da matriz


void LU_por_gauss(float A[N][N],float L[N][N],float B[N],float X[N],float Y[N]);
void trocar_linha(float A[N][N],float L[N][N],int linha1, int linha2);

void LU_por_gauss(float A[N][N],float L[N][N],float B[N],float X[N],float Y[N]){
	float pivo;
	float m[N];

	for(int linha = 1; linha < N; linha++){
        pivo = A[linha][linha];

        if(pivo != 0){
			for(int linha2 = linha+1; linha2 < N; linha2++){   ///Lx = Lx - L[]/pivo * Lx-1 para todas as linhas abaixo do pivo
				m[linha2] = A[linha2][linha] / pivo;
				L[linha2][linha] = m[linha2];                 /// O m é o valor dado a L

                for(int coluna = 1; coluna < N; coluna++){
                    A[linha2][coluna] = A[linha2][coluna] - m[linha2] * A[linha][coluna];
                }
            }
        }else{
            /// Se pivo == 0, trocar com alguma linha abaixo !=0
            int linha2 = linha +1;
            while (A[linha2][linha] == 0){
                linha2++;
                if (linha2 >= N){
                    printf("ERRO");
                    return;
                }
            }

            trocar_linha(A,L,linha, linha2);
            linha--;
		}
    }

    printf("\nMatriz U\n");
    for (int i = 1; i < N; i++){
		for (int j = 1; j < N; ++j){
			printf("%f ", A[i][j]);
		}
		printf("\n");
	}
    printf("\nMatriz L\n");
    for (int i = 1; i < N; i++){
		for (int j = 1; j < N; ++j){
			printf("%f ", L[i][j]);
		}
		printf("\n");
	}


	float soma;

	/*----------------- Ly = b ----------------------*/
	printf("\n\nY =");
	for(int i = 1; i < N; ++i){
        for(int j = 1; j < i; ++j){
            soma += L[i][j] * Y[j];
        }
        Y[i] = B[i] - soma;
        printf("\n %f \n", Y[i]);
        soma = 0;
    }

    /*----------------- Ux = y ----------------------*/
    printf("\n\nX =");
    for (int i = N-1; i >= 1; i--){
        for(int j = N-1; j > i; j--){
            soma += A[i][j] * X[j];
        }
        X[i] = (Y[i] - soma) / A[i][i];
        soma = 0;
    }
    for (int i = 1; i <N; i++){
        printf("\n %f \n", X[i]);
    }
}

void trocar_linha(float A[N][N],float L[N][N], int linha1, int linha2){
    float temp;

    if(linha1 != linha2){
        for (int i = 0; i < N+1; i++) {
            temp = A[linha1][i];
            A[linha1][i] = A[linha2][i];
            A[linha2][i] = temp;
        }
        int i =0;
        printf("\n%d %d\n", linha1, linha2);
        while (i< linha1){      /// o i vai caminhando pelas colunas trocadas até chegar a coluna que está sendo invertida.
            temp = L[linha1][i];
            L[linha1][i] = L[linha2][i];
            L[linha2][i] = temp;
            i++;
        }
    }
}

int main(void){
	int TAM;

	printf("Tamanho da matriz A: ");
	scanf("%d", &N);
	N = N + 1;

    float A[N][N], B[N];        ///matriz A se torna a matriz U
	float L[N][N];
	float X[N], Y[N];


	 /* Le os valores da matriz A */
    printf("Valores da matriz A: ");
    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
           scanf("%f", &A[i][j]);
        }
    }
    /* Le os valores de B */
    printf("Valores do vetor B: ");
    for(int i = 1; i < N; i++) {
         scanf("%f", &B[i]);
    }

    /* Valores Fixos de L */
    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
            L[i][j] = 0;
        }
        L[i][i] = 1;
    }

    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
           printf(" %f ", A[i][j]);
        }
        printf("\n");
    }

    LU_por_gauss(A, L, B, X, Y);

}
