#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//2.ջ stack
#include <stack>
//ͨ�����η�װ˫�˶���(deque)������ʵ���Ƚ������ջ���ݽṹ
//A.���÷���
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


//B.��������
//����ֱ������������Ҫ��дջ��
//���⣬vectorҲ���Ե�ջ�ã�vector�� .back() ȡβ��Ԫ�أ����൱��ջ��
//.push_back()�൱�ڽ�ջ��.pop_back()�൱�ڳ�ջ
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


//C.ע������
//���ɷ����ڲ�Ԫ�أ�ֻ��ѹջ�ͳ�ջ
