#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//4.优先队列 priority queue (堆)
#include <queue>
//提供常数时间的最大元素查找，对数时间的插入与提取，底层原理是二叉堆
//A.常用方法
//a.构造
//priority_queue<类型,容量,比较器> pque
//类型：要存储的数据类型
//容器：储存数据的底层容器，默认为 vector<类型> ，竞赛中保持默认即可
//比较器：比较大小使用的比较器，默认为 less<类型> ，可自定义
int main()
{
	priority_queue<int> pque;
	pque.push(1);
	cout << pque.top() << endl;//在这种初始化1下，.top()取出堆顶(堆中的最大值)，当然并不是把堆顶给删了
	pque.push(3);
	cout << pque.top() << endl;
	pque.push(2);
	cout << pque.top() << endl;
	pque.push(4);
	cout << pque.top() << endl;

	pque.pop();//弹出堆顶元素（最大元素）
	cout << pque.top() << endl;

	return 0;
}

int main()
{
	priority_queue<int, vector<int>, greater<int>> pque;//变成小顶堆
	pque.push(1);
	cout << pque.top() << endl;//这种初始化下，.top()取出堆顶(堆中的最小值)
	pque.push(3);
	cout << pque.top() << endl;
	pque.push(2);
	cout << pque.top() << endl;
	pque.push(4);
	cout << pque.top() << endl;

	pque.pop();//弹出堆顶元素（最小元素）
	cout << pque.top() << endl;

	return 0;
}


//B.适用情形
//持续维护元素的有序性：每次向队列插入大小不定的元素，或者每次从队列里取出最大/最小的元素，元素数量n,插入操作数量k
//则：每次插入后进行快速排序：k* nlog(n)
//    使用优先队列维护：k* log(n)


//C.注意事项
//a.仅堆顶可读：只可访问堆顶，其他元素都无法取到
//b.堆中所有元素都是不可修改的
//c.如果你恰好要修改的是堆顶元素，那么是可以完成的：
int tp = pque.top();
pque.pop();
pque.push(tp + 1);//现在堆顶是tp+1