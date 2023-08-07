#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<assert.h>

#define LOG "log.txt"

// int main(){
//     //language of C's program
//     FILE* fd = fopen(LOG, "w");
//     if(fd == NULL){
//         perror("fopen fail");
//         exit(-1);
//     }

//     const char* msg = "Hello young, you must believe in youself";
//     int cnt = 5;
//     while(cnt){
//         char buffer[512];
//         snprintf(buffer,sizeof(buffer), "ChuHsiang %s: %ds\n", msg,cnt);
//         fputs(buffer,fd);
//         cnt--;
//     }

//     fclose(fd);
//     return 0;
// }

// int main(){
//     pid_t id = fork();
//     assert(id >= 0);
//     if(id == 0){
//         //child
//         //system's file transfer
//         umask(0);
//         int fd = open(LOG, O_WRONLY | O_CREAT |O_TRUNC, 0666);
//         if(fd == -1){
//             printf("fd: %d, errno: %d, strerror: %s\n", fd, errno, strerror(errno));
//         }else{
//             printf("fd: %d, errno: %d, strerror: %s\n", fd, errno, strerror(errno));
//         }

//         //write
//         const char* msg = "Hello joes, you will become to be my teacher";
//         int cnt =3;
//         while(cnt){
//             char buffer[512];
//             snprintf(buffer, sizeof(buffer), "joes-> %s: %ds\n", msg, cnt);
//             //ssize_t write(int fd, const void *buf, size_t count);
//             ssize_t n = write(fd,buffer,strlen(buffer));
//             printf("n: %d\n",n);
//             cnt--;
//             sleep(1);
//         }
//         close(fd);
//     }
//     sleep(5);
//     while(1){
//         int status = 0;
//         //pid_t waitpid(pid_t pid, int *status, int options);
//         pid_t ret_id = waitpid(id, &status, WNOHANG);
//         if(ret_id < 0){
//             printf("waitpid fail\n");
//             exit(1);
//         }else if(ret_id == 0){
//             printf("子进程还或者呢, 先干别的事!\n");
//             sleep(1);
//             continue;
//         }else{
//             printf("我是父进程, 我的pid: %d, ppid: %d, child exit code: %d, child signal code: %d\n", \
//             getpid(),getppid(),(status>>8)&0xFF,status & 0x7F);
//             break;
//         }
//     }
// }

//进程中，文件描述符的分配原则：在文件描述符表中，最小的，没有被使用的数组元素，分配给新文件
//重定向 -- 只需要更改文件描述符
int main(){
    umask(0);
    close(1);
    int fd = open(LOG, O_WRONLY|O_CREAT|O_TRUNC, 0666);
    printf("you can see me!\n");
    printf("you can see me!\n");
    printf("you can see me!\n");
    printf("you can see me!\n");
    printf("you can see me!\n");

    // printf("stdin->%d\n",fileno(stdin));
    // printf("stdout->%d\n",fileno(stdout));
    // printf("stderr->%d\n",fileno(stderr));

}