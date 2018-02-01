#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int main( int argc, char ** argv )
{

	// Création/Ouverture du fichier
	int file = open("liste.txt", O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);	

	// Création du pipe
	int pfd[2];

	if (pipe(pfd) == -1)
	{
		printf("Echec de la création du pipe\n");
		return 1;
	}

	// Création du processus fils
	int pid = fork();
	if (pid < 0)
	{
		printf("Echec du fork\n");
		return 1;
	}

	if (pid == 0) // Process cut
	{
		// Processus fils
		close(pfd[1]); // On ferme l'écriture du pipe coté enfant
		dup2(pfd[0], 0); // On connecte la sortie du pipe sur stdin du processus wc
		close(pfd[0]); // Une fois reliée, on peut fermer la sortie
		dup2(file,1);
		execlp("cut", "cut", "-f5", "-d:", NULL);
		return 1;
	}
	else // Process grep
	{
		// Processus parent
		close(pfd[0]); // On ferme la lecture du pipe coté parent
		dup2(pfd[1], 1); // On connecte l'entrée du pipe sur la sortie stdout du process ls
		close(pfd[1]); // Une fois reliée, on peut fermer l'entrée
		execlp("grep", "grep", "nobody", "/etc/passwd", NULL);
		wait(0);
		return 1;
	}

	return 0;
	
}
