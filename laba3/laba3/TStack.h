#pragma once

#include<iostream>

template <class ValueType>
class TStack
{
private:

	int i;
	int N;
	ValueType *ts;
public:
	TStack(int n);
	TStack(const TStack &s);
	~TStack();
	void sPush(int el);
	ValueType sTop();
	bool isEmpty();
	bool isFull();
	void Pop();
};

template<class ValueType>
TStack<ValueType>::TStack(int n)
{
	i = -1;
	N = n;
	ts = new ValueType[N];
}

template<class ValueType>
TStack<ValueType>::TStack(const TStack<ValueType> &s)
{
	N = s.N;
	i = s.i;
	ts = new int[N];
	for (int j = 0; j <= i; j++) ts[j] = s.ts[j];
}

template<class ValueType>
TStack<ValueType>::~TStack()
{
	delete[] ts;
}

template<class ValueType>
void TStack<ValueType>::sPush(int el)
{
	if (isFull()) throw "error";
	i++;
	//std::cout << i << std::endl;
	ts[i] = el;
}

template<class ValueType>
ValueType TStack<ValueType>::sTop()
{
	return (ts[i]);
}

template<class ValueType>
bool TStack<ValueType>::isFull()
{
	return (i >= N);
}

template<class ValueType>
bool TStack<ValueType>::isEmpty()
{
	return (i == -1);
}

template <class ValueType>
void TStack<ValueType>::Pop()
{
	if (isEmpty()) throw "error";
	i--;
}