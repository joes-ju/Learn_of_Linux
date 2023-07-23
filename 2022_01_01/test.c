#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<stdlib.h>

// int main(){
//     pid_t pid = 0;
//     printf("before: pid is %d\n", getpid());
//     if((pid = fork()) == -1){
//         perror("fork()");
//         exit(1);
//     }
//     printf("after: pid is %d, fork return %d\n", getpid(), pid);
//     sleep(1);

//     return 0;
// }

#include<string.h>
// int main(){
//     for(int i = 0; i <= 200; i++){
//         printf("%d : %s\n", i, strerror(i));
//         //char* strerror(int errnum); --> #include<string.h>
//     }

//     return 0;
// }

//自定义退出码
// const char* err_string[] = {
//     "success",
//     "error"
// };

//退出码
//exit()
#include<stdlib.h>

// int add_to_top(int top){
//     printf("enter add_to_top\n");
//     int sum = 0;
//     for(int i = 0; i <= top; i++){
//         sum += i;
//     }
//     exit(213);
//     printf("out add_to_top\n");
//     return sum;
// }

// int main(){
//     // for(int i = 0; i <= 140; i++){
//     //     printf("%d : %s\n", i, strerror(i));
//     //     exit(123);
//     // }
//     // return 0;


//     int result = add_to_top(100);
//     if(result == 5050){
//         return 0;
//     }else{
//         return 11;//计算结果不正确
//     }
// }


// int add_to_top(int top){
//     printf("enter add_to_top\n");
//     int sum = 0;
//     for(int i = 0; i <= top; i++){
//         sum += i;
//     }
//     _exit(222);
//     printf("out add_to_top\n");
//     return sum;
// }

// int main(){
//     int result = add_to_top(100);
//     if(result == 5050){
//         return 0;
//     }else{
//         return 11;//计算结果不正确
//     }
// }


// int main(){
//     printf("welcome to TU Berlin");//输出缓冲区
//     sleep(2);
//     // exit(107);//关闭文件+冲刷缓冲区
//     _exit(108);//干掉进程，不会对缓冲区数据做任何刷新

//     return 0;
// }

#include<sys/wait.h>
#include<sys/types.h>

// int main(){
//     pid_t id = fork();
//     if(id == 0){
//         //子进程
//         int cnt = 5;
//         while(cnt){
//             printf("我是子进程, 我还活着呢, 我还有%ds, PID:%d, PPID: %d\n",cnt--, getpid(), getppid());
//             sleep(1);
//         }
//         exit(0);
//     }
//     sleep(10);
//     //父进程
//     pid_t ret_id = wait(NULL);
//     printf("我是父进程, 等待子进程成功, PID: %d, PPID: %d, ret_id: %d\n",getpid(), getppid(), ret_id);
//     sleep(5);
//     // return 0;
// }


//status不要当作一个完整的整数，而是位图结构
int main(){
    pid_t id = fork();
    if(id == 0){
        //子进程
        int cnt = 5;
        while(cnt){
            printf("我是子进程, 我还活着呢, 我还有%ds, PID:%d, PPID: %d\n",cnt--, getpid(), getppid());
            sleep(1);
        }
        exit(0);
    }
    sleep(10);
    //父进程
    int status = 0;
    pid_t ret_id = waitpid(id, &status, 0);
    printf("我是父进程, 等待子进程成功, PID: %d, PPID: %d, ret_id: %d, child exit status: %d, child exit signal: %d\n",\
    getpid(), getppid(), ret_id, (status>>8)&0xFF, status & 0x7F);
    sleep(5);
    // return 0;
}