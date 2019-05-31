#pragma once
#include <iostream>
using namespace std;
template<typename ElemType>
struct Queue {
	ElemType * items;
	int capacity;
	int head, tail;
	int length;
	Queue(int c = 100)
	{
		head = tail = 0;
		length = 0;
		capacity = c;
		items = new ElemType[capacity];
	}
	~Queue()
	{
		delete[]items;
	}
	void enqueue(ElemType e)		//	���
	{
		if (length == capacity)
			throw "���������޷������";
		items[tail] = e;
		tail = (tail + 1) % capacity;
		length++;
	}
	ElemType dequeue()				//	����
	{		
		if (length == 0)
			throw "���ѿգ��޷��ٳ���";
		ElemType e = items[head];
		head = (head + 1) % capacity;
		length--;
		return e;
	}
	void output()
	{
		cout << "���е�ǰ���е�Ԫ���У�";
		for (int i = 0 ; i < length ; i ++ )
		{
			cout << items[(i+head)%capacity] << " ";
		}
		cout << endl;
	}
	bool isEmtpy()
	{
		return length == 0;
	}
};