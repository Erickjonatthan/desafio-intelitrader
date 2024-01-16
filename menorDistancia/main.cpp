#include <iostream>
#include <limits.h>

int main()
{
    int array1[] = {44, 8, 94, 71, 25, 68, 39, 63, 1, -21};
    int array2[] = {30, 45, 90, 3, 22, 17, 40, 58, 4, -44};
    int distanciaMin = INT_MAX;
    int valora;
    int valorb;
    int t = sizeof(int);
    for (int i = 0; i < (sizeof(array1) / t); i++)
    {
        for (int j = 0; j < (sizeof(array2) / t); j++)
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
    printf("A menor distancia eh de %d e correspode aos valores %d e %d", distanciaMin, valora, valorb);
}