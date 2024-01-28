CC = gcc
EXEC = hangman				# Nom de l'exécutable qui sera créé
CFLAGS = -Wall -Werror -Wextra   # Flags de compilation par défaut
SRC = $(wildcard src/*.c)	# Tous les fichiers .c
OBJ = $(SRC:.c=.o)			# Comme SRC mais on remplace .c par .o


ifeq ($(OS),Windows_NT)
    CC = gcc
    EXEC := $(EXEC).exe
else
    # Paramètres de compilation pour Linux
endif

all : $(EXEC)

%.o : %.c	# Tous les fichiers .o : Tous les fichiers .c
	$(CC) $(CFLAGS) -o $@ -c $<

$(EXEC) : $(OBJ)
	$(CC) -o $@ $^
	cp src/*.o obj/
	rm -rf src/*.o

clean:
	rm -f obj/*.o

fclean: clean
	rm -f $(EXEC)

run: $(EXEC)
	./$(EXEC)
