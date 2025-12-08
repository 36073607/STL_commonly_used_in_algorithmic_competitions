#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
using namespace std;
//迭代器
//1.迭代器是什么
int main()
{
	vector<int> a;
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}

	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it << endl;
	}

	return 0;
}
//a.begin()是一个迭代器，指向的是第一个元素
//a.end()是一个迭代器，指向的是最后一个元素再后面一位
//上述迭代器具有自增运算符，自增则迭代器向下一个元素移动
//迭代器与指针相似，如果对它使用解引用1操作符，即 *it ，就能取到对应值了


//2.为何需要迭代器
//很多数据结构并不是线性的（例如红黑树），对于非线性结构，下表是无意义的，无法使用下标来遍历整个数据结构
//迭代器的作用就是定义某个数据结构的遍历方式，通过迭代器的增减，代表遍历到的位置，通过迭代器便能成功遍历非线性结构了
//例如，set的实现是红黑树，我们是没法通过下标来访问元素的，但是通过迭代器，我们就可以遍历set中的元素了：
int main()
{
	set<int> st;
	for (set<int>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout << *it << endl;
	}
}



//3.迭代器用法
//对于vector容器，它的迭代器功能比较完善，以它举例：
//.begin()  头迭代器
//.end()  尾迭代器
//.rbegin()  反向头迭代器
//.rend()  反向尾迭代器
//迭代器+整型：将迭代器往后移动
//迭代器-整型：将迭代器往前移动
//迭代器++：将迭代器向后移动一位
//迭代器--：将迭代器向前移动一位
//迭代器-迭代器：两个迭代器的距离
//prev(it)：返回it的前一个迭代器
//next(it)：返回it的后一个迭代器
//对于其他容器，由于其结构特性，上面的功能不一定都有（例如set的迭代器是不能相减求距离的）


//4.常见问题
//a. .end()和.rend()指向的位置是无意义的值
//b. 不同容器的迭代器功能可能不一样
//c. 删除操作时需要警惕（别用迭代器操作容器！！！）


//在C++中，以下容器的迭代器是双向迭代器：
1. std::list
std::list<int> lst = {1, 2, 3};
auto it = lst.begin();
++it;  // 前向移动
--it;  // 反向移动

2. std::set
std::set<int> s = {1, 2, 3};
auto it = s.begin();
++it;  // 前向移动
--it;  // 反向移动

3. std::map
std::map<int, std::string> m = {{1, "a"}, {2, "b"}};
auto it = m.begin();
++it;  // 前向移动
--it;  // 反向移动

4. std::multiset
std::multiset<int> ms = {1, 1, 2, 3};
auto it = ms.begin();
++it;  // 前向移动
--it;  // 反向移动

5. std::multimap
std::multimap<int, std::string> mm = {{1, "a"}, {1, "b"}};
auto it = mm.begin();
++it;  // 前向移动
--it;  // 反向移动

6. std::deque（实际上是随机访问迭代器，包含双向功能）
std::deque<int> dq = {1, 2, 3};
auto it = dq.begin();
++it;  // 前向移动
--it;  // 反向移动
it += 2;  // 随机访问

7. std::vector（实际上是随机访问迭代器，包含双向功能）
std::vector<int> vec = {1, 2, 3};
auto it = vec.begin();
++it;  // 前向移动
--it;  // 反向移动
it += 2;  // 随机访问

//不能使用 prev() 或反向移动的容器：
1. std::unordered_map（只有前向迭代器）
std::unordered_map<int, int> um;
auto it = um.begin();
++it;  // 可以
--it;  // ❌ 编译错误！不能反向移动
auto it2 = prev(it);  // ❌ 不能在无序容器上使用prev

2. std::unordered_set（只有前向迭代器）
std::unordered_set<int> us;
auto it = us.begin();
++it;  // 可以
--it;  // ❌ 编译错误！

3. std::forward_list（只有前向迭代器）
std::forward_list<int> fl;
auto it = fl.begin();
++it;  // 可以
--it;  // ❌ 编译错误！
