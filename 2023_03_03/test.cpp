#include<iostream>
#include<string>
using namespace std;

void string_test01()
{
    string s;
    cout<<sizeof(s)<<endl;
    size_t sz = s.capacity();
    cout<<"making s grow:\n"<<endl;
    cout<<"capacity changed:"<<endl;
    for(int i = 0; i < 100; i++)
    {
        s.push_back('c');
        if(sz != s.capacity())
        {
            sz = s.capacity();
            cout<<"capacity changed:"<<sz<<endl;
        }
    }
    
}
void string_test02()
{
    string s1("hello world");
    string s2(s1);
    string s3("hello nit",6,3);
    string s4(10,'*');
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;

}

void string_test03()
{
    string s;
    s.reserve(100);
    size_t sz = s.capacity();
    cout<<"making s grow:"<<endl;
    cout<<"capacity changed:"<<endl;
    for(int i = 0; i < 100; i++)
    {
        s.push_back('c');
        if(sz != s.capacity())
        {
            sz = s.capacity();
            cout<<"capacity changed:"<<sz<<endl;
        }
    }
}

void string_test04()
{
    //reserve扩容
    string s1("hello world");
    s1.reserve(100);
    cout<<s1.size()<<endl;
    cout<<s1.capacity()<<endl;
    //resize扩容+初始化
    string s2("hello world");
    s2.resize(100);
    cout<<s2.size()<<endl;
    cout<<s2.capacity()<<endl;

    //比size小，删除数据，保留前5个
    s2.resize(5);
    cout<<s2.size()<<endl;
    cout<<s2.capacity()<<endl;
    //缩容不支持原地缩容,缩容一般开辟一个新的空间后将原来数据拷贝到新开辟的空间，一般不建议缩容
}

void string_test05()
{
    //about iterator
    string s1("hello world");
    //begin指第一个位置，end表示最后一个数据的下一个即d的后一个
    string::iterator it = s1.begin();
    while(it != s1.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;

    //范围for的底层是迭代器
    for(auto e:s1)
    {
        cout<<e<<" ";
    }
    cout<<endl;
}

int main()
{
    string_test05();
    return 0;
}
