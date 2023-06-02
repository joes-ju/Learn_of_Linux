#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t id = fork();
    if(id == 0){
        while(1){
        printf("我是子进程，PID：%d，PPID：%d\n",getpid(),getppid());
        sleep(1);
    }
    }else if(id > 0){
        while(1){ 
           printf("我是父进程，PID：%d，PPID：%d\n",getpid(),getppid());
           sleep(1);
        
        }
  }
}
