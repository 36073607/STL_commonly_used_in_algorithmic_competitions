#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//3.���� queue
#include <queue>
//ͨ�����η�װ˫�˶���(deque)������ʵ���Ƚ��ȳ��Ķ������ݽṹ
//A.���÷���
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


//B.��������
//����ֱ��ʹ�ö�������д����


//C.ע������
//�����Է����ڲ�Ԫ�أ�