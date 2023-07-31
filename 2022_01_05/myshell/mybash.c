#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

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

void debugPrint(char *argv[]){
    for(int i = 0; argv[i]; i++)
    {
        printf("%d: %s\n", i, argv[i]);
    }
}


int main(){


    while (1){
        char commandstr[MAX] = {0};
        char* argv[ARGC] = {NULL};
        printf("[ChuHsiang@mymachine currpath]# ");
        fflush(stdout);//需要刷新，因为数据被暂时写在缓冲区
        //char *fgets(char *s, int size, FILE *stream);      char *fgets(char *s, int size, FILE *stream);
        char* s = fgets(commandstr, sizeof(commandstr), stdin);
        assert(s);
        (void)s;//保证在realease方式发布时，因为去掉assert了，所以s就没有被使用，因而带来编译警告;什么都没做，但是充当一次使用

        commandstr[strlen(commandstr) - 1] = '\0';//去掉'\n'
        //ls -a -l  --> "ls" "-a" "-l"
        //切割
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
            execvp(argv[0], argv);
            exit(1);
        }
        int status = 0;
        waitpid(id, &status, 0);
        // printf("%s\n",commandstr);
        // sleep(100);
    }
    
    return 0;
}