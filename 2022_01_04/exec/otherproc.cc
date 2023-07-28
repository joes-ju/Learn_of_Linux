#include<iostream>
#include<unistd.h>
#include<sys/types.h>
using namespace std;

int main(){
    for(int i = 0; i < 5; i++){
        cout<<"我是另一个程序, 我的PID是: "<< getpid() <<endl;
        sleep(1);
    }
    return 0;
}