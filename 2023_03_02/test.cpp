#include<iostream>
using namespace std;

int addToTop(int top)
{
    cout<<"enter addToTop"<<endl;

    int sum = 0;
    for(int i = 0;i<=top;i++)
    {
        sum += i;
    }
    cout<<"quit addToTop"<<endl;
    return sum;
}


int main()
{
    int top = 100;
    int result = addToTop(top);
    cout<<"result: "<<result<<endl;
    return 0;
}
