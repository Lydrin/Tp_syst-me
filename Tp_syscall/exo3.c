#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define N 20

int main(void){
    char fichier[N];
    scanf("%s",&fichier);
    pid_t pid1 = fork();
    if(pid1==0){
        int X = open("./result.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
        if(X == -1){
            printf("An error has occured !\n");
            return 1;
        }
        else{
            dup2(X,1);
            execlp("wc","wc", "-l", fichier, NULL);
            close(X);
        }
    }
    else{
        wait(0);
    }
    return 0;
}
