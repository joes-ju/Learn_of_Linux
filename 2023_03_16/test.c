#include<stdio.h>
#include<unistd.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

//void test01(){
//  for(int i = 0;envp[i];i++){
//      printf("envp[%d]->%s\n",i,envp[i]);
//  }
//}
//
//int main(int argc,char *argv[],char *envp[]){
//  //test01();
//  for(int i = 0;envp[i];i++){
//      printf("envp[%d]->%s\n",i,envp[i]);
//  }
//  return 0;
//}
//

int main(){
    pid_t id = fork();
    if(id > 0){
        while(1){
            printf("我是父进程，PID：%d，PPID：%d\n",getpid(),getppid());
            sleep(1); 
        }
    }else if(id == 0){
        while(1){
            printf("我是子进程，PID：%d，PPID：%d\n",getpid(),getppid());
            sleep(1); 
        } 
    }
    return 0;
}
