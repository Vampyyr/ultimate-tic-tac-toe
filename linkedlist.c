// David Leonel Melo - 2021129559

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showInfo(pmove p) // Ciclo que imprime todas as estruturas desde onde o ponteiro aux aponta até ao final da lista ligada
{   
    pmove aux = p;
    while(aux != NULL)
    {
        printf("\nPlayer %d moved in board %d position %d\n",
               aux->player, (aux->board)+1, aux->pos);
        aux = aux->next;
    }
}

int searchMove(pmove p , int nMoves , int n) // Move o ponteiro aux até à cota desejada e, utilizando a função showInfo(), imprime todas as estruturas até ao final da lista ligada
{   
    pmove paux = p;
    for(int aux = 0; paux != NULL && aux != nMoves-n; aux++)
        paux = paux->next;

    if(paux != NULL)
        showInfo(paux);
    else
        return 1;
}

void moveRegister(pmove p, int player, int board, int pos) // Regista as informações relativas à jogada atual na estrutura apontada pelo ponteiro p
{
    p->player = player;
    p->board = board;
    p->pos = pos;
    p->next = NULL;
}

pmove addMove(pmove p, int player, int board, int pos) // Adiciona uma nova estrutura no final da lista ligada
{
    pmove new, aux;
    new = malloc(sizeof(move));

    if(new == NULL)
    {
        printf("Memory allocation error.\n");
        freeList(p);
        return NULL;
    }

    moveRegister(new, player, board, pos);

    if(p == NULL)
        p = new;
    else
    {
        aux = p;
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = new;
    }
    return p;
}

int freeList(pmove p) // Liberta toda a lista ligada
{
    pmove aux;
    while(p != NULL)
    {
        aux = p;
        p = p->next;
        free(aux);
    }
    return 0;
}

int expTXT(pmove p, char* fn) // Exporta todas as jogadas da partida registadas na lista ligada para um ficheiro de texto com nome escolhido pelo utilizador
{
    FILE *f;
    f = fopen(fn, "w");

    if(f==NULL){ fclose(f); return 0;}
    else{
        while(p != NULL){
            fprintf(f, "Player %d moved in board %d position %d\n\n", p->player, (p->board)+1, p->pos);
            p = p->next;
        }
        fclose(f);
    }

    return 1;
}

int expBin(pmove p, int game_mode) // Exporta o modo de jogo e todas as jogadas registadas na lista ligada para um ficheiro binário
{
    FILE *f;
    f = fopen("jogo.bin", "wb+");

    if(f==NULL){ fclose(f); return 0;}
    else{
        fwrite(&game_mode , sizeof(int) , 1 , f);
        for(pmove aux = p; aux != NULL; aux = aux->next)
            fwrite(aux, sizeof(move), 1, f);
        fclose(f);
    }

    return 1;
}


pmove readList(int* nM, int* gm) // Recupera o modo de jogo e regista todas as jogadas da partida anterior numa nova lista ligada
{
    pmove list = NULL;
    pmove new;
    pmove aux;
    
    move newAux;

    FILE* f = fopen("jogo.bin", "rb");
    if(f == NULL) {
        fclose(f);
        printf("*FILE DOESN´T EXIST*\n");
        freeList(list);
        return NULL;
    }

    fread(gm, sizeof(int), 1, f);

    while(fread(&newAux, sizeof(move), 1, f))
    {
        new = malloc(sizeof(move));

        if(new == NULL) {
            freeList(list);
            return NULL;
        }

        new->next = NULL;

        *new = newAux;

        if(list == NULL) {
            list = new;
            aux = list;
        }else {
            aux->next = new;
            aux = aux->next;
        }
        (*nM)++;
    }
    fclose(f);
    return list; // Devolve a lista ligada com todas as jogadas da partida anterior
}