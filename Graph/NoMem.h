#pragma once
//异常类
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
class OutOdBounds
{
public:
	OutOdBounds()
	{
		cout << "out of bounts" << endl;
	}
};