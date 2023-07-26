#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>
#include<string.h>
#include<stdlib.h>

// int main(){
//     pid_t id = fork();
//     if(id == 0){
//         //子进程
//         int cnt = 5;
//         while(cnt){
//             printf("我是子进程, 我还活着呢, 我还有%ds, PID = %d, PPid = %d\n", cnt--, getpid(),getppid());
//             sleep(1);
//         }

//     }
//     //父进程
//     while(1){
//         int status = 0;
//         pid_t ret_id = waitpid(id, &status, WNOHANG);//夯住了 -- 非阻塞的方式
//         if(ret_id < 0){
//             printf("waitpid error!\n");
//             exit(1);
//         }else if(ret_id == 0){
//             printf("子进程还没退出呢, 我在做做其他的事情......\n");
//             sleep(1);
//             continue;
//         }else{
//             printf("我是父进程, 等待子进程成功, PID: %d, PPID: %d, ret_id: %d, child exit code: %d, child exit signal: %d\n",\
//                     getpid(), getppid(), ret_id, (status>>8)&0xFF, status & 0x7F);
//             break;
//         }
//     }

// }

// int main(){
//     //打印所有的退出码
//    for(int i = 0; i < 140; i++){
//         printf("%d -> %s\n",i,strerror(i));
//    }
//    return 0;
// }

//父进程定期执行某些任务
#define TASK_NUM 10
typedef void (*func_t)(); //函数指针类型
func_t other_task[TASK_NUM] = {NULL};//函数指针数组

//预设一批任务
void sync_disk(){
    printf("这是一个刷新数据的任务\n");
}

void sync_log(){
    printf("这是一个同步日志的任务\n");
}

void net_send(){
    printf("这是一个进行网络发送的任务\n");
}

//要保存的任务相关
int LoadTask(func_t func){
    //装载任务
    int i = 0;
    for( i; i < TASK_NUM; i++){
        if(other_task[i] == NULL){
            break;
        }

        if(i == TASK_NUM){
            return -1;
        }else{
            other_task[i] = func;
        }
    }

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
            printf("我是子进程, 我还活着呢, 我还有%dS, PID: %d, PPID: %d\n", cnt--, getpid(), getppid());
            sleep(1);
        }
    }
    InitTask();
    while(1){
        int status = 0;
        pid_t ret_id = waitpid(id, &status, WNOHANG);
        if(ret_id < 0){
            printf("waitpid error!\n");
            exit(1);
        }else if(ret_id == 0){
            RunTask();
            sleep(1);
            continue;
        }else{
            printf("我是父进程, 等待子进程成功, PID: %d, PPID: %d, ret_id: %d, child exit code: %d, child exit signal: %d\n",\
                     getpid(), getppid(), ret_id, (status>>8)&0xFF, status & 0x7F);
            break;
        }
    }
}
