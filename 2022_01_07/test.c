#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX 1024
#define ARGC 64
#define SEP " "

int split(char* commandstr, char* argv[]){
    assert(commandstr);
    assert(argv);

    argv[0] = strtok(commandstr, SEP);
    if(argv[0] == NULL){
        return -1;
    }

    int i = 1;
    while(1){
        argv[i] = strtok(NULL,SEP);
        if(argv[i] == NULL){
            break;
        }
        i++;
    }
    return 0;
}

void debugPrint(char* argv[]){
    for(int i = 0; argv[i]; i++){
        printf("[%d]: %s\n", i, argv[i]);
    }
}

void showEnv(){
    extern char** environ;
    for(int i = 0; environ[i]; i++){
        printf("%d: %s\n", i, environ[i]);
    }
}

int main(){
    int last_exit = 0;

    char myenv[32][256];
    int env_index = 0;
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

        int n = split(commandstr,argv);
        if(n != 0){
            continue;
        }
        // debugPrint(argv);
        //version 2 : 说明几个细节

        //cd .. /cd/ 等 bash自己执行的命令，称之为内建命令/内置命令  --> int chdir(const char *path);
        if(strcmp(argv[0], "cd") == 0){
            if(argv[1] != NULL){
                //说到底，cd命令，重要的表现就如同bash自己调用了对应的函数
                chdir(argv[1]);
            }
            continue;//不会往下继续执行，回到while(1)重新开始
        }else if(strcmp(argv[0], "export") == 0){
            if(argv[1] != NULL){
                strcpy(myenv[env_index], argv[1]);
                putenv(myenv[env_index++]);
            }
            continue;
        }else if(strcmp(argv[0], "env") == 0){
            showEnv();
            continue;
        }else if(strcmp(argv[0], "echo") == 0){
            //echo $PATH
            const char* target_env = NULL;
            if(argv[1][0] == '$'){
                if(argv[1][1] == '?'){
                    printf("%d\n", last_exit);
                    continue;
                }else{
                    target_env = getenv(argv[1]+1);
                }
            }
            if(target_env != NULL){
                printf("%s=%s\n", argv[1]+1, target_env);
            }

            continue;
        }

        // else if(strcmp(argv[0], "export") == 0){
        //     if(argv[1] != NULL){
        //         putenv(argv[1]);
        //     }
        //     continue;
        // }

        if(strcmp(argv[0], "ls") == 0){
            int pos = 0;
            while(argv[pos]){
                pos++;
            }
            argv[pos++] = (char*)"--color=auto";
            argv[pos] = NULL;//比较安全的做法
        }

        //version 1
        pid_t id = fork();
        assert(id >= 0);
        (void)id;

        if(id == 0){
            //child
            // execvp(argv[0], argv);
            execvp(argv[0], argv);
            exit(1);
        }
        int status = 0;
        pid_t ret_id = waitpid(id, &status, 0);
        if(ret_id > 0){
            last_exit = WEXITSTATUS(status);
        }
    }
}

//一般用户自定义的环境变量，在bash中要用户自己进行维护，不要用一个经常被覆盖的缓冲区来保存环境变量