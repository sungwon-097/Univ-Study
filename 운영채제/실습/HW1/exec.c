#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char *argv[3];
    argv[0] = "echo";
    argv[1] = "hello";
    argv[2] = 0;
    int pid = fork();

    if(pid > 0){
        wait(&pid);
    }
    else if (pid == 0) {
        execv("/bin/echo", argv);
    }
    else{
        printf("fork error\n");
    }
}