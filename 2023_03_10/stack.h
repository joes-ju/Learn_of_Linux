#pragma once
#include<iostream>
#include<vector>
#include<list>
using namespace std;

namespace joes
{
  template<class T,class Container>
  class stack
  {
    public:
      void push(const T& x)
      {
        return _con.push_back(x);
      }

      void pop()
      {
        return _con.pop_back();
      }

      const T& top()
      {
        return _con.back();
      }

      size_t size()
      {
        return _con.size();
      }

      bool empty()
      {
        return _con.empty();
      }

    private:
      Container _con;
  };

  void test_stack01()
  {
    stack<int,vector<int>> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    while(!s1.empty())
    {
      cout<<s1.top()<<" ";
      s1.pop();
    }
    cout<<endl;
  }

  void test_stack02()
  {
    stack<int,list<int>> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    while(!st.empty())
    {
      cout<<st.top()<<" ";
      st.pop();
    }
    cout<<endl;
  }

}
