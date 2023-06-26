#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add_to_top(int top){
    printf("enter add_to_top\n");
    int sum = 0;
    for(int i = 0; i <= top; i++){
      sum += i;
    }
    //exit(123);
    _exit(111);
    printf("out add_to_top\n");
    return sum;
}

int main(){
    printf("hello world\n");
    //printf("hello world");//输出缓冲区 -- 文件系统
    sleep(2);
    exit(107);


    //int result = add_to_top(100);
    //if(result == 5050){
    //    return 0;
    //}else{
    //    return 11;//计算结果不正确
    //}
   // 
   
  //  for(int i = 0; i <= 200; i++){
  //      printf("%d : %s\n",i,strerror(i));
  //      exit(123);
  //  }
    return 0;
}
