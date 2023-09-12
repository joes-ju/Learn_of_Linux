#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

//基础IO
int main(){
    pid_t id = fork();
    if(id == 0){
        //child
        int cnt = 5;
        while(cnt){
            printf("我是子进程, pid: %d, ppid: %d, %dS\n",getpid(),getppid(),cnt--);
        }
    }
    //parent
    int status = 0;
    while(1){
        pid_t ret_id = waitpid(id,&status,WNOHANG);
        if(ret_id < 0){
            printf("waitpid error\n");
            exit(1);
        }else if(ret_id == 0){
            printf("子进程还活着呢, 可以干别的事\n");
            sleep(1);
            continue;
        }else{
            printf("我是父进程, 我的pid: %d, waitid: %d, code of exit: %d, code of exit signal: %d\n",\
                    getpid(), ret_id, (status>>8)&0xFF,status&0x7F);
        }
    }

    return 0;
}