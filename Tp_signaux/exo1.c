#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


struct sigaction action;

void hand(int sig){

	if(sig == SIGINT){
		printf(MESSAGE);
		exit(SIGINT);
	}

}

int main(void){
	
	action.sa_handler = hand;
	sigaction(SIGINT, &action, NULL);
	while(1);
	
}
