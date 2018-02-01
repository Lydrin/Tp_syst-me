#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define N 50

int id(char*);

int main( int argc, char ** argv )
{
    char entree[N];
    char chemin[N];
    for(;;){
        printf("%s@%s >> ",getlogin(),getcwd(chemin,N));
        scanf("%s\n",entree);
        switch(id(entree)){
            case 1:
                printf("Ceci est un ls !\n");
            break;
            default:
                printf("Commande inconnue, pour plus d'info, voir le man\n");
            break;
        }
    }
    return 0;
}


int id(char* s){
    if(strcmp(s,"ls")==0){
        return 1;
    }
    else{
        return -1;
    }
}

