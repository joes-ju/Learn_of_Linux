#pragma once

#include<iostream>
#include<functional>
#include<vector>
#include<unistd.h>

//约定，每一个command都必须是4字节
#define COMMAND_LOG 0
#define COMMAND_MYSQL 1
#define COMMAND_REQUEST 2

typedef void (*func_t)(); //函数指针


void PrintLog(){
    std::cout<<"pid"<<getpid()<<", 打印日志任务，正在被执行..."<<std::endl;
}

void InsertMYSQL(){
    std::cout<<"执行数据库任务，正在被执行..."<<std::endl;

}

void NetRequest(){
    std::cout<<"执行网络请求任务，正在被执行..."<<std::endl;
}

// void ExitProcess(){
//     exit(0);
// }

class Task{
public:
    Task(){
        funcs.push_back(PrintLog);
        funcs.push_back(InsertMYSQL);
        funcs.push_back(NetRequest);
    }

    void Execute(int command){
        if(command >= 0 && command < funcs.size()){
            funcs[command]();
        }
    }

    ~Task(){}


public:
    std::vector<func_t> funcs;
};