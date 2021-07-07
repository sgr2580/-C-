#include <iostream>
#include "LinearListSqu.hpp"
#include "LinearList.h"
#include "NoMem.h"
#include "LinearLIstLink.hpp"
#include "Doublelist.hpp"

using namespace std;

//顺序表测试
void text01()
{
	try {
		LinearListSqu<int> L(5);
		cout << "Length = " << L.Length() << endl;
		cout << "IsEmpty = " << L.IsEmpty() << endl;
		bool ok = false;
		ok = L.Insert(0, 2);
		if (!ok)
		{
			cout << "OK" << endl;
		}

		L.Insert(1, 6);
		L.Insert(2, 8);
		cout << "List is " << L << endl;
		cout << "IsEmpty = " << L.IsEmpty() << endl;

		int z;
		L.Find(1, z);
		cout << "First element is " << z << endl;
		cout << "Length  = " << L.Length() << endl;
		L.Delete(1, z);
		cout << "Delete element is " << z << endl;
		cout << "List is " << L << endl;
	}
	catch (...)
	{
		cerr << "An exception has occurred" << endl;
	}
}

//单向链表测试
void test02()
{
	LinearListLink<int> c;
	cout << "新建链表:	" << endl;
	cout << "链表是否为空：   " << c.IsEmpty() << endl;
	cout << "链表的长度：    " << c.Length() << endl;
	cout << "链表为：     " << c << endl << endl;

	//插入测试数据
	c.Insert(0, 1);
	c.Insert(1, 2);
	c.Insert(2, 3);
	c.Insert(3, 4);


	int value = 0;

	c.Find(2, value);
	cout << "测试Find()函数---c.Find(2,x):" << endl;
	cout << "x为：" << value << endl << endl;
}

int main()
{
	//text01();


	test02();

	system("pause");
	return 0;
}