#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){

    pid_t pid1 = fork();
    if( pid1 == 0 ){
        sleep(3);
        printf("Je suis un fils et mon PID est : %d, et mon parent est %d\n",getpid(),getppid());
    }
    else{
        pid_t pid2 = fork();
        if( pid2 ==0 ){
            sleep(3);
            printf("Je suis un fils et mon PID est : %d, et mon parent est %d\n",getpid(),getppid());
        }
        else{
            printf("Je suis le père et mon PID est : %d, et mon parent est %d\n",getpid(),getppid());
            printf("J'attends la mort de mes fils\n");
            wait(0);
        }
    }
    return 0;
}
