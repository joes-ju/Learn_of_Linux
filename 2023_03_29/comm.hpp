#include<iostream>
#include<string>
#include<cassert>
#include<cstring>
#include<cstdio>
#include<cerrno>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/shm.h>
using namespace std;

#define PATHNAME "."
#define PROJID 0x6666

//共享内存得大小是以page页（4kB)为单位的
const int gsize = 4096;

//创建key值
key_t keyGet(){
    //
    key_t k = ftok(PATHNAME,PROJID);
    if(k == -1){
        cout<<"error: "<<errno<<" : "<<strerror(errno)<<endl;
        exit(1);
    }
    return k;
}

//转换为十六进制
string toHex(int x){
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "0x%x", x);
    return buffer;
}

static int createShmHelper(size_t k, int size, int flag){
    int shmid = shmget(k, size, flag);//key值为k（是路径和项目id值得转换获得）
    if(shmid == -1){
        cout<<"error: "<<errno<<" : "<<strerror(errno)<<endl;
        exit(2);
    }
    return shmid;
}

//创建共享内存
int createShm(key_t k, int size){
    umask(0);//系统调用函数
    return createShmHelper(k, gsize, IPC_CREAT|IPC_EXCL|0666);
}

//获取共享内存
int getShm(key_t k, int size){
    return createShmHelper(k, gsize, IPC_CREAT);
}


//attach共享内存
char *attachShm(int shmid){
    char *start = (char*)shmat(shmid, nullptr, 0);
    return start;
}

//取消关联
void detachShm(char *start){
    int n = shmdt(start);
    assert(n != -1);
    (void)n;
}

//删除shm
void delShm(int shmid){
    int n = shmctl(shmid, IPC_RMID, nullptr);
    assert(n != -1);
    (void)n;
}

#define SERVER 1
#define CLIENT 0

class Init{
public:
    Init(int t)
        :type(t)
    {
        key_t k = keyGet();
        if(type == SERVER){
            shmid = createShm(k, gsize);
        }else{
            shmid = getShm(k, gsize);
        }
        start = attachShm(shmid);
    }

    char *getStart(){
        return start;
    }

    ~Init(){
        detachShm(start);
        if(type == SERVER){
            delShm(shmid);
        }
    }
private:
    char *start;
    int type;//server or client
    int shmid;
};