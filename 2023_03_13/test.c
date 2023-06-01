#include<stdio.h>
#include<assert.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
  pid_t ret = fork();
  if(ret==0){
    //子进程
    while(1){
      printf("我是子进程，我的PID是：%d，我的父进程是：%d\n",getpid(),getppid());
      sleep(1);
    }
  }else if(ret>0){
    //父进程
    while(1){
      printf("我是父进程，我的PID是：%d，我的父进程是：%d\n",getpid(),getppid());
    }
  }else{

  }
  return 0;
}
