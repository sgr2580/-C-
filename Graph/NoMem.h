#pragma once
//�쳣��
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
class OutOdBounds
{
public:
	OutOdBounds()
	{
		cout << "out of bounts" << endl;
	}
};