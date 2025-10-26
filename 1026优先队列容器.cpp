#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//4.���ȶ��� priority queue (��)
#include <queue>
//�ṩ����ʱ������Ԫ�ز��ң�����ʱ��Ĳ�������ȡ���ײ�ԭ���Ƕ����
//A.���÷���
//a.����
//priority_queue<����,����,�Ƚ���> pque
//���ͣ�Ҫ�洢����������
//�������������ݵĵײ�������Ĭ��Ϊ vector<����> �������б���Ĭ�ϼ���
//�Ƚ������Ƚϴ�Сʹ�õıȽ�����Ĭ��Ϊ less<����> �����Զ���
int main()
{
	priority_queue<int> pque;
	pque.push(1);
	cout << pque.top() << endl;//�����ֳ�ʼ��1�£�.top()ȡ���Ѷ�(���е����ֵ)����Ȼ�����ǰѶѶ���ɾ��
	pque.push(3);
	cout << pque.top() << endl;
	pque.push(2);
	cout << pque.top() << endl;
	pque.push(4);
	cout << pque.top() << endl;

	pque.pop();//�����Ѷ�Ԫ�أ����Ԫ�أ�
	cout << pque.top() << endl;

	return 0;
}

int main()
{
	priority_queue<int, vector<int>, greater<int>> pque;//���С����
	pque.push(1);
	cout << pque.top() << endl;//���ֳ�ʼ���£�.top()ȡ���Ѷ�(���е���Сֵ)
	pque.push(3);
	cout << pque.top() << endl;
	pque.push(2);
	cout << pque.top() << endl;
	pque.push(4);
	cout << pque.top() << endl;

	pque.pop();//�����Ѷ�Ԫ�أ���СԪ�أ�
	cout << pque.top() << endl;

	return 0;
}


//B.��������
//����ά��Ԫ�ص������ԣ�ÿ������в����С������Ԫ�أ�����ÿ�δӶ�����ȡ�����/��С��Ԫ�أ�Ԫ������n,�����������k
//��ÿ�β������п�������k* nlog(n)
//    ʹ�����ȶ���ά����k* log(n)


//C.ע������
//a.���Ѷ��ɶ���ֻ�ɷ��ʶѶ�������Ԫ�ض��޷�ȡ��
//b.��������Ԫ�ض��ǲ����޸ĵ�
//c.�����ǡ��Ҫ�޸ĵ��ǶѶ�Ԫ�أ���ô�ǿ�����ɵģ�
int tp = pque.top();
pque.pop();
pque.push(tp + 1);//���ڶѶ���tp+1