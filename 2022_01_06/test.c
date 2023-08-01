#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX 1024
#define ARGC 64
#define SEP " "

//模拟指令
// void Usage(const char* name){
//     printf("\nUsage: %s [-a|-b|-c]\n", name);
//     exit(0);
// }

// int main(int argc, char* argv[]){
//     //simulate command
//     //e.g ls -a|-b|-c
//     if(argc != 2){
//         Usage(argv[0]);
//     }

//     if(strcmp(argv[1], "-a") == 0){
//         printf("打印所有内容!\n");
//     }else if(strcmp(argv[1], "-b") == 0){
//         printf("打印一部分内容!\n");
//     }else if(strcmp(argv[0], "-c") == 0){
//         printf("打印链接内容!\n");
//     }else{
//         printf("选择的超出范围!\n");
//     }
// }


// int main(){
//     char str[] = "- This, a sample string.";
//     char* pch;
//     printf("spliting string \"%s\" into tockens: \n", str);
//     pch = strtok(str, " ,.-");
//     int i = 0;
//     while(pch){
//         printf("[%d]: %s\n",i, pch);
//         pch = strtok(NULL, " ,.-");
//         i++;
//     }
//     return 0;
// }

// int main(){
//     char str[] = "hello world and welcome!";
//     char* argv[ARGC];
//     argv[0] = strtok(str, SEP);
//     if(argv[0] == NULL) {
//         return -1;
//     }

//     int i = 1;
//     while(1){
//         argv[i] = strtok(NULL, SEP);
//         if(argv[i] == NULL){
//             break;
//         }
//         i++;
//     }

//     for(int k = 0; argv[k]; k++){
//         printf("[%d] -> %s\n", k, argv[k]);
//     }

//     return 0;
// }


//sample of simulate shell
// int split(char* commandstr, char* argv[]){
//     assert(commandstr);
//     assert(argv);

//     argv[0] = strtok(commandstr, SEP);
//     if(argv[0] == NULL){
//         return -1;
//     }

//     int i = 1;
//     while(1){
//         argv[i] = strtok(NULL, SEP);
//         if(argv[i] == NULL){
//             break;
//         }
//         i++;
//     }
//     return 0;
// }

// void debugPrint(char* argv[]){
//     for(int i = 0; argv[i]; i++){
//         printf("[%d]: %s\n", i, argv[i]);
//     }
// }

// int main(){
//     while(1){
//         //char *strtok(char *str, const char *delim);
//         char commandstr[MAX] = {0};
//         char* argv[ARGC] = {NULL};
//         printf("[ChuHsiang@mymachine currpath]# ");
//         fflush(stdout);//刷新缓冲区

//         //char *fgets(char *s, int size, FILE *stream);
//         char* s = fgets(commandstr, sizeof(commandstr), stdin);
//         assert(s);
//         (void)s;

//         //ls-a\n\0 --> ls-a\0
//         commandstr[strlen(commandstr) - 1] = '\0';//将'\n'覆盖掉

//         //split --e.g 
//         int n = split(commandstr, argv);
//         if(n != 0){
//             continue;
//         }
//         // debugPrint(argv);

//         pid_t id = fork();
//         assert(id >= 0);
//         (void)id;

//         if(id == 0){
//             //child
//             //程序替换
//             execv(argv[0], argv);
//             exit(1);
//         }
//         int status = 0;
//         waitpid(id,&status,0);
//     }
// }

//replace of process
// int main(){
//     pid_t id = fork();
//     assert(id >= 0);
//     (void)id;

//     if(id ==0){
//         printf("我是子程序, pid: %d, ppid: %d\n", getpid(), getppid());
//         execl("/bin/ls", "ls", "-a", "-l", NULL);
//         printf("子程序还在呢!\n");
//     }
//     sleep(5);
//     while(1){
//         int status = 0;
//         pid_t ret_id = waitpid(id, &status, WNOHANG);
//         if(ret_id < 0){
//             printf("waitpid error!\n");
//             exit(0);
//         }else if(ret_id == 0){
//             printf("子程序还活着呢!\n");
//             continue;
//         }else{
//             printf("我是父进程, 我的pid: %d, child exit code: %d, child exit signal: %d\n",\
//                 getpid(), (status>>8)&0xFF, status & 0x7F);
//             break;
//         }
//     }
// }

// int main(){
//     pid_t id = fork();
//     assert(id >= 0);
//     (void)id;

//     if(id == 0){

//         printf("我是子程序, pid: %d, ppid: %d\n", getpid(), getppid());
//         char* const myargv[] = {
//             "ls",
//             "-a",
//             "-n",
//             NULL
//         };
//         execv("/bin/ls", myargv);
//         printf("you failed!\n");
//     }
//     sleep(5);
//     while(1){
//         int status = 0;
//         pid_t ret_id = waitpid(id, &status, WNOHANG);
//         if(ret_id < 0){
//             printf("waitpid error!\n");
//             exit(0);
//         }else if(ret_id == 0){
//             printf("子程序还活着呢!\n");
//             continue;
//         }else{
//             printf("我是父进程, 我的pid: %d, child exit code: %d, child exit signal: %d\n",\
//                 getpid(), (status>>8)&0xFF, status & 0x7F);
//             break;
//         }
//     }
// }

// int main(){
//     pid_t id = fork();
//     assert(id >= 0);
//     (void)id;

//     if(id == 0){
//         //child
//         printf("我是子进程, PID: %d\n", getpid());
//         execlp("ls", "ls", "-a", "-i", NULL);
//         printf("you fail\n");
//     }
//     //father
//     sleep(5);
//     int status = 0;
//     printf("我是父进程, PID: %d\n", getpid());
//     waitpid(id, &status, 0);
//     printf("child exit code: %d\n", WEXITSTATUS(status));
// }

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

// int main(){
//     pid_t id = fork();
//     if(id == 0){
//         //子进程
//         printf("我是子进程, PID: %d\n", getpid());
//         execl("./exec/otherproc","otherproc",NULL);
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

// int split(char* commandstr, char* argv[]){
//     assert(commandstr);
//     assert(argv);

//     argv[0] = strtok(commandstr,  SEP);
//     if(argv[0] == NULL){
//         return -1;
//     }

//     int i = 1;
//     while(1){
//         argv[i] = strtok(NULL, SEP);
//         if(argv[i] == NULL){
//             break;
//         }
//         i++;
//     }
//     return 0;
// }

// void debugPrint(char* argv[]){
//     for(int i = 0; argv[i]; i++){
//         printf("[%d]: %s\n", i, argv[i]);
//     }
// }

// int main(){
//     while(1){
//         char commandstr[MAX] = {0};
//         char* argv[ARGC] = {NULL};
//         printf("[ChuHsiang@HuaweiCloud]# ");
//         fflush(stdout);

//         char* s = fgets(commandstr, sizeof(commandstr), stdin);
//         assert(s);
//         (void)s;

//         commandstr[strlen(commandstr) - 1] = '\0';//覆盖掉'\n'
//         int n = split(commandstr, argv);
//         if( n!= 0){
//             continue;
//         }

//         // debugPrint(argv);

//         pid_t id = fork();
//         assert(id >= 0);
//         (void)id;

//         if(id == 0){
//             //child and replace of procecc
//             execv(argv[0],argv);
//             exit(1);
//         }
//         //father
//         int status = 0;
//         waitpid(id, &status, 0);
//         // sleep(100);
//     }
// }

// int main(){
//     //practice of replace of process
//     pid_t id = fork();
//     assert(id >= 0);
//     (void)id;

//     if(id == 0){
//         //child
//         char* myargv[] = {
//             "ls",
//             "-a",
//             "-l",
//             NULL
//         };

//         execv("/bin/ls", myargv);
//         int cnt = 5;
//         while(cnt){
//             printf("我是子程序, 我还有%dS, pid: %d, ppid: %d\n", cnt--, getpid(), getppid());
//             sleep(1);
//         }
//     }
//     //father
//     while(1){
//         int status = 0;
//         pid_t ret_id = waitpid(id, &status, WNOHANG);
//         if(ret_id < 0){
//             printf("waitpid error!\n");
//             exit(1);
//         }else if(ret_id == 0){
//             printf("子进程还活着呢!, 你可以干其他的事情.\n");
//             sleep(1);
//             continue;
//         }else{
//             printf("我是父进程, 我的pid: %d, ppid: %d, child exit code: %d, child exit signal: %d\n",\
//                 getpid(), getppid(), WEXITSTATUS(status), status & 0x7F);
//             break;
//         }
//     }
// }

//simulate shell
int split(char* commandstr, char* argv[]){
    assert(commandstr);
    assert(argv);

    argv[0] = strtok(commandstr, SEP);
    if(argv[0] == NULL){
        return -1;
    }

    int i = 1;
    while(1){
        argv[i] = strtok(NULL, SEP);
        if(argv[i] == NULL){
            break;
        }
        i++;
    }
    return 0;
}

void debugPrint(char* const argv[]){
    for(int i = 0; argv[i]; i++){
        printf("[%d]: %s\n", i, argv[i]);
    }
}

int main(){
    //ls -a -l
    while(1){
        char commandstr[MAX] = {0};
        char* argv[ARGC] = {NULL};
        
        printf("[ChuHsiang@HuaWeiCloud]# ");
        fflush(stdout);
        // sleep(100);

        char* s = fgets(commandstr, sizeof(commandstr), stdin);
        assert(s);
        (void)s;
        commandstr[strlen(commandstr) - 1] = '\0';

        int n = split(commandstr, argv);
        if(n != 0){
            continue;
        }
        // debugPrint(argv);

        pid_t id = fork();
        assert(id >= 0);
        (void)id;
        if(id == 0){
            //child
            //replace of process
            execv(argv[0],argv);
            exit(1);
        }
        int status = 0;
        waitpid(id, &status, 0);
    }
}