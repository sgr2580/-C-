//异常类
#pragma once
#include <iostream>
using namespace std;

//内存不足
class NoMem
{
public:
	NoMem()
	{
		cout << "memory is not enough" << endl;
	}
};

//越界
class OutOfBounds
{
public:
	OutOfBounds()
	{
		cout << "out of bounts" << endl;
	}
};
