#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
//7.�ַ��� string
#include <string>
//����˼�壬���Ǵ洢�ַ�����
//A.���÷���
//string(����,��ֵ)
int main()
{
	string s;
	cin >> s;
	cout << s << endl;

	//��c���Ե�printf��scanfʹ��string
	/*string s1;
	char buf[100];
	scanf("%s", buf);
	s = buf;
	printf("%s", s1.c_str());*/


	string s1(100, '0');
	s1 = "awa";
	cout << s1 << endl;
	s1[0] = 'b';//����ֱ���޸�
	cout << s1 << endl;


	string s2 = "abcde";
	string s3 = "abcde";
	if (s2 == s3)
		cout << "Yes" << endl;


	string sa = "123";
	string sb = "456";
	sa += 'a';
	cout << sa + sb << endl;


	string sc = "123456789";
	cout << sc.substr(3) << endl;//456789
	cout << sc.substr(3, 4) << endl;//4567
	//.substr(a,b)   a��ʾ�ִ�����ʼ�±꣬b��ʾa������b���ַ���������δ��дb�����a��ʼ�����ַ���


	string sd = "123123123";
	cout << sd.find("312") << endl;//2    .find()���ص�����ʼ����±�
	if (sd.find("312") != string::npos)//����Ҳ������ַ�����.find()�᷵�� string::npos �����趨�õ�
		cout << "Yes" << endl;


	string se = "123123123";
	int x = stoi(se);//stoi():���ַ�����ת��Ϊ����   string to integer
	long long y = stoll(se);//string to long long
	float z = stof(se);
	double q = stod(se);
	long double w = stold(se);
	cout << x << endl;


	int integer = 6662;
	string sf = to_string(integer);
	cout << sf << endl;

	return 0;
}


//B.��������
//    ��


//C.ע������
//a.β���ַ���һ��Ҫ�� +=
//string��+=�������������ԭ�ַ���ԭ��β���ַ���
//��+����=��ֵ����������һ����ʱ�������ٸ��Ƹ�string��ͨ���ַ������ȿ��Ժܳ������ʹ��+�ַ����ͺ�����TLE��
// 
// �Ż�ǰ��15139ms
// string s;
// for(int i = 0;i<5e5;i++)
//     s = s + "a";
// 
// �Ż���< 1ms ����ʱ����ʾ0��
// string s;
// for(int i = 0;i<5e5;i++)
//     s+="a";

//b. .substr()�������������
//һ��Ҫע�⣬C++ string ��ȡ�Ӵ��ĵ�һ���������Ӵ�����±꣬�ڶ����������Ӵ�����
//�ڶ������������Ӵ��յ㣡����

//c. .find�����ĸ��Ӷ�
//�÷���ʵ��Ϊ����ʵ�֣�ʱ�临�Ӷ�ΪO(n^2)
