#include<iostream>
#include<cstdio>
#include<cerrno>
#include<cstring>
#include<cassert>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include"comm.hpp"


int main(){
    //1.不需要创建管道文件，我们只需要打开对应的文件
    int wfd = open(fifoname.c_str(),O_WRONLY);
    if(wfd < 0){
        std::cerr<<errno<<":"<<strerror(errno)<<std::endl;
        return 1;
    }

    //2.可以进行常规通信
    char buffer[NUM];
    while(true){
        std::cout<<"请输入你的信息# ";
        char *msg = fgets(buffer,sizeof(buffer),stdin);
        assert(msg);
        (void)msg;

        buffer[strlen(buffer)-1] = 0;
        if(strcmp(buffer,"quit") == 0){
            break;
        }

        ssize_t n = write(wfd,buffer,strlen(buffer));;
        assert(n >= 0);
        (void)n;
    }
    
    close(wfd);
}