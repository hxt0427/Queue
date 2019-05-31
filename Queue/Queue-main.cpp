#include "pch.h"
//#include"Queue.h"
//#include"Queue-Point-4.h"				//4联通逆序
//#include"Queue-Point-8.h"				//8联通逆序
#include"Queue-Point-order.h"			//4联通顺序


int main()
{

	try {
		findPath(Point(1, 1), Point(8, 8));
		cout << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout << map[i][j];
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				previous[i][j].output();
			cout << endl;
		}
		}
	catch (const char * message) {
		cout << "异常信息：" << message << endl;
	}


	return 0;
}