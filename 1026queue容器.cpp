#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//3.队列 queue
#include <queue>
//通过二次封装双端队列(deque)容器，实现先进先出的队列数据结构
//A.常用方法
int main()
{
	queue<int> que;
	que.push(1);
	que.push(2);
	que.push(3);
	cout << que.front() << endl;
	cout << que.back() << endl;
	cout << que.size() << endl;
	cout << que.empty() << endl;

	que.pop();
	cout << que.front() << endl;
	cout << que.back() << endl;
	que.pop();
	cout << que.front() << endl;
	cout << que.back() << endl;


	return 0;
}


//B.适用情形
//可以直接使用而不用手写队列


//C.注意事项
//不可以访问内部元素！
