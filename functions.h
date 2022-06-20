// David Leonel Melo - 2021129559

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AUX 9
#define N 10

#ifndef TIC_TAC_TOE_LIBRARY_H
#define TIC_TAC_TOE_LIBRARY_H

typedef struct play move, *pmove;
struct play{
    int player;
    int board;
    int pos;
    pmove next;
};

// GAME MODE FUNCTIONS
int vshuman(int game_mode, int load, int nMoves, pmove list);
int vsAI(int game_mode, int load, int nMoves, pmove list);

// BOARD FUNCTIONS
void freeBoard(char** p, int numRows);
char** createBoard(int numRows, int numCols);
int FullBoard(char **mat,int board);
int AvailableBoards(char **mat);
void PrintBoard(char **mat,int board,int player);
void PrintBoardFinal(char **mat);

// SIMPLE FUNCTIONS
void InsertMove(char **mat,int board,int pos,int player);
void SwitchPlayer(int *player);
int RandomNumber(int max);
int special_character(char str[]);

// WIN CONDITION FUNCTIONS
int VerifyBoardWin(char **mat,int board,int * wins,int pos);
int UltimateRow(char c,char **mat,int pos);
int UltimateCol(char c,char **mat,int pos);
int UltimateDiagonal(char c,char **mat,int pos);
int Ultimate(char **mat);

// PERSONAL ASSISTANT FUNCTIONS
int welcomeHuman(int player);
int welcomeAI(int player);
void checkPrevious(int nMoves, pmove p);
int continueGame();
int txtHelper(pmove p);

// LINKED LIST FUNCTIONS
void showInfo(pmove p);
int searchMove(pmove p , int nMoves , int c);
void moveRegister(pmove p, int player, int board, int pos);
pmove addMove(pmove p, int player, int board, int pos);
int freeList(pmove p);
int expTXT(pmove p, char* fn);
int expBin(pmove p, int game_mode);
pmove readList(int* nM, int* gm);


#endif //TIC_TAC_TOE_LIBRARY_H
