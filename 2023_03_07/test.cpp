#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include<algorithm>
using namespace std;

//template<class T,class Alloc=allocator<T> > class vector;//generic template       其中allocator空间配置器
//vector其实就是数组（动态顺序表）  管理任意类型数组
//与string的操作很像

//member function
//include: constructor/deconstructor/operator=
void vector_test01()
{
	vector<int> v;//无参构造
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//遍历vector --> 三种常见的方式
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	//auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//魔法糖不能倒着遍历
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> copy(v);//拷贝构造
	for (auto e : copy)
	{
		cout << e << " ";
	}
	cout << endl;
}


void vector_test02()
{
	vector<int> v1(10, 1);//10个1
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v2(v1.begin(), v1.end());//迭代器区间
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

	string s1("hello world");
	vector<char> v3(s1.begin()+3, s1.end());
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
}


//Iterator
//include: begin/end/rbegin/rend/cbegin/cend/crbegin/crend
void vector_test03()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//vector<int>::reverse_iterator rit = v.rbegin();
	auto rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}


//capacity
//include: size/capacity/resize/reserve

void vector_test04()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	cout << v.size() << endl;
	cout << v.max_size() << endl;
}

void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	v.reserve(100);
	sz = v.capacity();
	cout << "making v grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	}
}
//shrink_to_fit 缩容，尽量不要使用

void vector_test05()
{
	vector<int> v1;
	v1.resize(10, 0);
	for (auto i : v1)
	{
		cout << i << " ";
	}
	cout << endl;

	vector<int> v2(10, 0);
	for (auto i : v2)
	{
		cout << i << " ";
	}
	cout << endl;
}

//Element access
//include: operator[]/at/front/back/data
void vector_test06()
{
	vector<int> v;
	v.push_back(11);
	v.push_back(22);
	v.push_back(33);
	v.push_back(44);

	cout << v.front() << endl;
	cout << v.back() << endl;
	cout << v[2] << endl;
}



//Modifiers
//include: push_back/pop_back/insert/erase/swap/clear/

void vector_test07()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (auto e:v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>::iterator pos = find(v.begin(), v.end(), 2);
	if (pos != v.end())
	{
		v.insert(pos,20);
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;


	pos = find(v.begin(), v.end(), 2);
	if (pos != v.end())
	{
		v.erase(pos);
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin());
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

//vector<char> 不能完全替代 string；string有'\0'

int main()
{
	vector_test07();
	//TestVectorExpand();
	return 0;
}
