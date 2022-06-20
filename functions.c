// David Leonel Melo - 2021129559

#include "functions.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>


void InsertMove(char **mat,int board,int pos,int player)  // Coloca 'X' ou '0' na matriz, tendo em conta o jogador atual, correspondendo à jogada previamente validada
{
    if(player == 1) mat[board][pos] = 'X';

    else if(player == 2) mat[board][pos] = 'O';
}


void SwitchPlayer(int *player) // Troca o jogador da jogada seguinte, tendo em conta o atual
{
    switch (*player) {
        case 1:
            *player = 2;
            break;
        case 2:
            *player = 1;
            break;
    }
}

int RandomNumber(int max)
{
    int random;

    srand(time(NULL));

    do { random = rand(); }while(random > max);

    return random;
}

int special_character(char str[]) // Verifica a existência de caracteres inválidos na string utilizada para o ficheiro de texto
{
    int n = strlen(str);
    int flag = 0;

    for (int i = 0; i < n; ++i) {
        if (
            str[i] == '*'
            || str[i] == ':'
            || str[i] == '"'
            || str[i] == '<'
            || str[i] == '>'
            || str[i] == '/'
            || str[i] == '?'
            || str[i] == '|'
            )
            flag = 1;
    }

    if(flag == 1){
        printf("TXT file name is not allowed.\n:> ");
        return 1;
    }
    else
        return 0;
}







