#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pid = fork();
    if (pid > 0) {
        printf("parent: child=%d\n", pid);
        wait(&pid);
        printf("child %d is done\n", pid);
    } 
    else if (pid == 0) {
        printf("child: exiting\n");
    } 
    else{
        printf("fork error\n");
    }
    return 0;
}