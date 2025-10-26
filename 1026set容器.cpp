#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;
//5.集合 set
#include <set>
//提供对数时间的插入，删除，查找的集合数据结构。底层原理是红黑树
//集合三要素               解释                         set               multiset                 unordered_set
//  确定性     一个元素要么在集合中，要么不在           √                   √                         √
//  互异性     一个元素仅可以在集合中出现一次           √                   ×(任意次)                 √
//  无序性     集合中的元素是没有顺序的                 ×(从小到大)         ×(从小到大)               √

//A.常用方法
//a.构造
//set<类型,比较器> st
//类型：要储存的数据类型
//比较器：比较大小使用的比较器，默认为 less<类型> ,可自定义
int main()
{
	set<int> st;
	st.insert(1);
	st.insert(2);
	st.insert(2);
	st.insert(0);
	//由于互异性，集合中只有 1，2，0三个元素
	st.erase(2);//把元素2删了
	for (auto& ele : st)
	{
		cout << ele << endl;
	}

	if (st.find(1) != st.end())//.find()返回一个迭代器，如果找到1的话会返回一个指向一的迭代器；如果在整个set中找不到，会返回尾迭代器
	{
		cout << "Yes" << endl;
	}

	if (st.count(1))//.count()返回的是该元素在集合中有几个  （由于set的互异性，.count()只有两种返回值：1和0）（但在multiset中调用就会返回具体有几个数了）
	{
		cout << "Yes" << endl;
	}

	cout << st.size() << endl;
	st.clear();
	cout << st.empty() << endl;


	//遍历：
	//使用迭代器的循环：
	for (set<int>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout << *it << endl;
	}
	//基于范围的循环（C++ 11）
	for (auto& ele : st)//&引用
	{
		cout << ele << endl;
	}

	return 0;
}
//增删查的时间复杂度均为：O(log n)


//B.适用情形
//a.元素去重：[1,1,3,2,4,4]->[1,2,3,4]
//b.维护顺序：[1,5,3,7,9]->[1,3,5,7,9]
//c.元素是否出现过：元素大小[-10^18,10^18]，元素数量10^8，vis数组无法实现，通过set可以完成
int main()
{
	set<int> st1;
	st1.insert(1);
	st1.insert(2);

	if (st1.count(1))
	{
		cout << "yes" << endl;
	}

	return 0;
}


//C.注意事项
//a.不存在下标索引：set虽说可以遍历，但仅可使用迭代器进行遍历，它不存在下标这一概念，无法通过下标访问到数据
cout << *st.begin() << endl;//可以通过迭代器查找
//b.元素只读：set的迭代器取到的元素是只读的(因为是const迭代器)，不可修改其值。如果要改需要先erase再insert
//c.不可用迭代器计算下标
