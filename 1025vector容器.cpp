#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//����
//1.���� vector
//���ǳ���֮Ϊvector����
#include <vector>
//������˳��Ĵ���ṹ��������һ������𣩣������г��ȿɱ������
//A.���÷���
//a.����
//vector<����> arr(����,[��ֵ])
//ʱ�临�Ӷȣ�O(n)
vector<int> arr1;//����int���飬Ĭ�Ϲ��캯�������εĻ������ĳ���Ϊ0�������ǿյ�
vector<int> arr2(100);//�����ʼ����Ϊ100��int����
vector<int> arr3(100, 1);//�����ʼ����Ϊ100��int���飬��ֵΪ1

vector<vector<int>> array(5, vector<int>(6));//����һ���������еĶ�ά����
//��ά������һά���������
//5���������vector<int>���͵�Ԫ�أ� vector<int>(6)��ʾÿ��Ԫ�ض�����6��Ԫ�ص�һά����
vector<vector<int>> array(5, vector<int>(6, 10));//����һ���������еĶ�ά���飬��ά������ÿ��������10

vector<vector<vector<int>>> dp(5, vector<vector<int>>(6, vector<int>(6)));
int mat[5][6][4];


//b.β��&βɾ
int main()
{
	vector<int> arr4;
	arr4.push_back(1);
	arr4.push_back(2);
	arr4.push_back(3);
	for (auto& ele : arr4)
	{
		cout << ele << endl;
	}

	arr4.pop_back();
	arr4.pop_back();
	for (auto& ele : arr4)
	{
		cout << ele << endl;
	}

	return 0;
}


//c.��ȡ����
int main()
{
	vector<int> arr5;
	arr5.push_back(1);
	arr5.push_back(2);
	arr5.push_back(3);

	cout << arr5.size() << endl;

	return 0;
}


//d.���
int main()
{
	vector<int> arr6;
	arr6.push_back(1);
	arr6.push_back(2);
	arr6.push_back(3);

	arr6.clear();

	cout << arr6.size() << endl;

	return 0;
}


//e.�п�
int main()
{
	vector<int> arr7;
	arr7.push_back(1);
	arr7.push_back(2);
	arr7.push_back(3);

	cout << arr7.empty() << endl;//����һ��bool���ͣ��յķ���1���ǿշ���0

	if (arr7.empty())//���Ϊ�գ���ִ���������
	{
		;
	}

	return 0;
}


//f.�ı䳤��
int main()
{
	vector<int> arr8;
	arr8.push_back(1);
	arr8.push_back(2);
	arr8.push_back(3);
	cout << arr8.size() << endl;//arr8����3��Ԫ��

	arr8.resize(5);//arr8������5��Ԫ�أ�ʣ������δ��ʼ����Ԫ��Ĭ��Ϊ0
	arr8.resize(5, 3);//ʣ������Ԫ��Ϊ3
	for (auto ele : arr8)
	{
		cout << ele << endl;
	}

	arr8.resize(1);//ֻʣ�µ�һ��Ԫ��

	return 0;
}


//B.��������
//һ�������vector�����滻����ͨ����
//��Щ�������ͨ����û�������n*m�ľ���1<=n,m<=10^6��n*m<=10^6
//�������ͨ���� int mat[1000010][1000010],�˷��ڴ棬�ᵼ��MLE
//���ʹ�� vector<vector<int>> mat(n+10,vector<int> (m+10)),�������
//��������10�Ƿ�ֹ���Լ������ݵ�ʱ�򱬵���
//���⣬vector�����ݴ����ڶѿռ��У����ᱬջ(RE)
//����ջ���Է���ȫ�֣�



//C.ע������
//a.��ǰָ������
//��������Ѿ�ȷ������ôӦ��ֱ���ڹ��캯��ʱָ�����ȣ�������һ��һ����.push_back().
//��Ϊvector�����ڴ�ľ�����ط�������ʱ�俪���ģ�ֱ��ָ�����ȾͲ�������ط�����
int main()
{
	//�Ż�ǰ��522ms
	vector<int> a;
	for (int i = 0; i < 1e8; i++)
		a.push_back(i);

	//�Ż���259ms
	vector<int> b(1e8);
	for (int i = 0; i < a.size(); i++)
		a[i] = i;

	return 0;
}


//b.���� size_t ���
//vector��ȡ���ȵķ���.size()�ķ���ֵ����Ϊ size_t 
//ͨ��OJƽ̨ʹ�õ���32λ��������(��Щƽ̨����cf��ѡ64λ)����ô�����ͷ�ΧΪ[0,2^32)
vector<int> a(65536);
long long a = a.size() * a.size();//ֱ��������0