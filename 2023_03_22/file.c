#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define LOG_NORMAL "logNormal.txt"
#define LOG_ERROR "logError.txt"

int main(){
    //close(1);
    //open(LOG_NORMAL,O_WRONLY|O_CREAT|O_TRUNC,0666);
    //close(2);
    //open(LOG_ERROR,O_WRONLY|O_CREAT|O_TRUNC,0666);

    //printf("hello printf->stdout\n");
    //printf("hello printf->stdout\n");
    //printf("hello printf->stdout\n");
    //printf("hello printf->stdout\n");
    //fprintf(stdout,"hello fprintf->stdout\n"); 
    //fprintf(stdout,"hello fprintf->stdout\n"); 
    //fprintf(stdout,"hello fprintf->stdout\n"); 
    //fprintf(stdout,"hello fprintf->stdout\n");
    //fprintf(stdout,"hello fprintf->stdout\n"); 
    //fprintf(stdout,"hello fprintf->stdout\n"); 
    //fprintf(stdout,"hello fprintf->stdout\n"); 
    //fprintf(stdout,"hello fprintf->stdout\n"); 

    //fprintf(stderr,"hello fprintf->stderr\n");
    //fprintf(stderr,"hello fprintf->stderr\n");
    //fprintf(stderr,"hello fprintf->stderr\n");
    //fprintf(stderr,"hello fprintf->stderr\n");
    //fprintf(stderr,"hello fprintf->stderr\n");
    //fprintf(stderr,"hello fprintf->stderr\n");
    //
    

    
    //int fd = open(LOG_NORMAL,O_CREAT | O_WRONLY | O_APPEND, 0666);
    //if(fd < 0){
    //    perror("open");
    //    return 1;
    //}
    //
    //dup2(fd,1);
    //printf("hello world,hello joes!\n");
    //close(fd);
    //
    

    //C库
    fprintf(stdout,"hello fprintf\n");
    //系统调用
    const char *msg = "hello write\n";
    write(1,msg,strlen(msg));

    fork();//?
    return 0;
}
