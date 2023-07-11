#include<stdio.h>
#include<assert.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

#define NAME "ChuHsiang"
//全局变量
int g_value = 100;

// int main(){
//     pid_t id = fork();
//     //fork()在返回的时候，父子都有了，return两次，id不是是pid_t类型的变量，返回本质就是写入
//     //谁先返回，就让OS发生写时拷贝
//     assert(id >= 0);
//     if(id == 0){
//         //子进程
//         while(1){
//             printf("我是子进程, 我的ID是: %d, 我的父进程是: %d, g_value: %d, &g_value: %p\n", getpid(), getppid(), g_value++, &g_value);
//             sleep(1);
//         }

//     }else{
//         //父进程
//         while(1){
//             printf("我是父进程, 我的ID是: %d, 我的父进程是: %d, g_value: %d, &g_value: %p\n", getpid(), getppid(), g_value ,&g_value);
//             sleep(1);
//         }
//     }
//     return 0;
// }

//地址空间是线性的
//向OS申请内存，OS不会立马给用户，在用户需要的时候才给 -- OS不允许任何浪费（或不高效的行为）

void Usage(const char *name){
    printf("\nUsage: %s -[a|b|c]\n", name);
    exit(0);
}

int main(int argc, char *argv[]){
    //模拟命令行
    //./mytest -[a|b|c|d]
    if(argc != 2){
        Usage(argv[0]);
    }

    if(strcmp(argv[1], "-a") == 0){
         printf("打印当前目录下的文件名\n");
    }else if(strcmp(argv[1], "-b") == 0){
         printf("打印当前目录下的文件的详细信息\n");
    }else if(strcmp(argv[1], "-c") == 0){
         printf("打印当前目录下的文件名(包含隐藏文件)\n");
    }else{
        printf("其他功能待开发\n");
    }

    return 0;
}

