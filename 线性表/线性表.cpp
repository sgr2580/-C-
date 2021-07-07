#include <iostream>
#include "LinearListSqu.hpp"
#include "LinearList.h"
#include "NoMem.h"
#include "LinearLIstLink.hpp"
#include "Doublelist.hpp"

using namespace std;

//˳������
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

//�����������
void test02()
{
	LinearListLink<int> c;
	cout << "�½�����:	" << endl;
	cout << "�����Ƿ�Ϊ�գ�   " << c.IsEmpty() << endl;
	cout << "����ĳ��ȣ�    " << c.Length() << endl;
	cout << "����Ϊ��     " << c << endl << endl;

	//�����������
	c.Insert(0, 1);
	c.Insert(1, 2);
	c.Insert(2, 3);
	c.Insert(3, 4);


	int value = 0;

	c.Find(2, value);
	cout << "����Find()����---c.Find(2,x):" << endl;
	cout << "xΪ��" << value << endl << endl;
}

int main()
{
	//text01();


	test02();

	system("pause");
	return 0;
}