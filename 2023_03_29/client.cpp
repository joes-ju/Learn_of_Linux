#include"comm.hpp"
#include<unistd.h>

int main(){
    Init init(CLIENT);

    char *start = init.getStart();
    char c = 'A';
    while(c <= 'Z'){
        start[c - 'A'] = c;
        c++;
        start[c - 'A'] = '\0';
        sleep(1);
    }

    // //创建key值
    // key_t k = keyGet();
    // cout<< "client key: " << toHex(k) << endl;

    // //创建shm
    // int shmid = getShm(k, gsize);
    // cout<< "client shmid: " << shmid <<endl;

    // //将自己和共享内存关联起来
    // char* start = attachShm(shmid);
    // sleep(15);

    // //将自己和共享内存去关联
    // detachShm(start);

    return 0;
}