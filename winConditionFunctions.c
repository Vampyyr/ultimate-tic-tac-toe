// David Leonel Melo - 2021129559

#include "functions.h"


int VerifyBoardWin(char **mat,int board,int * wins,int pos) // Verifica todas as condições de vitória nos tabuleiros inferiores, caso haja vitória num deles, o caracter correspondente ao jogador que ganhou ('X' ou 'O') é guardado em [board][0], sendo "board" o tabuleiro onde o jogador venceu
{
    char c = mat[board][pos];

    int row = 0;

    if(pos <= 3)
        if(mat[board][pos + 3] == c && mat[board][pos + 6] == c )
            mat[board][0] = c;

    if(pos > 3 && pos <= 6)
        if(mat[board][pos - 3] == c && mat[board][pos + 3] == c)
            mat[board][0] = c;

    if(pos > 6 && pos <= 9)
        if(mat[board][pos - 3] == c && mat[board][pos - 6] == c)
            mat[board][0] = c;

    if(pos <= 3)
    {
        for (int i = 1; i <= 3; i++)
        {
            if (mat[board][i] != c)
                break;
            else
                row += 1;
        }

        if (row == 3)
            mat[board][0] = c;
    }

    if(pos > 3 && pos <= 6)
    {
        for(int i = 4; i <= 6; i++)
        {
            if(mat[board][i] != c)
                break;
            else
                row += 1;
        }

        if(row == 3)
            mat[board][0] = c;
    }

    if(pos > 6 && pos <= 9)
    {
        for(int i = 7; i <= 9; i++)
        {
            if(mat[board][i] != c)
                break;
            else
                row += 1;
        }

        if(row == 3)
            mat[board][0] = c;
    }


    if(pos == 1)
        if(mat[board][pos + 4] == c && mat[board][pos + 8] == c )
            mat[board][0] = c;

    if(pos == 5)
        if(mat[board][pos - 4] == c && mat[board][pos + 4] == c )
            mat[board][0] = c;

    if(pos == 9)
        if(mat[board][pos - 4] == c && mat[board][pos - 8] == c )
            mat[board][0] = c;

    if(pos == 3)
        if(mat[board][pos + 2] == c && mat[board][pos + 4] == c )
            mat[board][0] = c;

    if(pos == 5)
        if(mat[board][pos + 2] == c && mat[board][pos - 2] == c )
            mat[board][0] = c;

    if(pos == 7)
        if(mat[board][pos - 2] == c && mat[board][pos - 4] == c )
            mat[board][0] = c;

    if(mat[board][0] == c)
        return 1;
    else
        return 0;
}


int UltimateRow(char c,char **mat,int pos) // Verifica a existência de vitória nas linhas do tabuleiro Ultimate, caso se verifique esta condição, a variável win é colocada a 1
{
    int row = 0;
    int win = 0;

    if(pos <= 2)
    {
        for(int i = 0; i <= 2; i++)
        {
            if(mat[i][0] != c)
                break;
            else
                row += 1;

        }

        if(row == 3)
            win = 1;
    }


    if(pos > 2 && pos <= 5)
    {
        for(int i = 3; i <= 5; i++)
        {
            if(mat[i][0] != c)
                break;
            else
                row += 1;

        }

        if(row == 3)
            win = 1;
    }


    if(pos > 5 && pos <= 8)
    {
        for(int i = 6; i <= 8; i++)
        {
            if(mat[i][0] != c)
                break;
            else
                row += 1;

        }

        if(row == 3)
            win = 1;
    }

    if(win == 1)
        return 1;
    else
        return 0;
}

int UltimateCol(char c,char **mat,int pos) // Verifica a existência de vitória nas colunas do tabuleiro Ultimate, caso se verifique esta condição, a variável win é colocada a 1
{
    int win = 0;

    if(pos <= 3)
        if(mat[pos + 3][0] == c && mat[pos + 6][0] == c )
            win = 1;


    if(pos > 3 && pos <= 6)
        if(mat[pos - 3][0] == c && mat[pos + 3][0] == c)
            win = 1;


    if(pos > 6 && pos <= 9)
        if(mat[pos - 3][0] == c && mat[pos - 6][0] == c)
            win = 1;


    if(win == 1)
        return 1;
    else
        return 0;
}


int UltimateDiagonal(char c,char **mat,int pos) // Verifica a existência de vitória nas diagonais do tabuleiro Ultimate, caso se verifique esta condição, a variável win é colocada a 1
{
    int win = 0;

    if(pos == 0)
        if(mat[pos + 4][0] == c && mat[pos + 8][0] == c )
            win = 1;

    if(pos == 4)
        if(mat[pos - 4][0] == c && mat[pos + 4][0] == c )
            win = 1;

    if(pos == 8)
        if(mat[pos - 4][0] == c && mat[pos - 8][0] == c )
            win = 1;



    if(pos == 2)
        if(mat[pos + 2][0] == c && mat[pos + 4][0] == c )
            win = 1;


    if(pos == 4)
        if(mat[pos + 2][0] == c && mat[pos - 2][pos - 2] == c )
            win = 1;


    if(pos == 6)
        if(mat[pos - 2][0] == c && mat[pos - 4][0] == c )
            win = 1;


    if(win == 1)
        return 1;
    else
        return 0;
}


int Ultimate(char **mat) // Verifica, utilizando as funções UltimateRow(), UltimateCol() e UltimateDiagonal(), se o jogador ganhou a partida, devolve 1 se sim e 0 se não
{
    int win = 0;

    char c1 = 'X';
    char c2 = 'O';
    int pos_x;
    int pos_o;

    for(int i = 0; i < 9; i++)
    {
        if(mat[i][0] == 'X')
        {
            pos_x = i;
            if(UltimateRow(c1,mat,pos_x) == 1 || UltimateCol(c1,mat,pos_x) == 1 || UltimateDiagonal(c1,mat,pos_x) == 1)
            {
                win = 1;

                break;
            }
        }

        if(mat[i][0] == 'O')
        {
            pos_o = i;
            if(UltimateRow(c2,mat,pos_o) == 1 ||UltimateCol(c2,mat,pos_o) == 1 || UltimateDiagonal(c2,mat,pos_o) == 1)
            {
                win = 1;
                break;
            }
        }
    }


    if(win == 1)
        return 1;
    else
        return 0;
}
