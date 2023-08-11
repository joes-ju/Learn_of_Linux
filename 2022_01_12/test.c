#include"mystdio.h"
#include<string.h>
#include<unistd.h>
#include<stdbool.h>

#define MYFILE "log.txt"

// int main(){
//     MY_FILE* fp = my_fopen(MYFILE, "w");
//     if(fp == NULL){
//         return 1;
//     }

//     const char* str = "hello my fwrite";
//     int cnt = 0;
//     //操作文件
//     while(true){
//         char buffer[1024];
//         //int snprintf(char *str, size_t size, const char *format, ...);
//         snprintf(buffer,sizeof(buffer),"%s: %d\n",str,cnt++);
//         size_t size = my_fwrite(buffer,strlen(buffer),1,fp);
//         sleep(1);
//         printf("当前成功写入: %lu个字节\n",size);
//     }

//     my_fclose(fp);
//     return 0;
// }

int main(){
    int a = 123456;//是一个整数
    printf("%d\n",a);//123456 被打印成为一个字符串，这是 数据格式转换的问题，printf做的
}