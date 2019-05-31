#pragma once
#include <iostream>
#include "Queue-Point.h"
using namespace std;

#define M 8
Point direction[M] = {
	Point{-1,-1},	//左上
	Point{-1,0},	//上
	Point{0,-1},	//左
	Point{-1,1},	//右上
	Point{1,-1},	//左下
	Point{1,0},		//下
	Point{0,1},		//右
	Point{1,1},		//右下
};

void printPath(Point c)
{
	Point p = c;
	Point p1 = previous[p.y][p.x];
	if (p1.x == 0 && p1.y == 0)
	{
		cout << "找不到路径" << endl;
		return;
	}
	p.output();
	while (p1.x != 0) {
		cout << " <-- ";
		p1.output();
		p.rePoint(p1);
		p1.rePoint(previous[p.y][p.x]);
	}
	cout << endl;
}
void findPath(Point src, Point dst)
{
	map[src.y][src.x] = 'A';
	map[dst.y][dst.x] = 'B';
	Queue<Point>Q;
	Q.enqueue(src);
	while (Q.isEmtpy() == false)
	{
		Point pt = Q.dequeue();
		for (int i = 0; i < M; i++)
		{
			Point c = pt.move(direction[i]);
			char ch = map[c.y][c.x];
			if (ch == ' ')
			{
				previous[c.y][c.x] = pt;;
				map[c.y][c.x] = '#';
				Q.enqueue(c);
			}
			if (ch == 'B')
			{
				previous[c.y][c.x] = pt;
				printf("找到出口B点啦，路径是：");
				printPath(c);
				//return;
			}
		}
	}
}