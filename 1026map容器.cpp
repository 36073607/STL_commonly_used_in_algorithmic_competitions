#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;
//6.ӳ�� map
#include <map>
//�ṩ����ʱ��������ֵ�Խṹ���ײ�ԭ���Ǻ����
//   ����               ����                         map               multimap                 unordered_map
//  ������     һ������������ӳ���г���һ��          ��                ��(�����)                    ��
//  ������          ����û��˳���               ��(��С����)         ��(��С����)                   ��

//A.���÷���
//map<������,ֵ����,�Ƚ���> mp
//�����ͣ�Ҫ�洢����������
//ֵ���ͣ�Ҫ�洢����������
//�Ƚ��������Ƚϴ�Сʹ�õıȽ�����Ĭ��Ϊ less<����>,���Զ���
int main()
{
	map<int, int> mp;
	mp[2] = 1;//��������
	mp[3] = 1;
	mp[4] = 1;
	mp[2] = 3;   //map��ֵ�����޸�
	cout << mp[2] << endl;
	cout << mp[1000] << endl;//�������map�в����ڵ�Ԫ�أ��ͻḳһ����ֵ----0

	if (mp.find(2) != mp.end())
	{
		cout << "Yes" << endl;
	}

	mp.erase(2);//��mp[2]ɾ��

	cout << mp.count(2) << endl;//.count()����mp[2]�����������mp�г��ּ��Σ�����map�Ļ����ԣ����������countֻ��0��1

	cout << mp.size() << endl;
	mp.clear();
	cout << mp.empty() << endl;


	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}

	for (auto& pr : mp)
	{
		cout << pr.first << " " << pr.second << endl;
	}

	return 0;
}

int main()
{
	map<string, int> mp;
	vector<string> word;
	word.push_back("awa");
	word.push_back("awa");
	word.push_back("awa");
	word.push_back("awa");
	word.push_back("bwb");
	word.push_back("bwb");

	for (int i = 0; i < word.size(); i++)
	{
		mp[word[i]]++;//mp�ļ����㿪ʼ����
	}

	for (auto& pt : mp)
	{
		cout << pt.first << " " << pt.second << endl;
	}

	return 0;
}


//B.��������
//��Ҫά��ӳ��ĳ�������ʹ�ã����������ַ�����ͳ��ÿ���ַ����ĳ��ִ���.(map<string,int> mp)


//C.ע������
//a.���ʹ��������[]����mapʱ��Ӧ�ļ������ڣ���ô�����������������ֵΪĬ��ֵ����������Ż�Ӱ����Ĵ�����
map<char, int> mp;
cout << mp.count('a') << endl;//0
mp['a'];//��ʹʲô��û������ʱmp['a']=0�Ѿ�������
cout << mp.count('a') << endl;//1
cout << mp['a'] << endl;//0

//b.�����õ����������±꣺map�ĵ�����������vectorһ������õ��±�