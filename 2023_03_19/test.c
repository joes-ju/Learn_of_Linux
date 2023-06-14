#include<stdio.h>
#include<assert.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>


#define TASK_NUM 10

//预设一批任务
void sync_disk(){
    printf("这是一个刷新数据任务！\n");
}

void sync_log(){
    printf("这是一个同步日志的任务！\n");
}

void net_send(){
    printf("这是一个进行网络发送的任务！\n");
}

//要保存的任务相关的
typedef void (*func_t) ();
func_t other_task[TASK_NUM] = {NULL};

int LoadTask(func_t func){
    int i = 0;
    for(; i < TASK_NUM; i++){
        if(other_task[i] == NULL) break;
    }
    if(i == TASK_NUM) return -1;
    else other_task[i] = func;
    return 0;
}

void InitTask(){
  for(int i = 0; i < TASK_NUM; i++){
    other_task[i] = NULL;
  }
  LoadTask(sync_disk);
  LoadTask(sync_log);
  LoadTask(net_send);
}

void RunTask(){
  for(int i = 0; i < TASK_NUM; i++){
      if(other_task[i] == NULL) continue;
      other_task[i]();
  }
}

int main(){
    pid_t id = fork();
    if(id == 0){
        //子进程
        int cnt = 5;
        while(cnt){
            printf("我是子进程，我还活着呢，我还有%dS, PID=%d, PPID=%d \n",cnt--,getpid(),getppid());
            sleep(1);
        }
        exit(111);
    }

    //父进程
    while(1){
        int status = 0;
        pid_t ret_id = waitpid(id,&status,WNOHANG);
        if(ret_id < 0){
            printf("waitpid error!\n");
            exit(1);
        }else if(ret_id == 0){
            RunTask();
            sleep(1);
            continue;
        }else{
          if(WIFEXITED(status)){
              printf("wait success, child exit code: %d\n",WEXITSTATUS(status));
          }else{
              printf("wait success, child exit signal: %d\n",status & 0x7F);
          }
          break;
        }
    }
}
