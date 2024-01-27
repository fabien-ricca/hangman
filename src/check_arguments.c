// check_arguments.c
#include <stdio.h>
#include <string.h>
#include "../header/check_arguments.h"


int checkArgs(int argc, char *argv[]){
    if(checkNbArgs(argc) == 1){
        printf("%s\n", "Merci de saisir le bon nombre d'arguments.");
        return 1;
    }

    if(checkDifficult(argv[2]) == 1){
        printf("%s\n", "Merci de saisir une difficulté correcte.");
        return 1;
    }

    return 0;
}


// Vérifie le nombre d'arguments
int checkNbArgs(int nb){
    if( nb == 1 || nb == 4){
        return 0;
    }
    return 1;
}


// Vérifie que la difficulté passée est correcte
int checkDifficult(char *difficult){
    printf("%s\n", difficult);
    if(difficult == NULL){
        return 1;
    }
    if(strcmp(difficult, "facile") == 0){
        return 0;
    }

    if(strcmp(difficult, "moyen") == 0){
        return 0;
    }

    if(strcmp(difficult, "difficile") == 0){
        return 0;
    }

    return 1;
}