// David Leonel Melo - 2021129559

#include <stdio.h>
#include "functions.h"


int vshuman(int game_mode, int load, int nMoves, pmove list)
{
    char **mat = createBoard(9,10);
    int board;
    int available_boards;
    int player;
    int pos;
    int wins = 0;
    int full;
    int ultimate_w = 0;
    int ctn;
    int loadMoves = nMoves;

    if(load == 1)
    {
        for(pmove aux = list; aux != NULL ; aux = aux->next)
        {
            InsertMove(mat, aux->board, aux->pos, aux->player);
            VerifyBoardWin(mat, aux->board, &wins, aux->pos);

            if(aux->next == NULL) {
                if(aux->player == 1)
                    player = 2;
                else 
                    player = 1;
                board = aux->pos - 1;
            }
                
        }

        for (int i = 0; i < (81 - loadMoves) , ultimate_w != 1; i++)
        {
            full = FullBoard(mat, board);
            available_boards = AvailableBoards(mat);

            if (available_boards == 0) {
                ultimate_w = Ultimate(mat);
                break;
            }

            if (full == 1 || mat[board][0] != ' ')
                do { board = RandomNumber(8); } while (FullBoard(mat, board) == 1 || mat[board][0] != ' ');


                PrintBoardFinal(mat);

                ctn = continueGame();

                if (ctn == 1) {

                    checkPrevious(nMoves, list);

                    PrintBoard(mat, board, player);

                    do {
                        printf("\n\nMove: ");
                        scanf("%d", &pos);
                        if (pos < 1 || pos > 9 || mat[board][pos] != ' ')
                            printf("\n(!) This move is illegal, try again.");
                    } while (mat[board][pos] != ' ' || pos < 1 || pos > 9);


                    InsertMove(mat, board, pos, player);

                    list = addMove(list, player, board, pos);
                    if(list == NULL)
                        return 7;

                    VerifyBoardWin(mat, board, &wins, pos);

                    if (available_boards != 1)
                        board = pos - 1;

                    ultimate_w = Ultimate(mat);

                    if (ultimate_w == 0)
                        SwitchPlayer(&player);
                }
                else{
                    expBin(list, game_mode);
                    return 0;
                }

            nMoves++;
        }

        if (ultimate_w == 1)
            printf("\n\nPLAYER %d WINS!\n", player);
        else
            printf("\n\nTHE GAME ENDED IN A DRAW!\n");

        PrintBoardFinal(mat);

        txtHelper(list);

        freeList(list);
    }

    else if(load == 0)
    {
        freeList(list);
        pmove l = NULL;

        do { board = RandomNumber(8); } while (board < 0 || board > 8);

        player = welcomeHuman(player);

        for (int i = 0; i < 81, ultimate_w != 1; i++) {
            full = FullBoard(mat, board);
            available_boards = AvailableBoards(mat);

            if (available_boards == 0) {
                ultimate_w = Ultimate(mat);
                break;
            }

            if (full == 1 || mat[board][0] != ' ')
                do { board = RandomNumber(8); } while (FullBoard(mat, board) == 1 || mat[board][0] != ' ');

            if (nMoves == 0) {
                PrintBoard(mat, board, player);

                do {
                    printf("\n\nMove: ");
                    scanf("%d", &pos);
                    if (pos < 1 || pos > 9 || mat[board][pos] != ' ') printf("\n(!) This move is illegal, try again.");
                } while (mat[board][pos] != ' ' || pos < 1 || pos > 9);


                InsertMove(mat, board, pos, player);

                l = addMove(l, player, board, pos);
                if(l == NULL)
                    return 7;

                if (available_boards != 1)
                    board = pos - 1;

                SwitchPlayer(&player);
            }

            if (nMoves > 0) {
                PrintBoardFinal(mat);

                ctn = continueGame();

                if (ctn == 1) {

                    checkPrevious(nMoves, l);

                    PrintBoard(mat, board, player);

                    do {
                        printf("\n\nMove: ");
                        scanf("%d", &pos);
                        if (pos < 1 || pos > 9 || mat[board][pos] != ' ')
                            printf("\n(!) This move is illegal, try again.");
                    } while (mat[board][pos] != ' ' || pos < 1 || pos > 9);


                    InsertMove(mat, board, pos, player);

                    l = addMove(l, player, board, pos);
                    if(l == NULL)
                        return 7;

                    VerifyBoardWin(mat, board, &wins, pos);

                    if (available_boards != 1)
                        board = pos - 1;

                    ultimate_w = Ultimate(mat);

                    if (ultimate_w == 0)
                        SwitchPlayer(&player);
                } else {
                    expBin(l, game_mode);
                    return 0;
                }
            }

            nMoves++;
        }

        if (ultimate_w == 1)
            printf("\n\nPLAYER %d WINS!\n", player);
        else
            printf("\n\nTHE GAME ENDED IN A DRAW!\n");

        PrintBoardFinal(mat);

        txtHelper(l);

        freeList(l);
    }

    return 0;
}
