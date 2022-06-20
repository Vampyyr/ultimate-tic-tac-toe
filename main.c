// David Leonel Melo - 2021129559

#include <stdio.h>
#include "functions.h"

int main(void)
{
    printf(
            "\n\n"
            "============================================================="
            "\n"
            "                     ULTIMATE TIC TAC TOE                    "
            "\n"
            "============================================================="
            "\n\n\n"
            "|| GAME MODES ||\n\n"
            ">  [ PLAYER 1 VS PLAYER 2 ] - | 1 |\n\n"
            ">  [ PLAYER VS AI ] - | 2 |\n\n"
            ">  [ LOAD GAME ] - | 3 |\n\n"
            );

    int game_mode;
    int nMoves = 0;
    int * nM = &nMoves;
    int * gm = &game_mode;
    int load = 0;

    pmove list = NULL;

    do{ printf("\n:> "); scanf("%d",&game_mode); } while (game_mode < 1 || game_mode > 3);

    if(game_mode == 1)
        vshuman(game_mode, load , nMoves, list);
    else if(game_mode == 2)
        vsAI(game_mode, load , nMoves,list);
    else if(game_mode == 3)
    {
        list = readList(nM,gm);

        if(list == NULL)
            return 1;
        else
        {
            load = 1;

            if (game_mode == 1)
                vshuman(game_mode,load, nMoves, list);
            else if (game_mode == 2)
                vsAI(game_mode, load, nMoves, list);
        }
    }

    freeList(list);

    return 0;
}


