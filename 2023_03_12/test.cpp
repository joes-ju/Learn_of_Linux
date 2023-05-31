#include<iostream>
#include<vector>
using namespace std;

void test_vector01(){
  vector<int> t1;
  t1.push_back(1);
  t1.push_back(0);
  t1.push_back(0);
  t1.push_back(8);
  t1.push_back(6);

  vector<int>::iterator it = t1.begin();
  while(it!=t1.end()){
    cout<<*it<<" ";
    ++it;
  }
  cout<<endl;

  for(auto e: t1){
    cout<<e<<" ";
  }
  cout<<endl;
}

int main(){
  test_vector01();
  return 0;
}
