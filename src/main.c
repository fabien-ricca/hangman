// main.c
#include <stdio.h>
#include <string.h>
#include "../header/check_arguments.h"
#include "../header/dico.h"



/**
 * <strong>Arguments :</strong><br>
 * arg[0] -> Nom du programme './hangman.exe' <br>
 * arg[1] -> fichier csv<br>
 * arg[2] -> difficulté<br>
 * arg[3] -> catégorie<br>
 */
int main(int argc, char *argv[]) {

    // On vérifie les arguments.
    if(checkArgs(argc, argv) == 1){
        return 1;
    }

    // On parcours le fichier csv.
    char **good_lines = NULL;
    int num_lines = readFile(argv, &good_lines);
    if (num_lines == 1){
        return 1;
    }

    // Si le fichier ne contient aucune ligne correcte.
    if(num_lines == 0){
        printf("%s\n", "invalid file.");
    }




    return 0;
}
