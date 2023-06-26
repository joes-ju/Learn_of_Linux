#include "comm.hpp"
#include<unistd.h>

int main(){
    //1.创建key
    key_t k = getKey();
    cout<<"server: "<< toHex(k) <<endl;

    //2.创建共享内存
    int shmid = creatShm(k, gsize);
    cout<<"server shmid: "<< toHex(shmid) <<endl;
    sleep(3);

    //3.将自己和共享内存关联起来
    char *start = attachShm(shmid);
    sleep(20);

    //通信代码
    
    //4.将自己和共享内存去关联
    detachShm(start);
    sleep(3);
    
    //删除共享内存 -- “谁创建谁删除，谁污染谁治理”
    delShm(shmid);

    return 0;
}