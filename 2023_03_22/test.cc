#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> t1;
    t1.push_back(1);
    t1.push_back(2);
    t1.push_back(3);
    t1.push_back(4);
    cout<<t1.size()<<endl;
    vector<int>::iterator it = t1.begin();
    while(it!=t1.end()){
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
    return 0;
}
