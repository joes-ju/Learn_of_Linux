#include<iostream>
#include<string>
using namespace std;


void Func(const string& s)
{
	//只能遍历和读容器的数据内容，不能写
	string::const_iterator cit = s.cbegin();
	while (cit != s.cend())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}

//普通迭代器与const迭代器最大的区别是const迭代器只能读不能写

void string_test01()
{
	string s1("hello world");
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//反向迭代器
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	//const_iterator -- const迭代器
	Func(s1);

}

void string_test02()
{
	string s1("hello world");
	//常量反向迭代器 -- 只能读不能写
	//string::const_reverse_iterator crit = s1.crbegin();
	auto crit = s1.crbegin();
	while (crit != s1.crend())
	{
		cout << *crit << " ";
		++crit;
	}
	cout << endl;
}


//迭代器像指针，但又不完全是

//element access
void string_test03()
{
	//[] at
	//[]越界会直接报错(断言)，at越界抛异常
	string s1("hello world");
	try
	{
		s1.at(100);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	cout << s1.front() << endl;
	cout << s1.back() << endl;//size-1
}

//modifilers -- +=/append/push_back/assign/insert/erase/replace/pop_back
void string_test04()
{
	string s1;
	string s2("hello world");
	//assign是一种赋值
	s1.assign(s2);
	cout << s1 << endl;
	s1.assign("welcome to nit");
	cout << s1 << endl;
	s1.assign("pangrams are cool", 7);
	cout << s1 << '\n';
	s1.assign(10, '*');
	cout << s1 << endl;


	//insert
	s2.insert(0, "welcome");
	s2.insert(7, 1,' ');//s2[7]处插入一个空格
	cout << s2 << endl;
	s2.insert(s2.begin() + 5, 'p');
	cout << s2 << endl;

	//erase
	s2.erase(5, 1);//s2[5]删除一个字符
	cout << s2 << endl;
	s2.erase(s2.begin() + 5);
	cout << s2 << endl;

	//replae尽量少用
	s2.replace(5, 1,"%%d");//此处扩容、挪动数据
	cout << s2 << endl;

	string s3("I love china and my hometown");
	//find
	size_t pos = s3.find(' ');
	if (pos != string::npos)
	{
		s3.replace(pos, 1, "%20");
		pos = s3.find(' ',pos+3);
	}
	cout << s3 << endl;
}

//空格替换成-->  %20
void string_test05()
{
	string s1("I love my motherland and hometown");
	size_t num = 0;
	for (auto ch : s1)
	{
		if (ch == ' ')
		{
			++num;
		}
	}

	//提前开辟空间，避免replace时扩容
	s1.reserve(s1.size() + 2 * num);

	size_t pos = s1.find(' ');
	while (pos != string::npos)
	{
		s1.replace(pos, 1, "%20");
		pos = s1.find(' ', pos + 3);
	}
	cout << s1 << endl;

	//以空间换时间
	string s2("I love my motherland and hometown");
	string newStr;
	for (auto ch : s2)
	{
		if (ch != ' ')
		{
			newStr += ch;
		}
		else
		{
			newStr += "%20";
		}
	}
	s2 = newStr;
	cout << newStr << endl;
	cout << "s2: " << s2 << endl;
}

//string::swap与std::swap
//string::swap改变指向的位置即可，故效率高
void string_test06()
{
	string s1("hello world");
	string s2("xxxxxxxxxxx");
	s1.swap(s2);
	cout << s1 << endl;
	cout << s2 << endl;

	swap(s1, s2);
	cout << s1 << endl;
	cout << s2 << endl;
}

//string operator
void string_test07()
{
	string s1("hello world");
	cout << s1 << endl;
	cout << s1.c_str() << endl;//返回的是char* _str

	s1 += '\0';
	s1 += '\0';
	s1 += "xxxxxx";
	cout << s1 << endl;//按流插入去打印，依据size，不管'\0'
	cout << s1.c_str() << endl;//char* 遇到'\0'就终止了


}

void string_test08()
{
	string filename("test.cpp");
	FILE* fout = fopen(filename.c_str(), "r");
	if (fout == nullptr)
	{
		perror("fopen fail");
	}

	char ch = fgetc(fout);
	while (ch != EOF)
	{
		cout << ch;
		ch = fgetc(fout);
	}
	fclose(fout);
}

int main()
{
	string_test08();
	return 0;
}


