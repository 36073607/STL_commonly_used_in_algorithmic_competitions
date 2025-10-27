#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
//�㷨
#include <algorithm>
//swap
int main()
{
	string a = "awa", b = "bwb";
	cout << a << " " << b << endl;
	swap(a, b);
	cout << a << " " << b << endl;

	return 0;
}

//sort ����������
int main()
{
	vector<int> arr{ 1,9,1,9,8,1,0 };
	sort(arr.begin(), arr.end());//��С������
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}


	sort(arr.begin(), arr.end(), greater<int>());//�Ӵ�С��
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;

	return 0;
}
//�Զ���Ƚ���
bool cmp(pair<int, int> a, pair<int, int> b)//��cmp��������true,��ʾ����Ԫ��λ������ȷ�ģ�����Ҫ����λ��
{
	//pair�ڶ�λ��С����
	if (a.second != b.second)
		return a.second < b.second;//ע�ⲻҪ���Ⱥ�
	//pair��һλ�Ӵ�С
	return a.first > b.first;//ע�ⲻҪ���Ⱥ�
}
int main()
{
	vector<pair<int, int>> arr{ {1,9},{2,9},{8,1},{0,0} };
	sort(arr.begin(), arr.end(), cmp);
	for (auto& p : arr)
	{
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}

//���ֲ��� : lower_bound()  /  upper_bound()
//�� ���������� ��Ԫ���У�Ӧ�ö��ֲ��Ҽ���ָ��Ԫ�أ����ض�ӦԪ�ص�����λ�ã��Ҳ����򷵻�β������
//lower_bound() ��Ѱ��>=x�ĵ�һ��Ԫ�ص�λ��
//upper_bound() ��Ѱ��>x�ĵ�һ��Ԫ�ص�λ��
//Q:��ô�� <=x / <x �ĵ�һ��Ԫ�أ�
// >x �ĵ�һ��Ԫ�ص�ǰһ��Ԫ�أ�����У�����<=x�ĵ�һ��Ԫ��
// >=x �ĵ�һ��Ԫ�ص�ǰһ��Ԫ�أ�����У�����<x�ĵ�һ��Ԫ��
//Q:���ص��ǵ����������ת���±������أ���ȥͷ����������
int main()
{
	vector<int> arr{ 0,1,1,1,8,9,9 };
	int pos1 = lower_bound(arr.begin(), arr.end(), 8) - arr.begin();
	int pos2 = upper_bound(arr.begin(), arr.end(), 8) - arr.begin();
	cout << pos1 << " " << pos2 << endl;//4 5

	int posa = lower_bound(arr.begin() + 2, arr.end(), 0) - arr.end();//�����Լ����ڲ��ҷ�Χ

	return 0;
}

//reverse
int main()
{
	vector<int> arr{ 0,1,1,1,8,9,9 };
	reverse(arr.begin(), arr.end());
	for (auto& pt : arr)
	{
		cout << pt << endl;
	}

	reverse(arr.begin() + 2, arr.begin() + 6);//�����Զ�����ת��һС������

	return 0;
}

//max/min
int main()
{
	cout << max(max(1, 3), 4) << endl;
	cout << max({ 1,3,5,2 }) << endl;//C++11�Ժ��������д
	cout << min(1, 3) << endl;

	return 0;
}

//unique ȥ��
//����������ظ�����Ԫ�أ����鳤�Ȳ��䣬������Ч�������̣����ص�����Ч����λ�õĽ�β������
//���磺[1,1,4,5,1,4]--->>[1,4,5,1,4,?]
//ע��
//����ʹ��unique�����ܴ��ȥ��Ч������Ϊ��ֻ�������ڵ��ظ�Ԫ�أ������������������ô������ȥ����
//������ȥ�غ�����β�������һЩ��Ч���ݣ�[1,1,2,4,4,4,5]-->>[1,2,4,5,?,?,?],Ϊ��ɾ����Щ��Ч���ݣ�������Ҫ���erase
int main()
{
	vector<int> arr{ 1,2,1,4,5,4,4 };
	sort(arr.begin(), arr.end());
	//1,1,2,4,4,4,5
	//1,2,4,5,*,?,?
	//unique(arr.begin(), arr.end());//unique()�ķ���ֵ��*��λ�õĵ�����
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (auto& ele : arr)
	{
		cout << ele << endl;
	}

	return 0;
}

//��ѧ����
//����ֵ abs()
//e^x  exp()
//lnx  log()
//x^y  pow()
//����x  sqrt()
//����ȡ��  ceil()
//����ȡ��  floor()
//��������  round()

//gcd()���Լ�� / lcm()��С������   C++17֧��
//�Լ��ִ�һ��Ҳͦ��
int gcd(int a, int b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}
int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}
