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
	void enqueue(ElemType e)		//	入队
	{
		if (length == capacity)
			throw "队已满，无法再入队";
		items[tail] = e;
		tail = (tail + 1) % capacity;
		length++;
	}
	ElemType dequeue()				//	出队
	{		
		if (length == 0)
			throw "队已空，无法再出队";
		ElemType e = items[head];
		head = (head + 1) % capacity;
		length--;
		return e;
	}
	void output()
	{
		cout << "队列当前保有的元素有：";
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