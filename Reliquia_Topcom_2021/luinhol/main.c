#include <stdio.h>
#include <stdlib.h>

void AtualizaPainelVazio(int mat[5][20])
{
    int l = 0, c = 0, led = 0;

    for (l = 0; l < 5; l++)
    {
        for (c = 0; c < 20; c++)
        {
            if (mat[l][c] == 'X')
            {
                mat[l][c-1] = 'X';
                mat[l][c] = '-';
            }
        }
    }
}

void AtualizaPainelCom1(int mat[5][20])
{
    int l = 0, c = 0;

    for (l = 0; l < 5; l++)
    {
        for (c = 0; c < 20; c++)
        {
            if (mat[l][c] == 'X')
            {
                mat[l][c-1] = 'X';
                mat[l][c] = '-';
            }
        }
    }

    for (l = 0; l < 5; l++)
    {
        mat[l][19] = 'X';
    }
}

void AtualizaPainelCom0(int mat[5][20])
{
    int l = 0, c = 0;

    for (l = 0; l < 5; l++)
    {
        for (c = 0; c < 20; c++)
        {
            if (mat[l][c] == 'X')
            {
                mat[l][c-1] = 'X';
                mat[l][c] = '-';
            }
        }
    }

    mat[0][19] = 'X';
    mat[4][19] = 'X';

}

void AtualizaPainelComTraco(int mat[5][20])
{
    int l = 0, c = 0;

    for (l = 0; l < 5; l++)
    {
        for (c = 0; c < 20; c++)
        {
            if (mat[l][c] == 'X')
            {
                mat[l][c-1] = 'X';
                mat[l][c] = '-';
            }
        }
    }

    mat[2][19] = 'X';
}

void CriaMatriz()
{
    int l = 0, c = 0;
    int mat[5][20];

    for (l = 0; l < 5; l++)
    {
        for (c = 0; c < 20; c++)
        {
            mat[l][c] = '-';
        }
    }
}