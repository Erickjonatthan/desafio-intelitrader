#include <iostream>
#include <cstring>
#include <cmath>


//função para converter 8 bits em um numero decimal
int converter(char *str)
{
    int result = 0;
    int expo = 0;

    // percorre a string de trás para frente
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
    
    // Passo 1: Remover todos os espaços em branco
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

    // Passo 2: A cada 8 bits, os dois últimos estão invertidos
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

    // Passo 3: A cada 4 bits, os 4 bits foram trocados com os próximos 4
    int index = 0;
    for (int i = 0; i < int(strlen(valor) / 8); i++)
    {
        index = i * 8;
        char temp1 = valor[index];
        char temp2 = valor[index + 1];
        char temp3 = valor[index + 2];
        char temp4 = valor[index + 3];
        valor[index] = valor[index + 4];
        valor[index + 1] = valor[index + 5];
        valor[index + 2] = valor[index + 6];
        valor[index + 3] = valor[index + 7];
        valor[index + 4] = temp1;
        valor[index + 5] = temp2;
        valor[index + 6] = temp3;
        valor[index + 7] = temp4;
    }

    // Passo 4: Exibir codigo descriptografado

    // cria um array temporário para armazenar os 8 bits
    char temp[9];
    temp[8] = '\0';
    
    // a cada 8 bits exibe o valor convertido
    contador = 0;
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