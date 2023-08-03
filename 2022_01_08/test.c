#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

#define LOG "log.txt"
//文件系统
//文件描述符，重定向，缓冲区
//Linux系统方案

//int open(const char *pathname, int flags, mode_t mode);  -- -1失败，成功则返回文件描述符号


int main(){
    //等同fopen(LOG,"w");
    umask(0);
    //O_CREAT|O_WRONLY默认不会对原始文件内容做清空
    //int open(const char *pathname, int flags, mode_t mode)
    // int fd = open(LOG, O_WRONLY | O_CREAT,0666);
    //int fd = open(LOG, O_WRONLY | O_CREAT| O_TRUNC,0666);//O_TRUNC将文件清空
    int fd = open(LOG, O_WRONLY | O_APPEND | O_CREAT,0666);//O_RDONLY读取
    if(fd == -1){
        printf("fd: %d, errno: %d, errstring: %s\n", fd, errno, strerror(errno));
    }else{
        printf("fd: %d, errno: %d, errstring: %s\n", fd, errno, strerror(errno));
    }

    char buffer[1024];
    //这里我们无法做到按行读取，是整体读取的
    // ssize_t read(int fd, void *buf, size_t count);
    ssize_t n = read(fd,buffer,sizeof(buffer)-1);//使用系统接口来进行IO的时候，一定要注意，"\0"问题
    if(n > 0){
        buffer[n] = '\0';
        printf("%s\n",buffer);
    }
    
    //ssize_t write(int fd, const void *buf, size_t count);
    // int snprintf(char *str, size_t size, const char *format, ...);
    // const char* msg = "hello joes,hello chuhsiang";
    // int cnt = 3;
    // while(cnt){
    //     char line[128];
    //     snprintf(line,sizeof(line),"%s, %d\n",msg,cnt);//C标准的
    //     write(fd,line,strlen(line));//这里的strlen()不需要+1，"\0"是C语言的规定，不是文件规定
    //     cnt--;
    // }
    
    close(fd);
    return 0;
}















//C语言方案
// int main(){
//     //FILE *fopen(const char *path, const char *mode);
//     //w:默认写方式打开文件，如果文件不存在，就创建它；
//     //  1.默认如果只是打开，文件内容会被自动清空
//     //  2.同时，每次进行写入的时候，都会从最开始进行写入
//     // FILE* fp = fopen(LOG,"w");
//     FILE* fp = fopen(LOG,"a");

//     if(fp == NULL){
//         //void perror(const char *s) 错误码转错误码描述等价strerror(int num)   
//         perror("fopen");//fopen: XXX
//         return 1;
//     }

//     // const char* msg = "hello chusiang, welcome to CHN";
//     // const char* msg = "aaaaaa";

//     // int cnt = 5;
//     // while(cnt){
//     //     //int snprintf(char *str, size_t size, const char *format, ...);
//     //     //printf()默认向显示器打印；fprintf()指定文件流，向指定文件打印
//     //     // fprintf(fp, "%s: %d: ChuHsiang\n", msg,cnt);

//     //     //Linux中一切皆文件
//     //     // fputs(msg,fp);

//     //     char buffer[256];
//     //     snprintf(buffer, sizeof(buffer), "%s: %d: ChuHsiang\n", msg, cnt);

//     //     fputs(buffer, fp);


//     //     cnt--;
//     // }

//     while(1){
//         //char *fgets(char *s, int size, FILE *stream);从特定的文件流中按行读取文件,放入指定的地方
//         char line[128];
//         if(fgets(line,sizeof(line),fp) == NULL){
//             break;
//         }else{
//             printf("%s\n",line);
//         }
//     }

//     //int fclose(FILE *fp);
//     fclose(fp);
//     return 0;
// }