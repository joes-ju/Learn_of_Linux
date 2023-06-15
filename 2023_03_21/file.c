#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define LOG "log.txt"

int main(){
    //umask(0);
    int fd1 = open(LOG, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    int fd2 = open(LOG, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    int fd3 = open(LOG, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    int fd4 = open(LOG, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    int fd5 = open(LOG, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    int fd6 = open(LOG, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    printf("%d\n",fd1);
    printf("%d\n",fd2);
    printf("%d\n",fd3);
    printf("%d\n",fd4);
    printf("%d\n",fd5);
    printf("%d\n",fd6);

    
    return 0;
}
