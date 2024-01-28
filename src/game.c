#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../header/game.h"
#include "../header/dico.h"


void start(int num_lines, char *good_lines[]) {
    printf("\n\nLancement du jeu...\n");
    printf("------------------------------------------------------\n");

    int error = 0;
    int life = 3;
    char **tokens = splitLine(selectWord(num_lines, good_lines)); // 0:mot  1:catégorie  2:difficulté
    char *printWord = initPrintWord(tokens);
    char input[100];

    while (error < 6 || life > 0) {
        printGame(error, life, tokens, printWord);

        if(error == 6 || life == 0){
            printf("Dommage, c'est perdu.");
            break;
        }

        printf("\nVeuillez saisir une lettre ou une chaîne de caractères : ");
        fflush(stdout); // Vide le tampon de sortie
        fgets(input, sizeof(input), stdin); // L'utilisateur saisit sa proposition.

        // Supprime le saut de ligne s'il existe.
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Si le joueur saisi un mot entier.
        if(input[0] == '/'){
            memmove(input, input + 1, strlen(input));
            if(checkWord(tokens[0], input) == 1){
                life--;
                continue;
            }
            else{
                printf("Félicitation ! vous avez gagné !");
                break;
            }
        }

        // Si le joueur ne saisit qu'une seule lettre.
        if(checkInput(input, tokens[0], printWord) != 1){
            error++;
            continue;
        }

        // On vérifie si le mot à été trouvé.
        if(checkWord(tokens[0], printWord) == 0){
            printf("Félicitation ! vous avez gagné !");
            break;
        }
    }
}


//Fonction qui va sélectionner le mot pour la partie.
char* selectWord(int num_lines, char *good_lines[]){

    srand(time(NULL));
    int nb = rand() % (num_lines);

    return good_lines[nb];
}


// Crée le mot à afficher.
char* initPrintWord(char **tokens){
    int length = strlen(tokens[0]);
    char* printWord = (char*)malloc(length + 1);

    for(int i = 0; i<length; i++){
        if(i == 0 || i == length-1 || tokens[0][i] == '\'' || tokens[0][i] == '-' ){
            printWord[i] = tokens[0][i];
        }
        else if(tokens[0][i] == ' '){
            printWord[i] = ' ';
        }
        else{
            printWord[i] = '_';
        }
    }
    printWord[length] = '\0';

    return printWord;
}


// Gère l'affichage du jeu.
int printGame(int error, int life, char **tokens, char* printWord){
    printf("\n\n\n\n");
    printf("Categorie  : %s\n", tokens[1]);
    printf("Difficulte : %s\n\n", tokens[2]);
    printf("Vies :");

    for(int i=0; i<life; i++){
        printf(" ♥ ");
    }




    if(error == 6 || life == 0){
        printf("\n\n");
        printf("    ------\n");
        printf("     |   |\n");
        printf("     0   |\n");
        printf("    /|\\  |        GAME OVER\n");
        printf("    / \\  |\n");
        printf("         |\n");
        printf("  --------       Solution : %s\n", tokens[0]);
        return 0;
    }


    if(error == 0){
        printf("\n\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("                 %s\n", printWord);
        return 0;
    }


    if(error == 1){
        printf("\n\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("  --------       %s\n", printWord);
        return 0;
    }


    if(error == 2){
        printf("\n\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("  --------       %s\n", printWord);
        return 0;
    }


    if(error == 3){
        printf("\n\n");
        printf("    ------\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("  --------       %s\n", printWord);
        return 0;
    }


    if(error == 4){
        printf("\n\n");
        printf("    ------\n");
        printf("     |   |\n");
        printf("     0   |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("  --------       %s\n", printWord);
        return 0;
    }


    if(error == 5){
        printf("\n\n");
        printf("    ------\n");
        printf("     |   |\n");
        printf("     0   |\n");
        printf("    /|\\  |\n");
        printf("         |\n");
        printf("         |\n");
        printf("  --------       %s\n", printWord);
        return 0;
    }

    return 0;
}


// Verifie la lettre saisie par l'utilisateur.
int checkInput(char *input, char *word, char *printWord) {
    int found = 0;
    char letter = input[0];

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == letter) {
            printWord[i] = letter;
            found = 1;
        }
    }

    return found;
}


// Comparaison avec le mot à trouver.
int checkWord(char *wordToGuess, char *wordToVerify){
    if(strcmp(wordToGuess, wordToVerify) == 0){
        return 0;
    }
    return 1;
}


// Demande au joueur s'il souhaite rejouer.
int replay(){
    char letter;
    printf("\nSouhaitez-vous rejouer (y/n) ? ");
    fflush(stdout); // Vide le tampon de sortie
    scanf(" %c", &letter);


    if(letter == 'y'){
        return 0;
    }

    return 1;
}