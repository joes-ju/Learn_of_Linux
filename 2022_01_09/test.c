#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

#define LOG "log.txt"

// int main(){
//     umask(0);
//     //int open(const char *pathname, int flags, mode_t mode);  -- -1失败，成功则返回文件描述符号
//     int fd = open(LOG, O_WRONLY | O_CREAT, 0666);
//     if(fd == -1){
//         printf("fd: %d, errno: %d, strerror: %s\n", fd, errno, strerror(errno));
//     }else{
//         printf("fd: %d, errno: %d, strerror: %s\n", fd, errno, strerror(errno));
//     }

//     //ssize_t write(int fd, const void *buf, size_t count);
//     //int snprintf(char *str, size_t size, const char *format, ...);

//     const char* msg = "Hello ChuHsiang, You must believe yourself!";
//     int cnt = 5;
//     while(cnt){
//         char line[1024];
//         snprintf(line, sizeof(line), "%s, %d\n",msg,cnt);
//         write(fd, line,strlen(line));
//         cnt--;
//     }

//     close(fd);
//     return 0;
// }

// int main(){
//     FILE* fd = fopen(LOG,"w");//成功，返回FILE指针；失败，返回NULL，指出errno
//     if(fd == NULL){
//         perror("fopen fail");
//         return 1;
//     }

//     //输出转换函数：
//     // int printf(const char *format, ...);
//     // int fprintf(FILE *stream, const char *format, ...);
//     // int sprintf(char *str, const char *format, ...);
//     // int snprintf(char *str, size_t size, const char *format, ...);

//     const char* msg = "Hello NIT";
//     int cnt = 5;
//     while(cnt){
//         char buffer[128];
//         snprintf(buffer, sizeof(buffer), "ChuHsiang %s: %d\n", msg, cnt);
//         fputs(buffer, fd);
//         cnt--;
//     }


//     //char *fgets(char *s, int size, FILE *stream);
//     //int fputs(const char *s, FILE *stream);
//     // char* s = "Hello NIT\n";
//     // fputs(s, fd);


//     fclose(fd);
//     return 0;
// }

// int main(){
//     // FILE* fd = fopen(LOG,"w");
//     FILE* fd = fopen(LOG, "a");
//     if(fd == NULL){
//         perror("fopen failed");
//         return 1;
//     }

//     const char* str = "one must have sunshine, freedom, and a little flower";
//     int cnt = 3;
//     while(cnt){
//         char buffer[512];
//         // snprintf(buffer,sizeof(buffer),"joes -> %s : %d\n", str, cnt);
//         snprintf(buffer,sizeof(buffer),"ChuHsiang %s: %d time\n", str, cnt);
//         fputs(buffer,fd);
//         cnt--;
//     }

//     fclose(fd);
//     return 0;
// }


// int main(){
//     umask(0);
//     //int open(const char *pathname, int flags, mode_t mode);
//     int fd = open(LOG,O_WRONLY | O_CREAT,0666);
//     if(fd == -1){
//         printf("fd: %d, errno: %d, errstring: %s\n", fd, errno, strerror(errno));
//     }else{
//         printf("fd: %d, errno: %d, errstring: %s\n", fd, errno, strerror(errno));
//     }

//     char buffer[1024];
//     //ssize_t read(int fd, void *buf, size_t count);
//     ssize_t n = (fd,buffer, sizeof(buffer)-1);
//     if(n > 0){
//         buffer[n] = '\0';
//         printf("%s\n",buffer);
//     }

//     //ssize_t write(int fd, const void *buf, size_t count);
//     const char* msg = "hello joes, hello chuhsiang";
//     int cnt = 3;
//     while(cnt){
//         char line[128];
//         snprintf(line,sizeof(line),"%s, %d\n",msg,cnt);//C标准的
//         write(fd,line,strlen(line));//这里的strlen()不需要+1，"\0"是C语言的规定，不是文件规定
//         cnt--;
//     }

//     close(fd);
// }

// #include"List.h"

// void test_list01(){
//     LTNode* phead = Iint();
//     PushBack(phead, 1);
//     PushBack(phead, 2);
//     PushBack(phead, 3);
//     PushBack(phead, 4);
//     PushBack(phead, 5);
//     print(phead);
// }

// void test_list02(){
//     LTNode* phead = Iint();
//     PushBack(phead, 1);
//     PushBack(phead, 2);
//     PushBack(phead, 3);
//     PushBack(phead, 4);
//     PushBack(phead, 5);
//     print(phead);
//     Destroy(phead);
//     PushFront(phead,10);
//     PushFront(phead,20);
//     PushFront(phead,30);
//     print(phead);
// }

// int main(){
//     // test_list01();
//     test_list02();
//     return 0;
// }

// int main(){
//     //C的库函数
//     FILE* fd = fopen(LOG,"w");
//     if(fd == -1){
//         perror("fopen failed");
//         exit(1);
//     }

//     const char* msg = "you must believe in youself";
//     int cnt = 5;
//     while(cnt){
//         char buffer[512];
//         snprintf(buffer, sizeof(buffer), "ChuHsiang %s: %ds\n", msg, cnt); 
//         fputs(buffer,fd);
//         cnt--;
//     }
//     fclose(fd);
// }

int main(){
    //OS调用
    umask(0);
    int fd = open(LOG, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(fd == -1){
        printf("fd: %d, errno: %d, errstring: %s\n", fd, errno, strerror(errno));
    }else{
        printf("fd: %d, errno: %d, errstring: %s\n", fd, errno, strerror(errno));
    }

    const char* str = "Hello everyone, welcome to NUAA";
    int cnt = 5;
    while(cnt){
        char Line[512];
        snprintf(Line, sizeof(Line), "%s: %d\n", str, cnt);
        write(fd,Line,strlen(Line));
        cnt--;
    }

    close(fd);
}