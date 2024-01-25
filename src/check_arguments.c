// check_arguments.c
#include <stdio.h>
#include <string.h>
#include "../header/check_arguments.h"


int checkArgs(int argc, char *argv){
    if(checkNbArgs(argc) == 1){
        printf("%s\n", "Merci de saisir le bon nombre d'arguments.");
        return 1;
    }

    if(checkDifficult(*argv[3]) == 1){
        printf("%s\n", "Merci de saisir une difficulté correcte.");
        return 1;
    }

    return 0;
}


int checkNbArgs(int nb){
    if( nb == 1 || nb == 4){
        return 0;
    }
    return 1;
}

int checkDifficult(char *difficult){
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