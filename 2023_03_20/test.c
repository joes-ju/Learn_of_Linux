#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

#define LOG "log.txt"
//系统方案
#define LOG_NORMAL "logNormal.txt"
#define LOG_ERROR "logError.txt"

int main(){
    


    umask(0);
    int fd = open(LOG, O_CREAT | O_WRONLY | O_APPEND, 066);
    if(fd == -1){
        printf("fd:%d, errno:%d, errstring:%s\n",fd,errno,strerror(errno));
        
    }else{
        printf("fd:%d, errno:%d, errstring:%s\n",fd,errno,strerror(errno));
    }

    char buffer[1024];
    //这里我们无法做到按行读取，我们是整体读取的
    ssize_t n = read(fd,buffer,sizeof(buffer)-1);//使用系统接口进行IO的时候，一定要注意，\0问题
    if(n > 0){
        buffer[n] = '\0';

        printf("%s\n",buffer);
    }

    const char *msg = "AAAAAAAAAA";
    int cnt = 5;

    while(cnt){
        char line[128];
        snprintf(line,sizeof(line),"%s,%d\n",msg,cnt);

        write(fd,line,strlen(line));//这里的strlen不要+1，因为\0 是C语言的规定，不是文件的规定
        cnt--;
    }

    //dup2(fd,1);

    //printf("hello world, hello NIT!\n");
    close(fd);


    return 0;
}

//语言方案

//int main(){
//    //"w": 默认写方式打开文件，如果文件不存在，就创建它
//    //1.默认如果只是打开，文件内容会被清空 
//    //2.同时，每次进行写入的时候，都会从最开始进行写入
//    //FILE *fp = fopen(LOG,"w");
//    //"a": 不会清空文件，而是每一次写入都是从文件结尾写入的，追加
//    FILE *fp = fopen(LOG,"a");
//    if(fp == NULL){
//        perror("fopen"); //fopen: xxxx
//        return 1;
//    }
//
//    //正常文件操作
//  //while(1){
//  //    char line[128];
//  //    if(fgets(line,sizeof(line),fp) == NULL) break;
//  //    else printf("%s",line);
//  //}
//
//    const char *msg = "hello joes";
//    int count = 5;
//    while(count){
//        //fputs(msg,fp);
//        char buffer[256];
//        snprintf(buffer,sizeof(buffer),"%s:%d:ChuHsiang\n",msg,count);
//
//        fputs(buffer,fp);
//        printf("%s",buffer);
//
//
//        count--;
//    }
//
//    fclose(fp);
//    return 0;
//}
