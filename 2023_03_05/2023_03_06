#pragma once
#include<assert.h>
#include<string.h>
#include<iostream>
using namespace std;

namespace joes
{
  class string
  {
    public:
      typedef char* iterator;
      typedef const char* const_iterator;

      iterator begin()
      {
        return _str;
      }

      iterator end()
      {
        return _str+_size;
      }

      const_iterator begin() const
      {
        return _str;
      }

      const_iterator end() const
      {
        return _str+_size;
      }

      /*string()
        :_str(new char[0])
         ,_size(0)
         ,_capacity(0)
      {
        _str[0] = '\0';
      }*/

      //一个类一般要提供一个默认的构造函数以及一个缺省的构造函数

      //string(const char* str = nullptr)不可以
      string(const char* str = " " )
        :_size(strlen(str))
      {
        _capacity = _size == 0? 3 : _size;
        _str = new char[_capacity+1];
        strcpy(_str,str);
      }
      
      //深拷贝
      string(const string& s)
        :_size(s._size)
         ,_capacity(s._capacity)
      {
        _str = new char[s._capacity + 1];
        strcpy(_str,s._str);

      }


      size_t size() const
      {
        return _size;
      }

      size_t capacity() const
      {
        return _capacity;
      }

      const char* c_str()
      {
        return _str;
      }

      char& operator[](size_t pos) 
      {
        assert(pos < _size);

        return _str[pos];
      }

      const char& operator[](size_t pos) const
      {
        assert(pos < _size);
        return _str[pos];
      }

      //深拷贝的赋值s1=s3
      string& operator=(const string& str)
      {
        if(this != &str)
        {
          /*delete[] this->_str;
          this->_str = new char[str._capacity + 1];
          strcpy(_str,str._str);
          _size = str._size;
          _capacity = str._capacity;*/

          char* tmp = new char[str._capacity + 1];
          strcpy(tmp,str._str);
          delete[] _str;
          _str = tmp;
          _size = str._size;
          _capacity = str._capacity;
        }

        return *this;
      }

      void Print(const string& s)
      {
        for(size_t i = 0; i < s.size(); ++i)
        {
          cout<<s[i]<<" ";
        }
        cout<<endl;

        string::const_iterator it = s.begin();
        while(it != s.end())
        {
          cout<<*it<<" ";
          ++it;
        }
      }

      bool operator>(const string& s) const
      {
        return strcmp(_str,s._str)>0; 
      }

      bool operator==(const string& s) const
      {
        return strcmp(_str,s._str)==0;
      }

      bool operator>=(const string& s) const
      {
        return *this>s || *this==s;
      }

      bool operator<(const string& s) const
      {
        return !(*this>=s);
      }

      bool operator<=(const string& s) const
      {
        return *this<s || *this==s;
      }

      bool operator!=(const string& s) const
      {
        return !(*this == s);
      }

      //不修改成员变量数据的函数，最好都加上const
      
      //reserve扩容
      void reserve(size_t n)
      {
        //防止缩容
        if(n > _capacity)
        {
          char* tmp = new char[n+1];
          strcpy(tmp,_str);
          delete[] _str;
          _str = tmp;
          _capacity = n ;
        }
      }

      void push_back(char ch)
      {
        if(_size+1 >= _capacity)
        {
          reserve(2*_capacity);
        }
          _str[_size++] = ch;
          _str[_size]='\0';
      }

      void append(const char* str)
      {
        size_t len = strlen(str);
        if(_size+len > _capacity)
        {
          reserve(_size+len);
        }
        strcpy(_str+_size,str);
        _size+=len;
      }

      string& operator+=(char ch)
      {
        push_back(ch);
        return *this;
      }

      string& operator+=(const char* str)
      {
        append(str);
        return *this;
      }

      void resize(size_t n, char ch = '\0')
      {
        //resize不会缩容
        if(n < _size)
        {
          //删除数据，保留前n个
          _size = n;
          _str[_size] = '\0';
        }
        else if(n > _size)
        {

          if(n > _capacity)
          {
            reserve(n);
          
          }
          size_t i = _size;
          while(i < n)
          {
            _str[i++] = ch;
          }
          _size = n;
          _str[_size] = '\0';
        }
      }

      void insert(size_t pos, char ch)
      {
        assert(pos <= _size);
        if(_size+1 > _capacity)
        {
          reserve(_capacity * 2);
        }
        //注意，防止头插问题
        size_t end = _size + 1;
        while(end >= pos)
        {
          _str[end] = _str[end-1];
          --end;

        }
        _str[pos] = ch;
        ++_size;
      }

      void insert(size_t pos, const char* str)
      {
        assert(pos <= _size);

        size_t len = strlen(str);
        //扩容
        if(_size+len > _capacity)
        {
          reserve(_size+len);
        }
        //挪动数据
        size_t end = _size+len;
        while(end > pos+len-1)
        {
          _str[end] = str[end-len];
          --end;
        }
        //拷贝插入
        strncpy(_str+pos,str,len);
        _size+=len;
      }

      //从pos位置开始删除len个字符
      void erase(size_t pos, size_t len = npos)
      {
        assert(pos <= _size);
        
        if(len == npos || pos+len >= _size)
        {
          _str[pos]='\0';
          _size=pos;
        }
        else
        {
          strcpy(_str+pos,_str+pos+len);
          _size -= len;
        }
      }



      ~string()
      {
        delete[] _str;
        _str = nullptr;
        _size = _capacity = 0;
      }



    private:
      char* _str;
      size_t _size;
      size_t _capacity;

      static const size_t npos;//静态成员变量不可以给缺省值
  };

  const size_t string::npos = -1;

  void test01()
  {
    string s1;
    string s2("hello world");
    cout<<s1.c_str()<<endl;
    cout<<s2.c_str()<<endl;
    
    s2[0]++;
    cout<<s1.c_str()<<endl;
    cout<<s2.c_str()<<endl;
  }

  void test02()
  {
    string s1;
    string s2("hello world");
    string s3(s2);

    cout<<"s1: "<<s1.c_str()<<endl;
    cout<<"s2: "<<s2.c_str()<<endl;
    cout<<"s3: "<<s3.c_str()<<endl;

    s2[0]++;
    cout<<"s2: "<<s2.c_str()<<endl;
    cout<<"s3: "<<s3.c_str()<<endl;

    s1 = s3;
    cout<<"s1: "<<s1.c_str()<<endl;
    cout<<"s3: "<<s3.c_str()<<endl;
  }

  void test03()
  {
    string s1("hello world");
    for(size_t i = 0; i < s1.size(); ++i)
    {
      s1[i]++;
    }
    cout<<endl;

    for(size_t i = 0; i < s1.size(); ++i)
    {
      cout<<s1[i]<<" ";
    }
    cout<<endl;

    s1.Print(s1);

    string::iterator it = s1.begin();
    while(it != s1.end())
    {
      (*it)--;
      ++it;
    }
    while(it != s1.end())
    {
      cout<<*it<<" ";
      ++it;
    }
    cout<<endl;

    for(auto ch : s1)
    {
      cout<<ch<<" ";
    }
    cout<<endl;
  }

  void test04()
  {
    string s1("hello world");
    string s2("hello world");
    string s3("xx");

    cout<<(s1 < s2)<<endl;
    cout<<(s1 == s2)<<endl;
    cout<<(s1 >= s3)<<endl;
  }

  void test05()
  {
    string s1("hello world");
    /*s1.push_back(' ');
    s1.append("xxxxxxxxxxxxxxxxxxx");
    cout<<s1.c_str()<<endl;*/

    s1 += ' ';
    s1 += "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    cout<<s1.c_str()<<endl;
  }

  void test06()
  {
    string s1("hello world");

    s1.insert(5,'x');
    cout<<s1.c_str()<<endl;
  }

  void test07()
  {
    string s1;
    s1.resize(20,'x');
    cout<<s1.c_str()<<endl;
    s1.resize(30,'y');
    cout<<s1.c_str()<<endl;

    s1.resize(10);
    cout<<s1.c_str()<<endl;
  }

  void test08()
  {
    string s1("11111111");
    s1.insert(0,'x');
    cout<<s1.c_str()<<endl;

    s1.insert(3,'x');
    cout<<s1.c_str()<<endl;

    s1.insert(3,"yyy");
    cout<<s1.c_str()<<endl;
    s1.insert(0,"yyy");
    cout<<s1.c_str()<<endl;
  }

  void test09()
  {
    string s1("11111111");
    cout<<s1.c_str()<<endl;

    s1.erase(4,3);
    cout<<s1.c_str()<<endl;

    s1.erase(4,30);
    cout<<s1.c_str()<<endl;

    s1.erase(2);
    cout<<s1.c_str()<<endl;
  }
}
