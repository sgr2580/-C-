#include <iostream>
#include "linkstack.h"
#include "NoMem.h"
#include <string>

using namespace std;

void test01()
{
	//����һ��˳��ջ
	try {
		
	}
	catch (...)
	{
		cerr << "An exception has occurred" << endl;
	}
}

void test02()
{
	//����һ������ջ
	try {
		
	}
	catch (...)
	{
		cerr << "An exception has occurred" << endl;
	}
}

int main()
{
	test01();

	//test02();

	system("pause");
	return 0;
}