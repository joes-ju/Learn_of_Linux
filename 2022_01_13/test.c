#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>

// int main(){
//     pid_t id = fork();
//     if(id == 0){
//         //process of child
//         int cnt = 5;
//         while(cnt){
//             printf("我是子进程, 我的pid: %d, ppid: %d, 我还有%dS\n", getpid(),getppid(),cnt--);
//         }
//     }

//     //process of parent
//     while(1){
//         int status = 0;
//         // pid_t waitpid(pid_t pid, int *status, int options);
//         pid_t ret_id = waitpid(id,&status,WNOHANG);
//         if(ret_id < 0){
//             printf("waitpid error\n");
//             exit(1);//需要报头stdlib.h
//         }else if(ret_id == 0){
//             printf("子进程还活着呢, 先干别的!\n");
//             sleep(1);
//             continue;
//         }else{
//             printf("我是父进程, 我的pid: %d, ppid: %d, code of exit: %d, code of exit signal: %d, ret_id: %d\n",\
//             getpid(),getppid(),(status>>8)&0xFF, status & 0x7F,ret_id);
//         }
//     }
// }

// int main(){
//     pid_t id = fork();
//     if(id == 0){
//         //process of child
//         int cnt = 5;
//         while(cnt){
//             // int execl(const char *path, const char *arg, ...);
//             execl("./mycc/mycpp","mycpp",NULL);
//             printf("我是子进程, 我的pid: %d, ppid: %d, 我还有%dS\n", getpid(),getppid(),cnt--);
//         }
//     }

//     //process of parent
//     while(1){
//         int status = 0;
//         // pid_t waitpid(pid_t pid, int *status, int options);
//         pid_t ret_id = waitpid(id,&status,WNOHANG);
//         if(ret_id < 0){
//             printf("waitpid error\n");
//             exit(1);//需要报头stdlib.h
//         }else if(ret_id == 0){
//             printf("子进程还活着呢, 先干别的!\n");
//             sleep(1);
//             continue;
//         }else{
//             printf("我是父进程, 我的pid: %d, ppid: %d, code of exit: %d, code of exit signal: %d, ret_id: %d\n",\
//             getpid(),getppid(),(status>>8)&0xFF, status & 0x7F,ret_id);
//         }
//     }
// }

#define LOG "log.txt"

// int main(){
//     FILE* fp = fopen(LOG,"w");
//     if(fp == NULL){
//         perror("fopen");
//         return 1;
//     }
//     const char* msg = "Hello classmate, welcome to NUAA";
//     int cnt = 5;
//     while(cnt){
//         char buffer[1024] = {0};
//         //int snprintf(char *str, size_t size, const char *format, ...);
//         snprintf(buffer,sizeof(buffer),"ChuHsiang: %s->%d\n",msg,cnt--);
//         // int fputs(const char *s, FILE *stream);
//         fputs(buffer,fp);
//         //size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream);
//         // fwrite(buffer,strlen(buffer),1,fp);
//         sleep(1);//需要使用unistd.h报头
//     }

//     fclose(fp);
//     return 0;
// }

int main(){
    //int open(const char *pathname, int flags, mode_t mode);
    umask(0);
    int fd = open(LOG,O_CREAT|O_WRONLY|O_APPEND,0666);
    // const char* msg = "Hello everyone, watashiwakyosandesuka";
    const char* msg = "This is my favorite girl";
    int cnt = 3;
    while(cnt){
        char buffer[1024];
        snprintf(buffer,sizeof(buffer),"ChuHsiang %s->%d\n",msg,cnt--);
        write(fd,buffer,strlen(buffer));
    }
    close(fd);
    return 0;
}

