#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>

#define LOG "log.txt"

// int main(){
//     FILE* fd = fopen(LOG,"w");
//     if(fd == NULL){
//         perror("fopen failed");
//         exit(1);
//     }

//     const char* msg = "Hello TOKYO";
//     int cnt = 5;
//     while(cnt){
//         char buffer[512];
//         snprintf(buffer,sizeof(buffer),"ChuHsiang %s: %d\n", msg, cnt);
//         fputs(buffer,fd);
//         cnt--;
//     }

//     fclose(fd);
//     return 0;
// }

// int main(){
//     umask(0);
//     int fd = open(LOG, O_WRONLY|O_CREAT,0666);
//     if(fd == -1){
//         printf("fd: %d, errno: %d, strerror: %s\n",fd,errno,strerror(errno));
//     }else{
//         printf("fd: %d, errno: %d, strerror: %s\n",fd,errno,strerror(errno));
//     }

//     const char* str = "Hello Baby, thank you very much";
//     int cnt = 5;
//     while(cnt){
//         char buffer[512];
//         snprintf(buffer,sizeof(buffer),"ChuHsiang %s :-> %ds\n", str, cnt);
//         //ssize_t write(int fd, const void *buf, size_t count);
//         write(fd,buffer,strlen(buffer));
//         cnt--;
//     }
// }

#include"stack.h"
void test_stack01(){
    ST* ps ;
    StackInit(ps);
    StackPush(ps,11);
    StackPush(ps,22);
    StackPush(ps,33);
    StackPush(ps,44);
    StackPush(ps,55);

    printf("size: %d\n", StackSize(ps));
    printf("size: %d\n", ps->top+1);
    while(ps->top >= 0){
        printf("%d-> ",ps->a[ps->top -1]);
        ps->top--;
    }

    StackDestroy(ps);
}

int main(){
    test_stack01();
    return 0;
}