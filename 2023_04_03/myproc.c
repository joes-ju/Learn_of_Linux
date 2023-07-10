#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

// #define NAME "ChuHsiang"
//envp[]是一张环境变量表
// int main(int argc, char *argv[], char *envp[]){
// int main(){

//     // int cnt = 5;
//     // while(cnt){
//     //     printf("hello %d\n",cnt);
//     //     cnt--;
//     // }

//     //mian()函数可以带参
//     //char *envp[];指针数组 char* str="hello abc"中,char*指向字符串起始地址
//     // printf("%d\n",sizeof(int*));//8
//     // printf("%d\n",sizeof(char*));//8

//     // for(int i = 0; envp[i]; i++){
//     //     printf("envp[%d] -> %s\n", i, envp[i]);
//     // }

//     //environ[i]  *(environ+i)
//     // extern char **environ;
//     // for(int i = 0; environ[i]; i++){
//     //     printf("environ[i] -> %s\n", i ,environ[i]);
//     // }

//     //函数获取环境变量
//     // char *user = getenv("USER");
//     // if(user == NULL){
//     //     perror("USER");
//     // }else{
//     //     printf("USER: %s\n",user);
//     // }

//     // char *own = getenv("USER");
//     // if(strcmp(own,NAME) == 0){
//     //     printf("这个程序已经执行啦...\n");
//     // }else{
//     //     printf("当前用户%s是一个非法用户, 无法执行\n", own);
//     // }

//     //环境变量是可以被相关子进程继承下去的 -- 环境变量具有全局属性
//     printf("myenv: %s\n", getenv("hello"));
//     //内建

//     return 0;
// }

//命令行参数
// int main(int argc, char *argv[]){
//     printf("argc: %d\n",argc);
//     //char *argv[]
//     for(int i = 0; i < argc; i++){
//         printf("argv[%d] -> %s\n", i, argv[i]);
//     }
//     return 0;
// }


void Usage(const char *name){
    printf("\nUsage: %s -[a|b|c]\n", name);
    exit(0);//终止进程
}

int main(int argc, char *argv[]){
    //eg ./myproc arg
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
        printf("其他功能, 待开发\n");
    }

    return 0;
}