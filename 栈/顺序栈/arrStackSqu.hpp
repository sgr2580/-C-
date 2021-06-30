//
//creat by sgr on 2021/6/30
//

#include "arrStack.h"
#include <iostream>

using namespace std;

template <class T>
arrStack<T>::arrStack(T) :m_pTop(-1), m_nStackLen(capacity)
{
	arr = new T[capacity];
}