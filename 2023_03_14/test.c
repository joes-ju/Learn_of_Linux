#include<stdio.h>
#include<unistd.h>

int main(){
    int count = 0;
    while(1){
      printf("我是进程，%d\n",count++);
      sleep(1);
    }
    return 0;
}
