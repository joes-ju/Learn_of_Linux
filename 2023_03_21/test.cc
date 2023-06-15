#include<iostream>
#include<cstdio>

int main(){
    //因为Linux下一切皆为文件，所以向显示器打印，本质就是向文件中写入。
    //c 
    printf("hello printf->stdout\n");
    fprintf(stdout,"hello fprintf->stdout\n");
    fprintf(stderr,"hello fprintf->stderr\n");

    //c++
    std::cout<<"hello cout -> cout"<<std::endl;
    std::cerr<<"hello cerr -> cerr"<<std::endl;

}
