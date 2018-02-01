#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


struct sigaction action;
sigset_t ens1;

void hand(int sig){

	if(sig == SIGINT){
		printf("1\n");
		sigemptyset(&ens1);
		sigaddset(&ens1, SIGQUIT);
		sigprocmask(SIG_SETMASK, &ens1, NULL);
		sleep(10);
		sigemptyset(&ens1);
		sigprocmask(SIG_SETMASK, &ens1, NULL);
	}
	
	return;

}

int main(void){
	
	action.sa_handler = hand;
	sigaction(SIGINT, &action, NULL);
	while(1){printf("0\n");}
	
}
