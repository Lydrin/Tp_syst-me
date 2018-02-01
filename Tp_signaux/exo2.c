#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


struct sigaction action;

void hand(int sig){

	if(sig == SIGINT || sig == SIGQUIT){
		printf("Sig : %d\n",sig);
		exit(sig);
	}

}

int main(void){
	
	action.sa_handler = hand;
	sigaction(SIGINT, &action, NULL);
	sigaction(SIGQUIT, &action, NULL);
	while(1);
	
}
