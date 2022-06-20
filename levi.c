// David Leonel Melo - 2021129559

#include <stdio.h>
#include <string.h>
#include "functions.h"

int welcomeHuman(int player) { // Decide quem começa a jogar de uma forma interativa e completamente aleatória (1 vs 1)

    int guess;
    int think;

    do { player = RandomNumber(2);}  while (player < 1 || player > 2);

    printf("\n"
           "Levi:\n"
           "> Welcome to Ultimate Tic Tac Toe!\n"
           "> I´m Levi, your personal assistant.\n"
           "> First we should figure out who moves first...\n"
           "> Player %d, is the number I´m thinking 1 or 2? \n\n"
           ":> ", player);

    do{
        scanf("%d", &guess);
        if(guess > 2 || guess < 1)
            printf("\n(!) Invalid guess, try again\n:> ");
    }while(guess > 2 || guess < 1);

    do { think = RandomNumber(2); } while (think < 1 || think > 2);

    printf("\nLevi:");
    if (guess != think) {
        SwitchPlayer(&player);
        printf("\n> Sorry! I was thinking about number %d\n"
               "> Player %d starts the game!\n\n"
               "> Good luck to both of you! :)\n", think, player);
    } else
        printf("\n> Correct! I was thinking about number %d.\n"
               "> Player %d starts the game.\n\n"
               "> Good luck to both of you! :)\n", think, player);

    return player;
}

int welcomeAI(int player) { // Decide quem começa a jogar de uma forma interativa e completamente aleatória (1 vs AI)

    int guess;
    int think;

    printf("\n"
           "Levi:\n"
           "> Welcome to Ultimate Tic Tac Toe!\n"
           "> I´m Levi, your personal assistant.\n"
           "> First we should figure out who moves first...\n"
           "> Is the number I´m thinking 1 or 2? \n\n"
           ":> ");

    do{
        scanf("%d", &guess);
        if(guess > 2 || guess < 1)
            printf("\n(!) Invalid guess, try again\n:> ");
    }while(guess > 2 || guess < 1);

    do { think = RandomNumber(2);}  while (think < 1 || think > 2);

    printf("\nLevi:");
    if(guess != think) {
        SwitchPlayer(&player);
        printf("\n> Sorry! I was thinking about number %d\n"
               "> AI starts the game!\n\n"
               "> Good luck! :)\n",think);
    }
    else
        printf("\n> Correct! I was thinking about number %d.\n"
               "> YOU start the game.\n\n"
               "> Good luck! :)\n",think);

    return player;
}

int continueGame(){ // Verifica se o jogador quer continuar ou interromper o jogo
    int n;

    printf("\n\nLevi:\n"
           "(1) CONTINUE\n"
           "(2) STOP GAME\n"
           ":> ");

    do{
            scanf("%d",&n); if(n > 2 || n < 1)
            printf("\n(!) Invalid option, try again\n:> ");
    } while(n<1 || n>2);

    if(n==2){
        printf("Levi:\n"
               "> Can´t wait to see you again!\n");
        return 0;
    }
    else
        return 1;
}

void checkPrevious(int nMoves, pmove p) { // Verifica se o jogador quer visualizar alguma jogada anterior
    char c;
    int n;

    printf("Levi:\n"
           "> Do you wish to check any previous move(s)? [Y] [N]\n"
           ":> ");
    do {
        scanf(" %c", &c);
        if(c != 'y' && c != 'Y' && c != 'n' && c != 'N')
            printf("(!) Invalid Option, try again\n:> ");
    }while(c != 'y' && c != 'Y' && c != 'n' && c != 'N');

    if(c == 'Y' || c == 'y') {
        printf("How many moves do you want to check?\n"
               ":> ");
        do {
            scanf("%d", &n);
            if (n <= 0 || n > nMoves || n > 10)
                printf("(!) Try again:\n:> ");

        } while (n <= 0 || n > nMoves || n > 10);

        searchMove(p, nMoves, n);
    }
}

int txtHelper(pmove p) { // Recolhe o nome do ficheiro de texto ao utilizador, verifica a sua viabilidade e, então, exporta para o ficheiro de texto recorrendo a expTXT()

    char fname[254];
    int x;

    printf("\nLevi:\n"
           "> Enter .txt file name:\n"
           ":> ");
    do {
        scanf("%123s", fname);
        x = special_character(fname);
    } while( x == 1);

    strcat(fname,".txt");

    char * fn = fname;

    expTXT(p,fn);

    return 0;
}
