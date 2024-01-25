// main.c
#include <stdio.h>
#include "../header/check_arguments.h"



/**
 * <strong>Arguments :</strong><br>
 * arg[0] -> Nom du programme './hangman.exe' <br>
 * arg[1] -> dictionnaire<br>
 * arg[2] -> Difficulté<br>
 * arg[3] -> Catégorie<br>
 */
int main(int argc, char *argv[]) {

    checkArgs(argc, *argv);

    return 0;
}
