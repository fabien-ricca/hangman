// main.c
#include <stdio.h>
#include <string.h>
#include "../header/check_arguments.h"
#include "../header/dico.h"
#include "../header/game.h"



/**
 * <strong>Arguments :</strong><br>
 * arg[0] -> Nom du programme './hangman.exe' <br>
 * arg[1] -> fichier csv<br>
 * arg[2] -> difficulté<br>
 * arg[3] -> catégorie<br>
 */
int main(int argc, char *argv[]) {
    printf("\n");

    // On vérifie les arguments.
    if(checkArgs(argc, argv) == 1){
        return 1;
    }

    // On parcours le fichier csv et on établie la liste de lignes utilisables.
    char *good_lines[1000];
    int num_lines = readFile(argc, argv, good_lines);
    if (num_lines == 1){
        return 1;
    }

    // Si le fichier ne contient aucune ligne correcte.
    if(num_lines == 0){
        printf("!!! invalid file. !!!\n");
    }


    printf("%s\n", "GOOD_LINES :");
    for (int i = 0; i < num_lines; i++) {
        printf("Ligne %d : %s\n", i, good_lines[i]);
    }

    //Si la liste n'est pas vide.
    start(argc, argv, num_lines);

    return 0;
}
