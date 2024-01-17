#include <iostream>
#include <limits.h>

int main()
{
    int array1[] = {44, 8, 94, 71, 25, 68, 39, 63, 1, -21};
    int array2[] = {30, 45, 90, 3, 22, 17, 40, 58, 4, -44};
    int distanciaMin = INT_MAX;
    int valora;
    int valorb;
    int tamanho1 = sizeof(array1)/sizeof(int);
    int tamanho2 = sizeof(array2)/sizeof(int);
    
    for (int i = 0; i < tamanho1; i++)
    {
        for (int j = 0; j < (sizeof(array2) / tamanho2); j++)
        {
            int distanc = abs(array1[i] - array2[j]);
            if (distanc < distanciaMin)
            {
                distanciaMin = distanc;
                valora = array1[i];
                valorb = array2[j];
            }
        }
    }
    printf("A menor distancia equivale a %d e corresponde aos valores %d e %d", distanciaMin, valora, valorb);
}