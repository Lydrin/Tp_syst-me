#include <stdio.h>
#include <unistd.h>

int main(void){
    printf("UID réel = %u, UID effectif = %u\n, ID groupe = %u",getuid(),geteuid(), getgid());
    return 0;
}
