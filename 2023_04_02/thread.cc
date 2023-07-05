#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<cstdio>
#include<cassert>
#include<cerrno>
#include<string>
#include<ctime>
using namespace std;

void *threadRun(void* args){
    const char* name = static_cast<const char*>(args); // const char* name =  (const char*)args;
    int cnt = 5;
    while(cnt){
        cout<< name << " is runing: "<< cnt-- <<"obtain self id: "<< pthread_self() <<endl;
        sleep(1);
    }

    pthread_exit((void*)11);
}

int main(){
    pthread_t tid;
    pthread_create(&tid, nullptr, threadRun, (void*)"thread 1");
    // sleep(3);

    //线程取消
    // pthread_cancel(tid);

    void *ret = nullptr;
    pthread_join(tid, &ret);

    cout<<" new thread exit: "<< (int64_t)ret << "  quit thread: " << tid <<endl;
    return 0;
}


// #define NUM 10
//枚举类型
// enum{
//     OK = 0,
//     ERROR
// };

// class ThreadData{
//     public:
//     ThreadData(const string& name, int id, const time_t time, int top)
//         :_name(name)
//         ,_id(id)
//         ,_createTime((uint64_t)time)
//         ,_status(OK)
//         ,_top(top)
//         ,_result(0)
//     {}

//     ~ThreadData(){

//     }
// public:
//     //输入的
//     string _name;
//     int _id;
//     uint64_t _createTime;

//     //返回的
//     int _status;
//     int _top;
//     int _result;
//     // char arr[n];
// };


//线程终止
//1.线程函数执行完毕
// void *thread_run(void* args){
//     char *name = (char*)args;
//     while(true){
//         cout<<"new thread running, my thread name is: "<< name <<endl;
//         sleep(4);
//         break;
//     }
//     delete name;
//     return nullptr;
// }

//2.pthread_exit(void*)
// void *thread_run(void* args){
//     // char *name = (char*)args;
//     ThreadData *td = static_cast<ThreadData *> (args);
//     // while(true){
//     //     cout<<"new thread running, my thread name is: "<< name <<endl;
//     //     //exit(10);//进程退出，不是线程退出，只要有任何一个线程调用exit，整个进程（所有线程）全部退出
//     //     sleep(4);
//     //     break;
//     // }

//     for(int i = 1; i < td->_top; i++){
//         td->_result += i;
//     }

//     cout<<td->_name<<"cal done!"<<endl;
//     pthread_exit(td);
//     // return td;

//     // while(true){
//     //     cout<<"thread is  running, name is: "<< td->_name << " create time: "<< td->_createTime << " index: "<< td->_id <<endl;
//     //     //exit(10);//进程退出，不是线程退出，只要有任何一个线程调用exit，整个进程（所有线程）全部退出
//     //     sleep(4);
//     //     break;
//     // }

//     // delete name;

//     // delete td;
//     // pthread_exit((void*)2);
// }




// int main(){
//     pthread_t tids[NUM];
//     // for(int i = 0; i < NUM; i++){
//     //     char *tname = new char[64];
//     //     snprintf(tname, 64, "thread-%d", i+1);
//     //     pthread_create(tids+i,nullptr,thread_run,tname);
//     // }

//     for(int i = 0; i < NUM; i++){
//         char tname[64];
//         snprintf(tname, 64, "thread-%d", i+1);
//         ThreadData *td = new ThreadData(tname, i+1, time(nullptr), 100+5*i);

//         pthread_create(tids+i,nullptr,thread_run,td);
//         sleep(1);
//     }

//     void *ret = nullptr;

//     //等待
//     for(int i = 0; i < NUM; i++){
//         // int n = pthread_join(tids[i],nullptr);
//         int n = pthread_join(tids[i], &ret);
//         if(n != 0){ 
//             cerr<<"pthread_join error"<<endl;
//         }

//         ThreadData *td = static_cast<ThreadData *> (ret);
//         if(td->_status == OK){
//             cout<< td->_name <<"计算的结果是："<< td->_result << "(它要计算的是[1, "<< td->_top << "])"<<endl;
//         }
//         // cout<<"thread quit: "<< (uint64_t)ret <<endl;

//         delete td;
//     }

//     cout<<"all thread quit..."<<endl;



//     // sleep(3);

//     // while(true){
//     //     cout<<"main thread running, new thread id: "<<endl;
//     //     sleep(1);
//     // }
//     return 0;
// }