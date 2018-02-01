#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define N 50

int main( int argc, char ** argv )
{
    int fd[2];
    if(pipe(fd) == -1){
        printf("Pipe error\n");
        return 1;
    }
    int pidfils1 = fork();
    if(pidfils1 == 0){ //Fils 1, doit lire sur l'entrée standard une suite d'entier qui se termine par 0 et transmet les entiers paires au fils2
        int nombre1 = 0;
        close(fd[0]);
        do{
            scanf("%d",&nombre1);
            write(fd[1],(int*)&nombre1,sizeof(int));
        }while(nombre1!=0);
        write(fd[1],(int*)&nombre1,sizeof(int));
        return 0;
    }    
    else{
        int pidfils2 = fork();
        if(pidfils2 == 0){
            int nombre2 = 0;
            close(fd[1]);
            do{
                read(fd[0],(int*)&nombre2,sizeof(int));
                if((nombre2 %2) == 0){
                    printf("%d\n",nombre2);
                }
            }while(nombre2!=0);
            return 0;
        }
        else{
            close(fd[1]);
            close(fd[0]);
            wait(0);
            printf("Fin du programme\n");
            return 0;
        }
    }
}
