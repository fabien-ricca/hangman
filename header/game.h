// game.h
#ifndef GAME_H
#define GAME_H

void start(int num_lines, char *good_lines[]);

char* selectWord(int num_lines, char *good_lines[]);

int printGame(int error, int life, char **tokens, char* printWord);

char* initPrintWord(char **tokens);

int checkInput(char *input, char *wordToGuess, char *printWord);

int checkWord(char *wordToGuess, char *wordToVerify);

int replay();


#endif