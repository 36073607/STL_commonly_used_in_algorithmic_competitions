#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
using namespace std;
//8.��Ԫ�� pair
#include <utility>
//����˼�壬���Ǵ����Ԫ���
//A.���÷���
//pair<��һ��ֵ����,�ڶ���ֵ����> pr
//��һ��ֵ���ͣ�Ҫ�洢�ĵ�һ��ֵ����������
//�ڶ���ֵ���ͣ�Ҫ�洢�ĵڶ���ֵ����������
int main()
{
	pair<int, int> p = { 1,2 };
	pair<int, int> p1 = make_pair(1, 2);   //��ʽ�ķ�ʽ
	cout << p.first << " " << p.second << endl;

	if (p == p1)
		cout << "Yes" << endl;

	pair<char, int> pp = { 'a',2 };

	pair<pair<char, int>, char> px;//��Ԫ��
	pair<pair<int, int>, pair<int, int>> pxx;//��Ԫ��

	return 0;
}


//B.��������
//������Ҫ��Ԫ��ĳ�������ʹ�ã�Ч�ʺ��Լ�����Ľṹ����


//C.ע������
//��

