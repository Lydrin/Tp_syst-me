#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){

    pid_t pid1 = fork();
    if(pid1==0){
        pid_t pid2 = fork();
        if(pid2==0){
            printf("Je suis le petit fils et mon pid est %d, et mon parent est %d \n",getpid(),getppid());
        }
        else{
            printf("Je suis le fils et mon pid est %d, et mon parent est %d \n", getpid(), getppid());
            wait(0);
        }
    }
    else{
        printf("Je suis le grand père et mon pid est %d, et mon parent est %d \n",getpid(),getppid());
        wait(0);
    }


    return 0;
}
