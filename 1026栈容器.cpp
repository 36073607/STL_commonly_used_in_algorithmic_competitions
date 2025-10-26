#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//2.栈 stack
#include <stack>
//通过二次封装双端队列(deque)容器，实现先进后出的栈数据结构
//A.常用方法
int main()
{
	stack<double> stk;
	stk.push(1.0);
	stk.push(1.5);
	stk.push(1.8);
	cout << stk.size() << endl;
	cout << stk.top() << endl;
	cout << stk.empty() << endl;
	stk.pop();
	cout << stk.top() << endl;

	return 0;
}


//B.适用情形
//可以直接用它而不需要手写栈了
//另外，vector也可以当栈用，vector的 .back() 取尾部元素，就相当于栈顶
//.push_back()相当于进栈；.pop_back()相当于出栈
#include <vector>
int main()
{
	vector<double> vec;
	vec.push_back(1.0);
	vec.push_back(1.4);
	vec.push_back(1.8);
	cout << vec.back() << endl;
	vec.pop_back();
	cout << vec.back() << endl;

	return 0;
}


//C.注意事项
//不可访问内部元素！只能压栈和出栈
