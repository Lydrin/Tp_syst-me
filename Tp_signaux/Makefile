CC = gcc
CFLAGS = -W -Wall -pedantic
LDFLAGS =
PERDUFLAG = -DMESSAGE='"perdu\n"'
OUPSFLAG = -DMESSAGE='"oups, encore perdu\n"'
EXEC = main
SRC = $(wildcard *.c) #définit la liste des .c du dossier
OBJ = $(SRC:.c=.o) #définit la liste des .o grâce aux .c dans le dossier


perdu: $(SRC)
	$(CC) -o $(EXEC) $(SRC) $(CFLAGS) $(PERDUFLAG)

oups: $(SRC)
	$(CC) -o $(EXEC) $(SRC) $(CFLAGS) $(OUPSFLAG)
