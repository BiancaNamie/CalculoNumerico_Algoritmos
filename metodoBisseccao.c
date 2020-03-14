#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MODULO(x) ((x)>=0?(x):-(x))     // modulo, se o valor for negativo, se torna positivo
#define e 2.718281828

float funcao (float x);
int main();

float funcao (float x){             ///Onde coloca a funcao
    return (x+1)*(x+1) * pow(e, pow(x, 2)-2) - 1;
}
int main(){
    float a, b, p, fInicio, meio, fMeio;
    int n, k;

    printf("Intervalo que contem a raiz: ");
    scanf("%f %f", &a, &b);
    printf("Precisao: ");
    scanf("%f", &p);
    printf("Numero maximo de iteracoes: ");
    scanf("%d", &n);

    k=0;

   if (MODULO(b-a) < p){                    /// caso ele ache o valor antes de entrar no metodo
        printf("Zero iteracoes, resultado = %f",  abs(a+b)/2);
        return 0;
    }

    while (MODULO(b-a) > p && k < n){       ///criterios de parada
        k+=1;
        fInicio = funcao(a);
        meio = (a+b)/2;
        fMeio = funcao(meio);

        if (fInicio*fMeio < 0){     ///verifica se o sinal das funcoes é diferente
            b = meio;
        }else{
            a = meio;
        }
    }
    printf("A raiz e: %f\n", meio);
    printf("Numero de iteracoes: %d", k);

    return 0;
}
