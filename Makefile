CC = gcc
EXEC = hangman				# Nom de executable qui sera créé
CFLAGS = -Wall -Werror -Wextra   # Flags de compilation
SRC = $(wildcard src/*.c)	# Tous les fichiers .c
OBJ = $(SRC:.c=.o)			# Comme SRC mais on remplace .c par .o


all : $(EXEC)

%.o : %.c	# Tous les fichiers .o : Tous les fichiers .c
	$(CC) $(CFLAGS)  -o $@ -c $<

$(EXEC) : $(OBJ)
	$(CC) -o $@ $^
	cp src/*.o obj/
	rm -rf src/*.o


