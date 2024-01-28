#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../header/game.h"
#include "../header/dico.h"


void start(int argc, char *argv[], int num_lines){
    printf("\n\nLancement du jeu...\n");
    printf("%s\n", selectWord(argc, argv, num_lines));


}


//Fonction qui va sélectionner le mot pour la partie.
char* selectWord(int argc, char *argv[], int num_lines){

    srand(time(NULL));
    int nb = rand() % (num_lines+1);

    char *line_copy = strdup(argv[nb]); // Crée une copie de la ligne
    char **tokens = splitLine(line_copy);


    printf("Token 1: %s // Token 2: %s // Token 3: %s.", tokens[0], tokens[1], tokens[2]);


    if(argc == 4 && num_lines != 0 && argv[0] != NULL){
        return "Une difficulte et une categorie sont presentes.";
    }



    return "aucune difficulte ou categorie.";
}
