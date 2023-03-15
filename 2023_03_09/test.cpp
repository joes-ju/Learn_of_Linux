#include<iostream>
#include<list>
#include<vector>
#include<deque>
#include<algorithm>
#include<time.h>
using namespace std;

void test_list01()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_list02()
{
	list<int> lt1;
	lt1.assign(7, 100);
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int> lt2;
	lt2.assign(lt1.begin(), lt1.end());
	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list03()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	for (auto e : l1)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int>::iterator pos = find(l1.begin(), l1.end(), 3);
	if (pos != l1.end())
	{
		l1.insert(pos,30);
	}
	for (auto e : l1)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list04()
{
	list<int> lt;
	lt.push_back(10);
	lt.push_back(2);
	lt.push_back(5);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(4);
	lt.push_back(84);
	lt.push_back(6);
	lt.push_back(4);
	lt.push_back(0);
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	reverse(lt.begin(), lt.end());
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.remove(3);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.sort();
	lt.sort();
	//迭代器功能分类
	//1、单向 ++
	//2、双向 ++ --
	//3、随机 ++ -- + -
	//sort(lt.begin(),lt.end())
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	//先排序才能实现去重
	lt.unique();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list05()
{
	srand(time(0));
	const int N = 10000000;
	vector<int> v;
	v.reserve(N);

	list<int> lt1;
	list<int> lt2;
	deque<int> dq;
	for (int i = 0; i < N; ++i)
	{
		auto e = rand();
		lt2.push_back(e);
	}

	int begin1 = clock();
	for (auto e : v)
	{
		v.push_back(e);
	}
	sort(v.begin(), v.end());

	int end1 = clock();

	int begin2 = clock();
	lt2.sort();
	int end2 = clock();

	cout << "vector sort:" << (end1 - begin1) << endl;
	cout << "list sort:" << (end2 - begin2) << endl;
}

int main()
{
	//test_list01();
	//test_list02();
	//test_list04();
	test_list05();

	return 0;
}
