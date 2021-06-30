#include <iostream>
#include "arrStackSqu.hpp"
#include "linkstack.hpp"
#include "NoMem.h"
#include <string>

using namespace std;

void test01()
{
	//测试一下顺序栈
	try {
		int k = 0;
		int x;
		arrStack<int> int_arr_stack(8);
		int_arr_stack.print();
		cout << "The capacity of stack is " << int_arr_stack.GetLength() << endl;
		while (k < 12)
		{
			int_arr_stack.Push(k);
			++k;
			//int_arr_stack.print();
		}
		cout << "Top elem is " << int_arr_stack.GetTop() << endl;
		cout << "the capacity of stack is " << int_arr_stack.GetLength() << endl;
		int_arr_stack.print();
		int_arr_stack.Pop(x);
		cout << "New top elem is " << int_arr_stack.GetTop() << endl;
		int_arr_stack.Clear();
		//int_arr_stack.print();
		cout << "---------------------------------" << endl;
	}
	catch (...)
	{
		cerr << "An exception has occurred" << endl;
	}
}

void test02()
{
	//测试一下链接栈
	try {
		Stack<int> intstack;
		cout << "len of stack is " << intstack.GetLength() << endl;
		int nums = 0;
		if (intstack.IsEmpty())
		{
			cout << "intstack is empty!" << endl;
		}
		cout << "after push nums: " << endl;
		while (nums<5)
		{
			intstack.Push(nums);
			nums++;
		}
		cout << "len of stack is " << intstack.GetLength() << endl;
		intstack.print();
		int x;
		int y;
		intstack.Pop(x);
		cout << "x的值：" << x << endl;
		intstack.print();
		if (intstack.GetTop(y))
			cout << "top elem is " << y << endl;
		if (!intstack.IsEmpty())
			cout << "intstack is not empty!" << endl;
		intstack.Clear();
		cout << "len of stack is " << intstack.GetLength() << endl;
		cout << "---------------------------------" << endl;
	}
	catch (...)
	{
		cerr << "An exception has occurred" << endl;
	}
}

int main()
{
	//test01();

	test02();
	
	system("pause");
	return 0;
}