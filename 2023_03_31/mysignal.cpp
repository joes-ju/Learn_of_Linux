#include<iostream>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
using namespace std;

void handler(int signo){
    cout<<"我们的进程收到了："<< signo <<"信号导致崩溃的"<<endl;
    exit(1);
}

void showBlock(sigset_t *oset){
    int signo = 1;
    for(; signo <= 31; signo++){
        if(sigismember(oset,signo)){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }
    cout<<endl;
}

int main(){
    //案例：对2号信号屏蔽
    sigset_t set, oset;//oset(old set) -- 在栈上开辟的，在用户层面上
    sigemptyset(&set);//清空对应的信号集
    sigemptyset(&oset);

    sigaddset(&set,2);//SIGINT
    //设置进进程，谁调用，设置谁
    sigprocmask(SIG_SETMASK,&set,&oset);//1. 2号信号没反应； 2.我们看到老的信号屏蔽字block位图是全零
    int cnt = 1;
    while(true){
        showBlock(&oset);
        sleep(1);
        cnt++;

        if(cnt == 10){
            cout<<"recover blocK:";
            sigprocmask(SIG_SETMASK,&oset,&set);
            showBlock(&set);
        }
    }




    // // #define SIG_DFL	((__sighandler_t) 0)		/* Default action.  */
    // // #define SIG_IGN	((__sighandler_t) 1)		/* Ignore signal.  */
    // // signal(2,SIG_DFL);
    // signal(2,SIG_IGN);

    // while(true){
    //     sleep(1);
    // }


    // pid_t id = fork();
    // if(id == 0){
    //     sleep(2);
    //     cout<<"野指针问题...here"<<endl;
    //     cout<<"野指针问题...here"<<endl;
    //     cout<<"野指针问题...here"<<endl;

    //     int *p = nullptr;
    //     *p = 100;//2.野指针问题
    //     cout<<"野指针问题...here"<<endl;
    //     cout<<"野指针问题...here"<<endl;
    //     cout<<"野指针问题...here"<<endl;
    //     cout<<"野指针问题...here"<<endl;
    //     exit(0);
    // }
    // int status = 0;
    // waitpid(id,&status,0);
    // cout<<"exit code: "<<((status>>8)&0xFF)<<endl;
    // cout<<"exit signal: "<<(status & 0x7F)<<endl;
    // cout<<"core dump flag: "<<((status>>7)& 0x1)<<endl;


    // cout<<"野指针问题...here"<<endl;
    // cout<<"野指针问题...here"<<endl;
    // cout<<"野指针问题...here"<<endl;

    // int *p = nullptr;
    // *p = 100;//2.野指针问题
    // cout<<"野指针问题...here"<<endl;
    // cout<<"野指针问题...here"<<endl;
    // cout<<"野指针问题...here"<<endl;
    // cout<<"野指针问题...here"<<endl;


    // while(true){
    //     cout<<"我是一个正常进程，正在模拟某种异常："<<getpid()<<endl;
    //     sleep(1);
    // }

    // signal(SIGFPE,handler);
    // int a = 10;
    // a /= 0;
    // cout<< "div zero ... here" <<endl;
    return 0;
}