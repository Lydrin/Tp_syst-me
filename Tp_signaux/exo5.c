#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <sys/stat.h> 

struct sigaction actionpere;
struct sigaction actionfils;

sigset_t ens1;
sigset_t ens2;
pid_t pid;
int somme;
int pfd[2];

void handpere(int sig){

	if(sig == SIGINT){
		kill(pid, SIGTERM);
	}
	
	return;

}

void handfils(int sig){

	if(sig == SIGTERM){
		close(pfd[0]);
		write(pfd[1],(int*)&somme,sizeof(int));
		close(pfd[0]);
		exit(sig);
	}
	
	return;

}

int main(void){
	
	if (pipe(pfd) == -1)
	{
		printf("Echec de la création du pipe\n");
		return 1;
	}
	pid = fork();
	if(pid == 0){
		actionfils.sa_handler = handfils;
		sigaction(SIGTERM, &actionfils, NULL);
		sigemptyset(&ens2);
		sigaddset(&ens2,SIGINT);
		sigprocmask(SIG_SETMASK, &ens2, NULL);
		somme = 0;
		srand(time(NULL));
		while(1){
			somme+=rand()%11;
			sleep(1);
		}
	}
	else{
		actionpere.sa_handler = handpere;
		sigaction(SIGINT, &actionpere, NULL);
		wait(NULL);
		close(pfd[1]);
		int todisp = 0;
		read(pfd[0],(int*)&todisp,sizeof(int));
		printf("Somme : %d\n",todisp);
		close(pfd[0]);
	}
	return 0;
	
}
