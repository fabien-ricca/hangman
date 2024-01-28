// dico.h
#ifndef DICO_H
#define DICO_H

int readFile(int argc, char *argv[], char *good_lines[]);

int isFileExist(char *name);

char** splitLine(char *line_copy);

int checkLine(char **tokens);

int isLineCompliant(int argc, char *argv[], char **tokens);

#endif