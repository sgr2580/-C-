//�쳣��
#pragma once
#include <iostream>
using namespace std;

//�ڴ治��
class NoMem
{
public:
	NoMem()
	{
		cout << "memory is not enough" << endl;
	}
};

//Խ��
class OutOfBounds
{
public:
	OutOfBounds()
	{
		cout << "out of bounts" << endl;
	}
};
