#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;
//6.映射 map
#include <map>
//提供对数时间的有序键值对结构，底层原理是红黑树
//   性质               解释                         map               multimap                 unordered_map
//  互异性     一个键仅可以在映射中出现一次          √                ×(任意次)                    √
//  无序性          键是没有顺序的               ×(从小到大)         ×(从小到大)                   √

//A.常用方法
//map<键类型,值类型,比较器> mp
//键类型：要存储的数据类型
//值类型：要存储的数据类型
//比较器：键比较大小使用的比较器，默认为 less<类型>,可自定义
int main()
{
	map<int, int> mp;
	mp[2] = 1;//类似数组
	mp[3] = 1;
	mp[4] = 1;
	mp[2] = 3;   //map中值可以修改
	cout << mp[2] << endl;
	cout << mp[1000] << endl;//如果访问map中不存在的元素，就会赋一个初值----0

	if (mp.find(2) != mp.end())
	{
		cout << "Yes" << endl;
	}

	mp.erase(2);//把mp[2]删了

	cout << mp.count(2) << endl;//.count()返回mp[2]这个键在整个mp中出现几次，由于map的互异性，所以这里的count只有0，1

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
		mp[word[i]]++;//mp的键从零开始自增
	}

	for (auto& pt : mp)
	{
		cout << pt.first << " " << pt.second << endl;
	}

	return 0;
}


//B.适用情形
//需要维护映射的场景可以使用：输入若干字符串，统计每种字符串的出现次数.(map<string,int> mp)


//C.注意事项
//a.如果使用中括号[]访问map时对应的键不存在，那么会新增这个键，并且值为默认值，因此中括号会影响键的存在性
map<char, int> mp;
cout << mp.count('a') << endl;//0
mp['a'];//即使什么都没做，此时mp['a']=0已经插入了
cout << mp.count('a') << endl;//1
cout << mp['a'] << endl;//0

//b.不可用迭代器计算下标：map的迭代器不能像vector一样相减得到下标