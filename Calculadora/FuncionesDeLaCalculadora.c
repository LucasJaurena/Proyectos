#include <stdio.h>
#include <stdlib.h>
#include "FuncionesDeLaCalculadora.h"

float pedirNumero()
{
    float numero;

    printf("\nIngrese un numero: ");
    scanf("%f",&numero);
    return numero;
}

float suma(float x,float y)
{
    float resultado;
    resultado = x + y;

    return resultado;
}

float resta(float x,float y)
{
    float resultado;
    resultado = x - y;

    return resultado;
}

float division(float x,float y)
{
    float resultado;
    resultado = x / y;

    return resultado;
}

float multiplicacion(float x,float y)
{
    float resultado;
    resultado = x * y;

    return resultado;
}

int factorial(int x)
{
    int i;
    int resultado = 1;

    for(i = x; i > 0; i--)
    {
        resultado = resultado * i;
    }

     return resultado;
}
