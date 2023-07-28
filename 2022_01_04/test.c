#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>

#define TASK_NUM 10

// int main(){
//     for(int i = 0; i < 135; i++){
//         printf("[%d] -> %s\n", i , strerror(i));
//     }
//     return 0;
// }

// void Usage(const char* name){
//     printf("\nUsage: %s -[a|b|c]\n", name);
//     exit(0);
// }

// int main(int argc, char* argv){
//     //模拟命令  ./mytest -a| -b |-c 
//     if(argc != 2){
//         Usage(argv[0]);
//     }
    
//     if(strcmp(argv[1], "-a") == 0){
//         printf("打印当前目录下的文件名\n");
//     }else if(strcmp(argv[1], "-b") == 0){
//         printf("打印当前目录下的文件的详细信息\n");
//     }else if(strcmp(argv[1], "-c") == 0){
//         printf("打印当前目录下的文件名(包含隐藏文件)\n");
//     }else{
//         printf("其他功能待开发\n");
//     }

//     return 0;
// }

//WIFEXITED(status):若为正常终止子进程返回的状态，则为真（查看进程是否正常退出）
//WEXITSTATUS(status): 若WIFEXITED非零，提取子进程退出码（查看进程的退出码）

//预设一批任务
// void sync_disk(){
//     printf("这是一个数据刷新的任务!\n");
// }

// void sync_log(){
//     printf("这是一个同步日志的任务!\n");
// }

// void net_send(){
//     printf("这是一个网络发送的任务!\n");
// }

// //要保存的任务相关
// typedef void (*func_t)();//函数指针类型
// func_t other_task[TASK_NUM] = {NULL}; //函数指针数组


// int LoadTask(func_t func){
//     //装载任务
//     int i = 0;
//     for(i = 0; i < TASK_NUM; i++){
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
//     int i = 0;
//     for(i = 0; i < TASK_NUM; i++){
//         other_task[i] = NULL;
//     }

//     LoadTask(sync_disk);
//     LoadTask(sync_log);
//     LoadTask(net_send);
// }

// void RunTask(){
//     int i = 0;
//     for(i = 0; i < TASK_NUM; i++){
//         if(other_task[i] == NULL){
//             continue;
//         }
    
//         other_task[i]();
//     }
// }

// int main(){
//     pid_t id = fork();
//     if(id == 0){
//         //子进程
//         int cnt = 5;
//         while(cnt){
//             printf("我是子进程, 我还有%dS, PID: %d, PPID:%d\n", cnt--, getpid(), getppid());
//             sleep(1);
//         }
//     }
//     //父进程
//     InitTask();
//     while(1){
//         int status = 0;
//         pid_t ret_id = waitpid(id, &status, WNOHANG);
//         if(ret_id < 0){
//             printf("waitpid error!\n");
//             exit(1);
//         }else if(ret_id == 0){
//             RunTask();
//             sleep(1);
//             continue;
//         }else{
//             if(WIFEXITED(status)){//是否收到信号决定是否正常退出
//                 printf("wait success, child exit code: %d\n", WEXITSTATUS(status));
//             }else{
//                 printf("wait success, child exit signal: %d\n", status & 0x7F);
//             }
//             // printf("我是父进程, 等待子进程成功, PID: %d, PPID: %d, ret_id: %d, child exit code: %d, child exit signal: %d\n",\
//             //          getpid(), getppid(), ret_id, (status>>8)&0xFF, status & 0x7F);
//             break;
//         }
//     }
// }

//创建子进程的目的：让子进程执行父进程的一部分代码；如果子进程想执行全新的程序代码？->进程的程序替换
//程序替换（单进程版）
//int execl(const char* path, const char* arg, ...) -- 程序替换
//"..."是可变参数列表

// int main(){
//     printf("begin...\n");
//     printf("begin...\n");
//     printf("begin...\n");

//     printf("我已经是一个进程了, PID: %d, PPID: %d\n", getpid(), getppid());
//     execl("/bin/ls","ls","-a","-l", NULL);//必须NULL结束

//     printf("end...\n");
//     printf("end...\n");
//     printf("end...\n");

//     return 0;
// }

//进程的程序替换没有创建新的进程，PCB的PID没有改变；
//当创建进程的时候，先有进程数据结构，在需要的时候加载代码和数据 -- 加载过程

// int main(){
//     printf("begin...\n");
//     printf("begin...\n");
//     printf("begin...\n");

//     printf("我已经是一个进程了, PID: %d, PPID: %d\n", getpid(), getppid());
//     execl("/bin/ls","ls","-a","-l", NULL);//必须NULL结束
//     //执行程序替换，新的代码和数据就被加载了，后续的代码（end...等）属于旧代码，直接被替换，没有机会执行了

//     printf("end...\n");
//     printf("end...\n");
//     printf("end...\n");

//     return 0;
// }
//程序替换是整体替换，不是局部替换

// int main(){
//     pid_t id = fork();
//     if(id == 0){
//         //子进程
//         printf("我是子进程, PID: %d\n", getpid());
//         //execl,如果替换成功，不会有返回值；如果替换失败，一定返回值 
//         //不要对该函数进行返回值判断，之啊哟继续向后进行运行，就一定失败
//         execl("/bin/ls","ls","-a","-l",NULL);
//         printf("you failed\n");
//     }
//     //父进程
//     sleep(5);
//     int status = 0;
//     printf("我是父进程, PID: %d\n", getpid());
//     waitpid(id, &status, 0);
//     printf("child exit code: %d\n", WEXITSTATUS(status));
//     return 0;
// }
//程序替换只会影响调用进程，因为进程具有独立性！
//进程加载程序时，需要进行程序替换，发生写时拷贝（子进程执行的可是全新的程序，新的代码，写时拷贝在代码区也可以发生）

//程序替换的接口
//int execl(const char* path, const char* arg, ...); -- l相当于list
//const char* path: “你想执行谁”--》找到它 --》需要路径
//const char* arg: "你想怎么执行"

//int execv(const char* path, char* const argv[]); -- execv中"v"表示 vector(数组)
//
// int main(){
//     pid_t id = fork();
//     if(id == 0){
//         //子进程
//         printf("我是子进程, PID: %d\n", getpid());
//         char* const myargv[] = {
//             "ls",
//             "-a",
//             "-l",
//             "-n",
//             NULL
//         };
//         execv("/bin/ls",myargv);
//         printf("you failed\n");
//     }
//     //父进程
//     sleep(5);
//     int status = 0;
//     printf("我是父进程, PID: %d\n", getpid());
//     waitpid(id, &status, 0);
//     printf("child exit code: %d\n", WEXITSTATUS(status));
//     return 0;
// }


//int execlp(const char* file, const char* arg,...); -- execlp中p表示path
//当我们执行指定程序的时候，只需要指定程序名即可，系统会自动在环境变量PATH中进行查找
// int main(){
//     pid_t id = fork();
//     if(id == 0){
//         //子进程
//         printf("我是子进程, PID: %d\n", getpid());
//         execlp("ls","ls","-a","-l",NULL);//第一个"ls"就在PATH中（环境变量）
//         printf("you failed\n");
//     }
//     //父进程
//     sleep(5);
//     int status = 0;
//     printf("我是父进程, PID: %d\n", getpid());
//     waitpid(id, &status, 0);
//     printf("child exit code: %d\n", WEXITSTATUS(status));
//     return 0;
// }

//int execvp(const char* file, char* const argv[]); -- execvp中p就不需要绝对路径
// int main(){
//     pid_t id = fork();
//     if(id == 0){
//         //子进程
//         printf("我是子进程, PID: %d\n", getpid());
//         char* const myargv[] = {
//             "ls",
//             "-a",
//             "-l",
//             "-n",
//             NULL
//         };
//         execvp("ls",myargv);
//         printf("you failed\n");
//     }
//     //父进程
//     sleep(5);
//     int status = 0;
//     printf("我是父进程, PID: %d\n", getpid());
//     waitpid(id, &status, 0);
//     printf("child exit code: %d\n", WEXITSTATUS(status));
//     return 0;
// }

//int execle(const char* path, const char* arg, ... , char* const envp[]); -- 自定义环境变量
int main(){
    pid_t id = fork();
    if(id == 0){
        //子进程
        printf("我是子进程, PID: %d\n", getpid());
        execl("./exec/otherproc","otherproc",NULL);
        printf("you failed\n");
    }
    //父进程
    sleep(5);
    int status = 0;
    printf("我是父进程, PID: %d\n", getpid());
    waitpid(id, &status, 0);
    printf("child exit code: %d\n", WEXITSTATUS(status));
    return 0;
}