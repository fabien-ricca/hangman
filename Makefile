CC = gcc
CFLAGS = -Wall -Wextra -std=c99
FILE_EXEC = hangman.Exe
EXEC = hangman
SRCDIR = .
OBJDIR = obj

# Trouve tous les fichiers source dans les répertoires spécifiés
SRC = $(wildcard $(SRCDIR)/*.c)

# Génère les noms des fichiers objets à partir des fichiers source
OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D) # Crée le répertoire obj s'il n'existe pas
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJ)

fclean: clean

run: $(EXEC)
	./$(EXEC)