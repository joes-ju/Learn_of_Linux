#include<iostream>
#include<string>
#include<unistd.h>
#include<cassert>
#include<vector>
#include<sys/wait.h>
#include<sys/types.h>
#include"Task.hpp"
using namespace std;

const int gum = 3;
Task t;

//父进程要管理自己创建的管道和进程 -- 先描述，再组织；
class EndPoint{
private:
    static int number;
public:
    pid_t _child_id;
    int _write_fd;
    std::string processname;

    EndPoint(int id,int fd)
        :_child_id(id)
        ,_write_fd(fd)
    {
        //process-0[pid:fd]
        char namebuffer[64];
        snprintf(namebuffer,sizeof(namebuffer),"process-%d[%d:%d]",number++,_child_id,_write_fd);
        processname = namebuffer;
    }

    std::string name() const 
    {
        return processname;
    }

    ~EndPoint(){

    }
};

int EndPoint::number = 0;

//子进程要执行的方法
void WaitCommand(){
 
    while(true){
        int command = 0;
        int n = read(0,&command,sizeof(int));
        if(n == sizeof(int)){
            //每个command都是4个字节
            t.Execute(command);
        }else if(n == 0){
            std::cout<<"父进程让我退出，我就退出了: "<<getpid()<<std::endl;
            break;
        }else{
            break;
        }
    }
}

void creatProcesses(vector<EndPoint> *end_points){
    // vector<int> fds;
    //1.先进行构建控制结构，父进程写入，子进程读取
    for(int i = 0;i < gum; i++){
        //1.1创建管道
        int pipefd[2]={0};
        int n = pipe(pipefd);
        assert(n == 0);
        (void)n;

        //1.2创建进程
        pid_t id = fork();
        assert(id != -1);
        //一定是子进程
        if(id == 0){
            //1.3关闭不要的fd
            close(pipefd[1]);
            //我们期望所有子进程读取“指令”的时候，都从标准输入读取
            //1.3.1 输入重定向，也可以不做
            dup2(pipefd[0],0);
            //1.3.2 子进程开始等待获取命令
            WaitCommand();

            close(pipefd[0]);
            exit(0);
        }

        //一定是父进程
        //1.3关闭不要的fd
        close(pipefd[0]);

        //1.4将新的子进程和它的管道写端，构建对象
        end_points->push_back(EndPoint(id,pipefd[1]));

    }
}

int ShowBoard(){
    std::cout<<"###################################"<<std::endl;
    std::cout<<"# 0.执行日志任务   1.执行数据库任务 #"<<std::endl;
    std::cout<<"# 2.执行请求任务   3.退出          #"<<std::endl;
    std::cout<<"###################################"<<std::endl;
    std::cout<<"请选择#";
    int command = 0;
    std::cin >> command;
    return command;
}

void ctrlProcess(const vector<EndPoint> &end_points){
    //我们可以写成自动化的，也可以搞成交互式的
    int num = 0;
    int cnt = 0;
    while(true){
        //2.1 选择任务
        int command = ShowBoard();
        if(command == 3){
            break;
        }
        if(command < 0 || command > 2){
            continue;
        }

        //2.2 选择进程
        int index = cnt++;
        cnt %= end_points.size();
        std::string name = end_points[index].name();
        std::cout<<"选择了进程："<<name<<"|处理任务："<<command<<std::endl;
        // std::cout<<"选择了进程："<<end_points[index].name()<<"处理任务："<<command<<std::endl;

        //2.3 下发任务
        write(end_points[index]._write_fd,&command,sizeof(command));
        sleep(1);
    }
}

void waitProcess(const vector<EndPoint> &end_points){
    //3.1 需要让子进程全部退出  -- 只需要让父进程关闭所有的write fd就可以
    // for(const auto &ep : end_points){
    for(int end = end_points.size()-1; end>=0; end--){
        std::cout<<"父进程让所有的子进程全部退出"<<end_points[end]._child_id<<::endl;
        close(end_points[end]._write_fd);

        waitpid(end_points[end]._child_id,nullptr,0);
        std::cout<<"父进程回收了所有的子进程"<<end_points[end]._child_id<<std::endl;
    }
    sleep(10);

    //3.2 父进程要回收子进程的僵尸状态
    // for(const auto &ep:end_points){
    //     waitpid(ep._child_id,nullptr,0);
    // }
    // std::cout<<"父进程回收了所有的子进程"<<std::endl;
    // sleep(10);
}


int main(){
    vector<EndPoint> end_points;
    creatProcesses(&end_points);

    //2.我们得到了什么？end_points
    ctrlProcess(end_points);

    //3.处理所有的退出问题
    waitProcess(end_points);
    
    return 0;
}