#include<iostream>
#include<cstring>
#include<sys/types.h>
#include<unistd.h>

using namespace std;

int main(){
    cout <<"我是C++编辑的子进程, pid: "<< getpid() <<endl;
    return 0;
}