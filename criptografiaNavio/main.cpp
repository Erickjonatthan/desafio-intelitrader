#include <iostream>
#include <cstring>
#include <cmath>

int converter(char *str)
{
    int result = 0;
    int expo = 0;
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        int a;
        if (str[i] == '1')
        {
            a = 1;
        }
        else
        {
            a = 0;
        }
        result += a * pow(2, expo);
        expo++;
    }
    return result;
}

int main()
{
    char valor[] = "10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001 00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011";
    
    // Remover todos os espaços em branco
    int posicao = 0;
    for (int i = 0; i < strlen(valor); i++)
    {
        if (valor[i] == ' ')
        {
            continue;
        }
        valor[posicao] = valor[i];
        posicao++;
    }

    valor[posicao] = '\0';

    // a cada 8 bits, os dois últimos estão invertidos
    int contador = 0;
    for (int i = 0; i < strlen(valor); i++)
    {
        contador++;
        if (contador == 8)
        {
            contador = 0;
            if (valor[i] == '1')
            {
                valor[i] = '0';
            }
            else
            {
                valor[i] = '1';
            }

            if (valor[i - 1] == '1')
            {
                valor[i - 1] = '0';
            }
            else
            {
                valor[i - 1] = '1';
            }
        }
    }

    // a cada 4 bits, os 4 bits foram trocados com os próximos 4
    int len = strlen(valor);
    for (int i = 0; i < len; i += 8)
    {
        for (int j = 0; j < 4; ++j)
        {
            valor[i + j] ^= valor[i + j + 4];
            valor[i + j + 4] ^= valor[i + j];
            valor[i + j] ^= valor[i + j + 4];
        }
    }

    // Exibir valores a cada 8 bits
    contador = 0;
    char temp[9];
    temp[8] = '\0';
    
    for (int i = 0; i < strlen(valor); i++)
    {
        temp[contador] = valor[i];
        contador++;
        if (contador == 8)
        {
            printf("%c", converter(temp));
            contador = 0;
        }
    }
}