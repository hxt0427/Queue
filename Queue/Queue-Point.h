#pragma once
#include "Queue.h"

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

Point previous[N][N];