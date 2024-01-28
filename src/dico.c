// dico.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/dico.h"
#include "../header/check_arguments.h"


int readFile(char *argv[], char *good_lines[]){

    FILE *file = (isFileExist(argv[1]) == 0) ? fopen(argv[1], "r") : fopen("dico.csv", "r") ;

    char line[1000];
    int nb = 0;
    int num_lines = 0;
    while (fgets(line, sizeof(line), file) != NULL) {   // expliquer
        nb++;

        // Supprimer le saut de ligne s'il existe
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        if (line[0] == '#'){
            continue;
        }

        char *line_copy = strdup(line); // Crée une copie de la ligne
        char **tokens = splitLine(line_copy);

        if(checkLine(tokens) == 1){
            printf("error on line %d : \"%s\"\n", nb, line);
            continue;
        }

        good_lines[num_lines] = strdup(line);
        num_lines++;

    }

    fclose(file);
    return num_lines;
}

// Vérifie si le dictionnaire passé en argument existe
int isFileExist(char *name){
    FILE *file = fopen(name, "r");

    if(file){
        fclose(file);
        return 0;
    }

    return 1;
}


// Sépare la ligne courante en 3 tokens
char** splitLine(char *line_copy) {
    char *token = strtok(line_copy, ",");
    char** tokens = malloc(3 * sizeof(char*));

    // Vérifie si l'allocation de mémoire a réussi
    if (tokens == NULL) {
        perror("Erreur d'allocation mémoire");
        exit(EXIT_FAILURE);
    }

    // Token 'mot'
    if (token != NULL) {
        tokens[0] = strdup(token);

        token = strtok(NULL, ",");
        // Token 'catégorie'
        if (token != NULL) {
            tokens[1] = strdup(token);

            token = strtok(NULL, ",");
            // Token 'difficulté'
            if (token != NULL) {
                tokens[2] = strdup(token);
            }else{
                tokens[2] = "";
            }
        }else{
            tokens[1] = "";
        }
    }else{
        tokens[0] = "";
    }

    return tokens;
}


// Effectue les vérifications pour déterminer si la ligne est utilisable
int checkLine(char **tokens){

    if(checkDifficult(tokens[2]) == 1){
        return 1;
    }

    return 0;
}