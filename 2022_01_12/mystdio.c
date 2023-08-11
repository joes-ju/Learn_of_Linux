#include"mystdio.h"
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<assert.h>

MY_FILE* my_fopen(const char* path, const char* mode){
    //1.识别标志位
    int flag = 0;
    if(strcmp(mode,"r") == 0){
        flag |= O_RDONLY;
    }else if(strcmp(mode,"w") == 0){
        flag |= (O_CREAT | O_WRONLY | O_TRUNC);
    }else if(strcmp(mode,"a") == 0){
        flag |= (O_CREAT | O_WRONLY | O_APPEND);
    }else{
        //other operator...
        //e.g "r+"/"w+"/"a+"...
    }

    //尝试打开文件
    mode_t m = 0666;
    int fd = 0;
    if(flag & O_CREAT){
        fd = open(path,flag,m);
    }else{
        fd = open(path,flag);
    }

    if(fd < 0){
        return NULL;
    }

    //3.给用户返回MY_FILE对象，需要先 进行构建
    MY_FILE* mf = (MY_FILE*)malloc(sizeof(MY_FILE));
    if(mf == NULL){
        close(fd);
        return NULL;
    }

    //4.初始化MY_FILE对象
    mf->fd = fd;
    mf->flag = 0;
    mf->flag = BUFF_LINE;
    memset(mf->outputbuffer,'\0',sizeof(mf->outputbuffer));
    mf->current = 0;
    // mf->outputbuffer[0] = 0;//初始化缓冲区 

    //5.返回打开的文件
    return mf;
}
//注意：当关闭文件的时候（fclose(FILE*))，C语言帮助我们冲刷缓冲区


//行刷新
int my_fflush(MY_FILE* fp){
    assert(fp);

    //将用户缓冲区中的数据，通过系统调用接口，冲刷给OS
    write(fp->fd,fp->outputbuffer,fp->current);
    fp->current = 0;
    //todo
    //fsync系统强制刷新
    fsync(fp->fd);
    return 0;
}


//该接口特定文件流中写入特定大小的数字
size_t my_fwrite(const void* ptr, size_t size, size_t nmemb, MY_FILE* stream){
    //1.缓冲区如果已经满了，直接写入
    if(stream->current == NUM){
        my_fflush(stream);
    }

    //2.根据缓冲区剩余情况，进行数据拷贝即可
    size_t user_size = size * nmemb;
    size_t my_size = NUM - stream->current;
    size_t writen = 0;
    if(my_size >= user_size){
        memcpy(stream->outputbuffer + stream->current, ptr, user_size);
        //3.更新计数器字段
        stream->current += user_size;
        writen = user_size;
    }else{
        memcpy(stream->outputbuffer + stream->current, ptr, my_size);//空间不足时，自己有多少拷贝多少
        //3.更新计数器字段
        stream->current += my_size;
        writen = my_size;
    }

    //4.开始计划刷新
    //不发生刷新的本质，不进行写入，就是不进行IO，不进行调用系统调用，所以my_fwrite函数调用会非常快，数据会保存在缓冲区中；
    //可以在缓冲区中积压多份数据，统一进行刷新写入，--本质：就是一次IO可以IO更多的数据，提高IO效率
    if(stream->flag & BUFF_ALL ){
        if(stream->current == NUM){
            //满了
            my_fflush(stream);
        }
    }else if(stream->flag & BUFF_LINE){
        if(stream->outputbuffer[stream->current - 1] == '\n'){
            my_fflush(stream);
        }
    }else{
        //todo
    }
    
    return writen;
}



int my_fclose(MY_FILE* fp){
    assert(fp);

    //1.冲刷缓冲区
    if(fp->current > 0){
        my_fflush(fp);
    }
    //2.关闭文件
    close(fp->fd);
    //3.释放空间
    free(fp);
    //4.指针置NULL -- 可以设置
    fp = NULL;
}

// int my_scanf();

int my_printf(const char* format,...){
    //1.先获取对应的变量 

    //2.定义缓冲区，对a转换成字符串 
    //2.1 fwrite(stdout,str);
    //3.将字符串拷贝到stdout->buffer，即可
    //4.结合刷新策略显示
}
