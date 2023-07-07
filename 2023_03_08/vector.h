#include<assert.h>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;

namespace joes
{
  template<class T>
  class vector
  {
    public:
      typedef T* iterator;
      typedef const T* const_iterator;

      vector()
        :_start(nullptr)
         ,_finish(nullptr)
         ,_end_of_storage(nullptr)
      {}

      iterator begin()
      {
        return _start;
      }

      iterator end()
      {
        return _finish;
      }

      size_t size()
      {
        return _finish - _start;
      }

      size_t capacity()
      {
        return _end_of_storage - _start;
      }

      void reserve(size_t n)
      {
        if(n > capacity())
        {
          size_t sz = size();
          T* tmp = new T[n];
          if(_start)
          {
            memcpy(tmp,_start,sizeof(T)*size());
            delete[] _start;
          }
          _start = tmp;
          _finish = tmp + sz;
          _end_of_storage = tmp + n;
        }
      }

      void push_back(const T& x)
      {
        if(_finish == _end_of_storage)
        {
          reserve(capacity()==0?4:2*capacity());
        }
        *_finish = x;
        ++_finish;
      }

      T& operator[](size_t pos)
      {
        assert(pos < size());

        return _start[pos];
      }



    private:
      iterator _start;
      iterator _finish;
      iterator _end_of_storage;
  };

  void test_vector01()
  {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    for(size_t i = 0; i < v1.size();++i)
    {
      cout<<v1[i]<<" ";
    }
    cout<<endl;

    vector<int>::iterator it = v1.begin();
    while(it != v1.end())
    {
      cout<<*it<<" ";
      ++it;
    }
    cout<<endl;

    for(auto e : v1)
    {
      cout<<e<<" ";
    }
    cout<<endl;
  }
}
