#include"mystdio.h"

MY_FILE* my_fopen(const char* path, const char* mode){
    //1.识别标志位
    int flags = 0;
    if(strcmp(mode,"r") == 0){
        flags |= O_RDONLY;
    }else if(strcmp(mode,"w") == 0){
        flags |= (O_CREAT | O_WRONLY | O_TRUNC);
    }else if(strcmp(mode, "a") == 0){
        flags |= (O_CREAT | O_WRONLY | O_APPEND);
    }else{
        //
    }

    //2.打开文件
    mode_t m = 0;
    int fd = 0;
    if(flags & O_CREAT){
        fd = open(path,mode,m);
    }else{
        fd = open(path,mode);
    }

    if(fd < 0){
        return NULL;
    }
}
int my_fflush(MY_FILE* fp);
size_t my_fwrite(const void* ptr, size_t size, size_t nmemb, MY_FILE* stream);
int my_fclose(MY_FILE* fp);