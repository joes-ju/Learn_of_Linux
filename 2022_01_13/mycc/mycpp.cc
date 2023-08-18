#include<iostream>
#include<queue>
using namespace std;

void test_queue01(){
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    cout<<"The number of queue1: "<<q1.size()<<endl;
    while(!q1.empty()){
        cout<<q1.front()<<" ";
        q1.pop();
    }
    cout<<endl;
}

int main(){
    test_queue01();
    return 0;
}