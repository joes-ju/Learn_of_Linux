//该文件放置共享内存的封装
#ifndef __COMM_HPP__
#define __COMM_HPP__

#include<iostream>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<cerrno>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<string>
using namespace std;

// IPC_CREAT and IPC_EXCL
//单独使用IPC_CREAT: 创建一个共享内存，如果共享内存不存在就创建；如果已经存在，获取已经存在的共性内存并返回
//IPC_EXCL不能单独使用，一般都要配合IPC_CREAT
//IPC_CREAT | IPC_EXCL :创建一个共享内存，如果共享内存不存在就创建；如果已经存在，则立马出错返回  -- 如果创建成功，对应的shm

#define PATHNAME "."
#define PROJID 0x6666

const int gsize = 4096;//暂时

key_t getKey(){
    key_t k = ftok(PATHNAME, PROJID);
    if(k == -1){
        cerr<< "error: "<< errno << " : "<< strerror(errno) <<endl;
        exit(1);
    }
    return k;
}

string toHex(int x){
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "0x%x", x);
    return buffer;
}

static int creatShmHelper(key_t k, int size, int flag){
    int shmid = shmget(k, gsize, flag);
    if(shmid == -1){
        cerr<< "error: " << errno << " : " << strerror(errno) << endl;
        exit(2);
    }
    return shmid;
}

//创建共享内存
int creatShm(key_t k, int size){
    umask(0);
    return creatShmHelper(k, size, IPC_CREAT | IPC_EXCL | 0666);
}

//获取共享内存
int getShm(key_t k, int size){
    return creatShmHelper(k, size, IPC_CREAT);
}

char *attachShm(int shmid){
    char *start = (char*)shmat(shmid, NULL, 0);
    return start;
}

void *detachShm(char *start){
    int n = shmdt(start);
    assert(n != -1);
    (void)n;
}

void delShm(int shmid){
    int n = shmctl(shmid, IPC_RMID, nullptr);
    assert(n != -1);
    (void)n;
    
}

#endif