#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MODULO(x) ((x)>=0?(x):-(x))     // modulo, se o valor for negativo, se torna positivo
#define e 2.718281828

///pow(base, expoente)  -> fazer elevado
float funcao(float x){
    return (x+1)*(x+1) * pow(e, pow(x, 2)-2) - 1;
}
float derivada(float x){
    return 2 * x * pow(e, (x*x));
}

int main(){
    float x0, x1, p, fx, fxlinha, raiz;
    int n, k;

    printf("Aproximacao: ");
    scanf("%f", &x0);
    printf("Precisao: ");
    scanf("%f", &p);
    printf("Numero maximo de iteracoes: ");
    scanf("%d", &n);

    fx = funcao(x0);
    if (MODULO(fx) > p){
        k=1;
        fxlinha = derivada(x0);
        x1 = x0 - (fx/fxlinha);     //formula newton
        fx = funcao(x1);
        while(MODULO(fx) > p && MODULO(x1-x0) > p && k<n){
            k++;
            x0 = x1;
            fxlinha = derivada(x0);
            x1 = x0 - (fx/fxlinha);
            fx = funcao(x1);
        }
        raiz = x1;
    }else{
        raiz = x0;
    }

    printf("A raiz e: %f\n", raiz);
    printf("Numero de iteracoes: %d", k);

}
