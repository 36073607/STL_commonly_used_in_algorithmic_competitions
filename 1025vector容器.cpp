#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//容器
//1.向量 vector
//我们常称之为vector数组
#include <vector>
//连续的顺序的储存结构（和数组一样的类别），但是有长度可变的特性
//A.常用方法
//a.构造
//vector<类型> arr(长度,[初值])
//时间复杂度：O(n)
vector<int> arr1;//构造int数组，默认构造函数不传参的话，它的长度为0，数组是空的
vector<int> arr2(100);//构造初始长度为100的int数组
vector<int> arr3(100, 1);//构造初始长度为100的int数组，初值为1

vector<vector<int>> array(5, vector<int>(6));//构造一个五行六列的二维数组
//二维数组是一维数组的数组
//5代表有五个vector<int>类型的元素， vector<int>(6)表示每个元素都是有6个元素的一维数组
vector<vector<int>> array(5, vector<int>(6, 10));//构造一个五行六列的二维数组，二维数组中每个数都是10

vector<vector<vector<int>>> dp(5, vector<vector<int>>(6, vector<int>(6)));
int mat[5][6][4];


//b.尾接&尾删
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


//c.获取长度
int main()
{
	vector<int> arr5;
	arr5.push_back(1);
	arr5.push_back(2);
	arr5.push_back(3);

	cout << arr5.size() << endl;

	return 0;
}


//d.清空
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


//e.判空
int main()
{
	vector<int> arr7;
	arr7.push_back(1);
	arr7.push_back(2);
	arr7.push_back(3);

	cout << arr7.empty() << endl;//返回一个bool类型：空的返回1，非空返回0

	if (arr7.empty())//如果为空，则执行下列语句
	{
		;
	}

	return 0;
}


//f.改变长度
int main()
{
	vector<int> arr8;
	arr8.push_back(1);
	arr8.push_back(2);
	arr8.push_back(3);
	cout << arr8.size() << endl;//arr8现在3个元素

	arr8.resize(5);//arr8现在有5个元素，剩下两个未初始化的元素默认为0
	arr8.resize(5, 3);//剩下两个元素为3
	for (auto ele : arr8)
	{
		cout << ele << endl;
	}

	arr8.resize(1);//只剩下第一个元素

	return 0;
}


//B.适用情形
//一般情况下vector可以替换掉普通数组
//有些情况下普通数组没法解决：n*m的矩阵，1<=n,m<=10^6且n*m<=10^6
//如果用普通数组 int mat[1000010][1000010],浪费内存，会导致MLE
//如果使用 vector<vector<int>> mat(n+10,vector<int> (m+10)),完美解决
//（这里多出10是防止测试极端数据的时候爆掉）
//另外，vector的数据储存在堆空间中，不会爆栈(RE)
//（爆栈可以放在全局）



//C.注意事项
//a.提前指定长度
//如果长度已经确定，那么应当直接在构造函数时指定长度，而不是一个一个用.push_back().
//因为vector额外内存耗尽后的重分配是有时间开销的，直接指定长度就不会出现重分配了
int main()
{
	//优化前：522ms
	vector<int> a;
	for (int i = 0; i < 1e8; i++)
		a.push_back(i);

	//优化后：259ms
	vector<int> b(1e8);
	for (int i = 0; i < a.size(); i++)
		a[i] = i;

	return 0;
}


//b.当心 size_t 溢出
//vector获取长度的方法.size()的返回值类型为 size_t 
//通常OJ平台使用的是32位编译器，(有些平台例如cf可选64位)，那么该类型范围为[0,2^32)
vector<int> a(65536);
long long a = a.size() * a.size();//直接溢出变成0