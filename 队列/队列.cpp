#include <iostream>
#include "ListQueue.hpp"
#include "LinkQueue.hpp"


using namespace std;

//À≥–Ú—≠ª∑∂”¡–≤‚ ‘
void test01()
{
	try {
		ListQueue<int> list_queue(10);
		cout << "is empty? " << list_queue.IsEmpty() << endl;
		cout << "is full? " << list_queue.IsFull() << endl;
		for (int i = 0; i < 10; i++)
		{
			list_queue.Insert(i);
			list_queue.print();
			cout << "--------------" << endl;
		}
		cout << "is empty? " << list_queue.IsEmpty() << endl;
		cout << "is full? " << list_queue.IsFull() << endl;
		int a;
		list_queue.Delete(a);
		cout << "a = " << a << endl;
		list_queue.print();
		int b = 100;
		list_queue.Insert(b);
		list_queue.print();
		list_queue.Delete(a);
		list_queue.print();
		cout << "the length of queue is " << list_queue.getlength() << endl;
		cout << list_queue.getHead() << endl;
		cout << list_queue.getTail() << endl;
		list_queue.erase();
		cout << "is empty? " << list_queue.IsEmpty() << endl;
	}
	catch (...)
	{
		cerr << "An exception has occurred" << endl;
	}
}


void test02()
{
	try {
		LinkQueue<int> link_queue;
		cout << link_queue.IsEmpty() << endl;
		cout << link_queue.getlength() << endl;
		link_queue.getHead();
		link_queue.getTail();
	
		cout << "-----------------------------" << endl;
		for (int i = 0; i < 5; i++)
		{
			link_queue.Insert(i);
		}
		cout << link_queue.IsEmpty() << endl;
		cout << link_queue.getlength() << endl;
		cout << "Front is : " << link_queue.getHead() << endl;
		cout << "Rear is : " << link_queue.getTail() << endl;
		link_queue.print();
		int x;
		link_queue.Delete(x);
		cout << "X : " << x << endl;
		cout << link_queue.getlength() << endl;
		cout << "Front is : " << link_queue.getHead() << endl;
		cout << "Rear is : " << link_queue.getTail() << endl;
		link_queue.print();
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