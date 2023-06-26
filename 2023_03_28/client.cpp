#include "comm.hpp"
#include<unistd.h>

int main(){
    key_t k = getKey();
    cout<<"client: "<< toHex(k) <<endl;

    int shmid = getShm(k,gsize);
    cout<<"client shmid: "<<toHex(shmid)<<endl;

    //3.将自己和共享内存关联起来
    char *start = attachShm(shmid);
    sleep(5);

    //4.将自己和共享内存去关联
    detachShm(start);

    return 0;
}