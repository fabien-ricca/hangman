// main.c
#include <stdio.h>
//#include "../header/check_arguments.h"


void reverse(int *nbA, int *nbB){
    int temp = *nbB;
    *nbB = *nbA;
    *nbA = temp;

    printf("Nombre A : %d et Nombre B : %d\n", *nbA, *nbB);
}


/**
 * <strong>Arguments :</strong><br>
 * arg[0] -> Nom du programme './hangman.exe' <br>
 * arg[1] -> dictionnaire<br>
 * arg[2] -> Difficulté<br>
 * arg[3] -> Catégorie<br>
 */
int main(int argc, char *argv[]) {

//    checkArgs(argc, *argv);

    int nbA = 15;
    int nbB = 28;

    reverse(&nbA, &nbB);
    printf("Nombre A : %d et Nombre B : %d\n", nbA, nbB);




    return 0;
}
