#include"comm.hpp"
#include<unistd.h>

int main(){
    Init init(SERVER);
    //start 就已经执行共享内存的起始空间
    char *start = init.getStart();

    int n = 0;
    while(n <= 30){
        cout<< "client -> server: " << start <<endl;
        sleep(1);
        n++;
    }


    // //1.创建key值
    // key_t k = keyGet();
    // cout<< "server key: " << toHex(k) << endl;

    // //2.创建shm
    // int shmid = createShm(k, gsize);
    // cout<< "server shmid: " << shmid << endl;
    // sleep(3);
    // //3.将自己和共享内存关联起来
    // char *start = attachShm(shmid);
    // sleep(20);
    // //将自己和共享内存去关联
    // detachShm(start);
    // sleep(3);

    // //删除共享内存
    // delShm(shmid);

    return 0;
}