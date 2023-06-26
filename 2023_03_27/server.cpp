#include<iostream>
#include<cerrno>
#include<cstring>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include"comm.hpp"

int main(){
    //1.创建管道文件（一次创建）
    umask(0);//这个设置不会影响系统的默认配置，只会影响当前进程
    int n = mkfifo(fifoname.c_str(),mode);
    if(n != 0){
        std::cout<<errno<<":"<<strerror(errno)<<std::endl;
        return 1;
    }
    std::cout<<"creat fifo file success"<<std::endl;

    //2.让服务端直接开启管道文件
    int rfd = open(fifoname.c_str(),O_RDONLY);//读端
    if(rfd < 0){
        std::cout<<errno<<":"<<strerror(errno)<<std::endl;
        return 2;
    }
    std::cout<<"open fifo success, begin ipc"<<std::endl;

    //3.正常通信
    char buffer[NUM];
    while(true){
        buffer[0] = 0;
        ssize_t n = read(rfd,buffer,sizeof(buffer)-1);
        if(n > 0){
            buffer[n] = 0;
            std::cout<<"client: "<<buffer<<std::endl;
        }else if(n == 0){
            std::cout<<"client quit,me too"<<std::endl;
            break;
        }else{
            std::cout<<errno<<":"<<strerror(errno)<<std::endl;
            break;
        }
    }

    //关闭不要的fd
    close(rfd);
    unlink(fifoname.c_str());
    return 0;
}