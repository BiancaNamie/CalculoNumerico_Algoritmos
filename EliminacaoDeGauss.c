#include <stdio.h>
#include <stdlib.h>


int N;
float AB[100][101];

void trocar_linha(int linha1, int linha2){
    float temp;

    if(linha1 != linha2){
        for (int i = 0; i < N+1; i++) {
            temp = AB[linha1][i];
            AB[linha1][i] = AB[linha2][i];
            AB[linha2][i] = temp;
        }
    }
}

void eliminacao_de_gauss(){
	float pivo, soma;
	float m[N], X[N];  ///m = multiplicador , X = resultado

	for(int linha = 1; linha < N-1; linha++){
        pivo = AB[linha][linha];
        if(pivo != 0){
			for(int linha2 = linha+1; linha2 < N; linha2++){   ///Lx = Lx - L[]/pivo * Lx-1 para todas as linhas abaixo do pivo
				m[linha2] = AB[linha2][linha] / pivo;
                for(int coluna = 1; coluna <= N; coluna++){
                    AB[linha2][coluna] = AB[linha2][coluna] - m[linha2] * AB[linha][coluna];
                }
            }
        }else{
            /// Se pivo == 0, trocar com alguma linha abaixo !=0
            int linha2 = linha +1;
            while (AB[linha2][linha] == 0){
                linha2++;
                if (linha2 >= N){
                    printf("ERRO");
                    return;
                }
            }

            trocar_linha(linha, linha2);
            linha--;
		}
    }

    printf("\nMatriz depois de efetuado eliminacao de gauss\n");
    for (int i = 1; i < N; i++){
		for (int j = 1; j < N+1; ++j){
			printf("%f ", AB[i][j]);
		}
		printf("\n");
	}

	/*---------Calcula e printa X--------*/
	soma=0;
    for (int i = N-1 ; i>0 ; i--){
        for (int j = N-1 ; j>i ; j--){
            soma = soma + AB[i][j] * X[j];
        }
        X[i] = (AB[i][N] - soma) / AB[i][i];
        soma =0;
    }
    printf("\nx= \n");
    for(int i = 1; i < N; i++){
        printf(" %f\n", X[i]);
    }
}


int main(void){
	printf("Tamanho da matriz A: ");
	scanf("%d", &N);
	N = N + 1;

    printf("Elementos da matriz aumentada AB: \n");

    for(int i = 1; i < N; i++){
		for(int j = 1; j < N+1; ++j){
			scanf("%f", &AB[i][j]);
		}
	}

	for (int i = 1; i < N; i++){
		for (int j = 1; j < N+1; ++j){
			printf("%f ", AB[i][j]);
		}
		printf("\n");
	}

	eliminacao_de_gauss();

	return 0;
}


