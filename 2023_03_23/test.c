#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<assert.h>

// int main(){
//     while (1)
//     {
//         printf("hello proccess\n");
//         sleep(1);
//     }
//     return 0;
// }


// int main(){
//     //getpid()/getppid()是系统提供的接口
//     while(1){
//         printf("Hello proccess, 我已经是一个进程了, 我的PID是: %d\n",getpid());
//         sleep(1);
//     }
//     return 0;
// }

// int main(){
//     while (1)
//     {
//         printf("Hello proccess, 我已经是一个进程了, 我的PID是: %d, 我的父进程PPID是: %d\n", getpid(), getppid());
//         sleep(1);
//     }
//     return 0;
// }


// int main(){
//     printf("AAAAAAAAAAAAAAAAAAAAAAA:pid->%d,ppid->%d\n", getpid(), getppid());
//     fork();
//     printf("BBBBBBBBBBBBBBBBBBBBBBB:pid->%d,ppid->%d\n", getpid(), getppid());
//     sleep(1);
//     return 0;
// }


// int main(){
//     printf("AAAAAAAAAAAAAAAAAAAAAAA:pid->%d, ppid->%d\n", getpid(), getppid());
//     pid_t ret = fork();
//     printf("BBBBBBBBBBBBBBBBBBBBBBB:pid->%d, ppid->%d, ret:%d, &ret:%p\n", getpid(), getppid(), ret, &ret);
//     sleep(1);
//     return 0;
// }


// int main(){
//     int x = 100;
//     pid_t ret = fork();
//     assert(ret !=- 1);
//     if(ret == 0){
//         //子进程
//         while(1){
//             printf("我是子进程, 我的PID是: %d, 我的父进程是: %d, x = %d, &x: %p\n", getpid(), getppid(), x, &x);
//             sleep(1);
//         }
//     }else if(ret > 0){
//         //父进程
//         while(1){
//             x = 4321;
//             printf("我是父进程, 我的PID是: %d, 我的父进程是: %d, x = %d, &x: %p\n", getpid(), getppid(), x, &x);
//             sleep(1);
//         }
//     }
//     return 0;
// }

int Add(int a, int b){
    return a + b;
}

int Sub(int a, int b){
    return a - b;
}

int main(){
    int x = 100, y = 2;
    pid_t ret = fork();
    assert(ret != -1);
    if(ret == 0){
        //子进程
        int sum = Add(x, y);
        printf("我是子进程, 我的PID是: %d, 我的PPID是: %d, sum = %d\n", getpid(), getppid(), sum);
    }else if(ret > 0){
        int sub = Sub(x, y);
        printf("我是父进程, 我的PID是: %d, 我的PPID是: %d, Sub = %d\n", getpid(), getppid(), Sub);
    }
    sleep(1);
    return 0;
}