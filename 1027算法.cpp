#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
//算法
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

//sort （快速排序）
int main()
{
	vector<int> arr{ 1,9,1,9,8,1,0 };
	sort(arr.begin(), arr.end());//从小到大排
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}


	sort(arr.begin(), arr.end(), greater<int>());//从大到小排
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;

	return 0;
}
//自定义比较器
bool cmp(pair<int, int> a, pair<int, int> b)//当cmp函数返回true,表示两个元素位置是正确的，不需要交换位置
{
	//pair第二位从小到大
	if (a.second != b.second)
		return a.second < b.second;//注意不要带等号
	//pair第一位从大到小
	return a.first > b.first;//注意不要带等号
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

//二分查找 : lower_bound()  /  upper_bound()
//在 已升序排列 的元素中，应用二分查找检索指定元素，返回对应元素迭代器位置，找不到则返回尾迭代器
//lower_bound() ：寻找>=x的第一个元素的位置
//upper_bound() ：寻找>x的第一个元素的位置
//Q:怎么找 <=x / <x 的第一个元素？
// >x 的第一个元素的前一个元素（如果有）便是<=x的第一个元素
// >=x 的第一个元素的前一个元素（如果有）便是<x的第一个元素
//Q:返回的是迭代器，如何转成下标索引呢？减去头迭代器即可
int main()
{
	vector<int> arr{ 0,1,1,1,8,9,9 };
	int pos1 = lower_bound(arr.begin(), arr.end(), 8) - arr.begin();
	int pos2 = upper_bound(arr.begin(), arr.end(), 8) - arr.begin();
	cout << pos1 << " " << pos2 << endl;//4 5

	int posa = lower_bound(arr.begin() + 2, arr.end(), 0) - arr.end();//可以自己调节查找范围

	return 0;
}

//reverse  STL的reverse函数是左闭右开区间
int main()
{
	vector<int> arr{ 0,1,1,1,8,9,9 };
	reverse(arr.begin(), arr.end());
	for (auto& pt : arr)
	{
		cout << pt << endl;
	}

	reverse(arr.begin() + 2, arr.begin() + 6);//可以自定义逆转的一小段序列

	return 0;
}

//max/min
int main()
{
	cout << max(max(1, 3), 4) << endl;
	cout << max({ 1,3,5,2 }) << endl;//C++11以后可以这样写
	cout << min(1, 3) << endl;

	return 0;
}

//unique 去重
//消除数组的重复相邻元素，数组长度不变，但是有效数据缩短，返回的是有效数据位置的结尾迭代器
//例如：[1,1,4,5,1,4]--->>[1,4,5,1,4,?]
//注：
//单独使用unique并不能达成去重效果，因为它只消除相邻的重复元素，但是如果序列有序，那么它就能去重了
//但是它去重后，序列尾部会产生一些无效数据：[1,1,2,4,4,4,5]-->>[1,2,4,5,?,?,?],为了删掉这些无效数据，我们需要结合erase
int main()
{
	vector<int> arr{ 1,2,1,4,5,4,4 };
	sort(arr.begin(), arr.end());
	//1,1,2,4,4,4,5
	//1,2,4,5,*,?,?
	//unique(arr.begin(), arr.end());//unique()的返回值是*的位置的迭代器
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (auto& ele : arr)
	{
		cout << ele << endl;
	}

	return 0;
}

//数学函数
//绝对值 abs()
//e^x  exp()
//lnx  log()
//x^y  pow()
//根号x  sqrt()
//向上取整  ceil()
//向下取整  floor()
//四舍五入  round()

//gcd()最大公约数 / lcm()最小公倍数   C++17支持
//自己手搓一个也挺快
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

//全排列  next_permutation
//template<class Iterator>
//  bool next_permutation (Iterator first, Iterator last);

//template<class Iterator, class Compare>
//  bool next_permutation (Iterator first, Iterator last, Compare comp);

//按照 字典序 或者 按照输入到第三个参数 cmp 的排列方法排列

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  string number = "213";
  next_permutation(number.begin(), number.end());
  cout << number;
//输出结果为： 231
  return 0;
}

//洛谷 P1088 火星人
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	for (int i = 0; i < m; i++)
		next_permutation(arr.begin(), arr.end());

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}

