#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

// int main(){
//     pid_t id = fork();
//     if(id == 0){
//         //child
//         int cnt = 5;
//         while(cnt){
//             printf("我是子程序, 我还有%dS, 我的PID是%d, PPID是%d\n", cnt--, getpid(), getppid());
//             sleep(1);
//         }
//     }
//     //father
//     while(1){
//         int status = 0;

//         //pid_t waitpid(pid_t pid, int *status, int options);
//         pid_t ret_id = waitpid(id, &status, WNOHANG);
//         if(ret_id < 0){
//             printf("waitpid error!\n");
//             exit(1);
//         }else if(ret_id == 0){
//             printf("子进程还活着呢, 我再做其他的事!\n");
//             sleep(1);
//             continue;
//         }else{
//             printf("我是父进程, 等待子进程成功, PID: %d, PPID: %d, ret_id: %d, child exit code: %d, child exit signal: %d\n",\
//                      getpid(), getppid(), ret_id, (status>>8)&0xFF, status & 0x7F);
//             break;
//         }
//     }
// }



// #define TASK_NUM 10

// //预设的3个任务
// void sync_log(){
//     printf("这是一个同步系统日志的任务!\n");
// }

// void sync_disk(){
//     printf("这是一个刷新磁盘的任务!\n");
// }

// void net_send(){
//     printf("这是一个网络数据发送任务!\n");
// }

// typedef void (*func_t)();//函数指针类型
// func_t other_task[TASK_NUM] = {NULL};

// int LoadTask(func_t func){
//     //装载任务
//     int i = 0;
//     for(i; i < TASK_NUM; i++){
//         if(other_task[i] == NULL){
//             break;
//         }
//     }

//     if(i == TASK_NUM){
//         return -1;
//     }else{
//         other_task[i] = func;
//     }

//     return 0;
// }

// void InitTask(){
//     for(int i = 0; i < TASK_NUM; i++){
//         other_task[i] = NULL;
//     }

//     LoadTask(sync_disk);
//     LoadTask(sync_log);
//     LoadTask(net_send);
// }

// void RunTask(){
//     int i = 0;
//     for(i; i < TASK_NUM; i++){
//         if(other_task[i] == NULL){
//             continue;
//         }

//         other_task[i]();
//     }
// }

// int main(){
//     pid_t id = fork();
//     if(id == 0){
//         //child
//         int cnt = 5;
//         while(cnt){
//             printf("我是子程序, 我还有%dS, PID: %d, PPID: %d\n", cnt--, getpid(), getppid());
//             sleep(1);
//         }
//     }
//     //father
//     InitTask();
//     while(1){
//         int status = 0;
//         pid_t ret_id = waitpid(id, &status, WNOHANG);//id>0时，等待其进程ID与id相等的子进程；id=-1时，等待任一子进程
//         if(ret_id < 0){
//             printf("waitpid error!\n");
//             exit(1);
//         }else if(ret_id == 0){
//             RunTask();
//             sleep(1);
//             continue;
//         }else{
//             // printf("我是父进程, 等待子进程成功, PID: %d, PPID: %d, ret_id: %d, child exit code: %d, child exit signal: %d\n",\
//             //          getpid(), getppid(), ret_id, (status>>8)&0xFF, status & 0x7F);

//             if(WIFEXITED(status)){
//                 printf("wait success, child exit code: %d\n", WEXITSTATUS(status));
//             }else{
//                 printf("wait success, child exit signal: %d\n", status & 0x7F);
//             }
//             break;
//         }
//     }
// }




//about process replacement
// int main(){
//     pid_t id = fork();
//     if(id == 0){
//         //child
//         printf("我是子进程, pid->%d, ppid->%d\n", getpid(), getppid());
//         execl("/bin/ls","ls","-a","-l",NULL);

//     }
//     //father
//     sleep(5);
//     printf("我是父进程, pid->%d, ppid->%d\n", getpid(), getppid());
//     return 0;
// }

// int main(){
//     pid_t id = fork();
//     if(id == 0){
//         //child
//         int cnt = 5;
//         while(cnt){
//             printf("我是子进程, 我还有%dS, pid: %d, ppid: %d\n", cnt--, getpid(),getppid());
//             sleep(1);
//         }
//     }
//     //father
//     while(1){
//         int status = 0;
//         pid_t ret_id = waitpid(id, &status, WNOHANG);//id>0时，等待其进程ID与id相等的子进程；id=-1时，等待任一子进程
//         if(ret_id < 0){
//             printf("waitpid error!\n");
//             exit(1);
//         }else if(ret_id == 0){
//             printf("子进程还活着呢!\n");
//             sleep(1);
//             continue;
//         }else{
//             printf("我是父进程, 等待子进程成功, pid: %d, ppid: %d, ret_id: %d, child exit code: %d, child exit signal: %d\n",\
//                     getpid(), getppid(), ret_id, (status>>8) & 0xFF, status & 0x7F);
//             break;
//         }
//     }
//     return 0;
// }

int main(){
    //int putenv(char *string); -- #include<stdlib.h>
    extern char** environ;
    pid_t id = fork();
    if(id == 0){
        //child
        printf("我是子进程, pid: %d\n", getpid());

        // putenv("MYENV=YouCanSeeMe");
        // execle("./exec/otherproc", "otherproc", NULL, environ);
        execl("./exec/test.py", "test.py", NULL);
        exit(1);
    }
    sleep(1);
    int status = 0;
    printf("我是父进程, pid: %d\n", getpid());
    waitpid(id, &status, 0);
    printf("child exit code: %d\n", WEXITSTATUS(status));

    return 0;
}

//环境变量具有全局属性，可以被子进程继承下去。因为所有进程都是bash的子进程，而bash可以通过exec执行










