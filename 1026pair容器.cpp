#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
using namespace std;
//8.二元组 pair
#include <utility>
//顾名思义，就是储存二元组的
//A.常用方法
//pair<第一个值类型,第二个值类型> pr
//第一个值类型：要存储的第一个值的数据类型
//第二个值类型：要存储的第二个值的数据类型
int main()
{
	pair<int, int> p = { 1,2 };
	pair<int, int> p1 = make_pair(1, 2);   //老式的方式
	cout << p.first << " " << p.second << endl;

	if (p == p1)
		cout << "Yes" << endl;

	pair<char, int> pp = { 'a',2 };

	pair<pair<char, int>, char> px;//三元组
	pair<pair<int, int>, pair<int, int>> pxx;//四元组

	return 0;
}


//B.适用情形
//所有需要二元组的场景均可使用，效率和自己定义的结构体差不多


//C.注意事项
//无

