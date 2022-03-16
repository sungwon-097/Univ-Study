#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char buf[100];

void cat(int fd)
{
    int n;
    while((n = read(fd, buf, sizeof(buf))) > 0) {
        if (write(STDIN_FILENO, buf, n) != n) {
            printf("cat: write error\n");
            return;
        }
    }
    if(n < 0){
        printf("cat: read error\n");
        return;
    }
}

int main(int argc, char *argv[])
{
    int fd, i;
    if(argc <= 1){
        cat(0);
        exit(0);
    }

    for(i = 1; i < argc; i++){
        if((fd = open(argv[i], 0)) < 0){
            printf("cat: cannot open %s\n", argv[i]);
            exit(0);
        }
        cat(fd);
        close(fd);
    }
    exit(0);
}