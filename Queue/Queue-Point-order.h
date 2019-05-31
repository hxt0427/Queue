#pragma once
#include <iostream>
#include "Queue.h"
using namespace std;

struct Point {
	int x, y;
	Point(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
	void output()
	{
		cout << "(" << x << "," << y << ")";
	}
	Point move(Point vevtor)
	{
		return Point(x + vevtor.x, y + vevtor.y);
	}
	void rePoint(Point re)
	{
		x = re.x;
		y = re.y;
	}
};

#define N 10
#define M 4
char map[N][N + 1] = {
	"XXXXXXXXXX",
	"X  X   X X",
	"X  X   X X",
	"X    XX  X",
	"X XXX    X",
	"X   X X  X",
	"X X   X  X",
	"X XXX XX X",
	"XX       X",
	"XXXXXXXXXX",
};

Point direction[M] = {
	Point{1,0},		//下
	Point{0,1},		//右
	Point{-1,0},	//上
	Point{0,-1},	//左

};

Point previous[N][N];
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
	Q.enqueue(dst);
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
			if (ch == 'A')
			{
				previous[c.y][c.x] = pt;
				printf("找到出口B点啦，路径是：");
				printPath(c);
				return;
			}
		}
	}
}