#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<assert.h>

int main(){
 // while(1){
 //   printf("hello process,我已经是一个进程了,我的pid是：%d,我的父进程是：%d\n",getpid(),getppid());
 //   sleep(1);
 // }
    
  //printf("AAAAAAAAAAAAAAAAAAAAAAA:pid->%d,ppid->%d\n",getpid(),getppid());
  //pid_t ret = fork();
  //printf("BBBBBBBBBBBBBBBBBBBBBBB:pid->%d,ppid->%d,ret:%d,&ret:%p\n",getpid(),getppid(),ret,&ret);
  //sleep(1);
  //
  pid_t ret = fork();
  
  if(ret==0){
    //子进程
    while(1){
    printf("我是一个子进程了,我的pid是：%d,我的父进程是：%d\n",getpid(),getppid());
    sleep(1);
    }
  }else if(ret>0){
    //父进程 
    while(1){
    printf("我是一个父进程了,我的pid是：%d,我的父进程是：%d\n",getpid(),getppid());
    sleep(2);
    }
  }else{

  }
  return 0;
}
