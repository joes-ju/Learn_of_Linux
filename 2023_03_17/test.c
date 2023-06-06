#include<assert.h>
#include<stdio.h>
#include<unistd.h>

int g_value = 100;//全局变量

int main(){
    pid_t id = fork();
    assert(id >= 0);//断言必须是条件满足的情况
    if(id == 0){
        //child
      while(1){
          printf("我是子进程，我的ID是：%d，我的父进程是：%d，g_value：%d，&g_value：%p\n",getpid(),getppid(),g_value,&g_value);
          sleep(1);
          g_value++;//只有子进程会进行修改
      }
    }else{
        //father
      while(1){
          printf("我是父进程，我的ID是：%d，我的父进程是：%d，g_value：%d，&g_value：%p\n",getpid(),getppid(),g_value,&g_value);
          sleep(2);
      }
    }
}
