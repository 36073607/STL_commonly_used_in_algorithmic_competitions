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
	arr8.resize(5,3);//剩下两个元素为3
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



//2.栈 stack
#include <stack>
//通过二次封装双端队列(deque)容器，实现先进后出的栈数据结构
//A.常用方法
int main()
{
	stack<double> stk;
	stk.push(1.0);
	stk.push(1.5);
	stk.push(1.8);
	cout << stk.size() << endl;
	cout << stk.top() << endl;
	cout << stk.empty() << endl;
	stk.pop();
	cout << stk.top() << endl;

	return 0;
}


//B.适用情形
//可以直接用它而不需要手写栈了
//另外，vector也可以当栈用，vector的 .back() 取尾部元素，就相当于栈顶
//.push_back()相当于进栈；.pop_back()相当于出栈
#include <vector>
int main()
{
	vector<double> vec;
	vec.push_back(1.0);
	vec.push_back(1.4);
	vec.push_back(1.8);
	cout << vec.back() << endl;
	vec.pop_back();
	cout << vec.back() << endl;

	return 0;
}


//C.注意事项
//不可访问内部元素！只能压栈和出栈



//3.队列 queue
#include <queue>
//通过二次封装双端队列(deque)容器，实现先进先出的队列数据结构
//A.常用方法
int main()
{
	queue<int> que;
	que.push(1);
	que.push(2);
	que.push(3);
	cout << que.front() << endl;
	cout << que.back() << endl;
	cout << que.size() << endl;
	cout << que.empty() << endl;

	que.pop();
	cout << que.front() << endl;
	cout << que.back() << endl;
	que.pop();
	cout << que.front() << endl;
	cout << que.back() << endl;


	return 0;
}


//B.适用情形
//可以直接使用而不用手写队列


//C.注意事项
//不可以访问内部元素！



//4.优先队列 priority queue (堆)
#include <queue>
//提供常数时间的最大元素查找，对数时间的插入与提取，底层原理是二叉堆
//A.常用方法
//a.构造
//priority_queue<类型,容量,比较器> pque
//类型：要存储的数据类型
//容器：储存数据的底层容器，默认为 vector<类型> ，竞赛中保持默认即可
//比较器：比较大小使用的比较器，默认为 less<类型> ，可自定义
int main()
{
	priority_queue<int> pque;
	pque.push(1);
	cout << pque.top() << endl;//在这种初始化1下，.top()取出堆顶(堆中的最大值)，当然并不是把堆顶给删了
	pque.push(3);
	cout << pque.top() << endl;
	pque.push(2);
	cout << pque.top() << endl;
	pque.push(4);
	cout << pque.top() << endl;

	pque.pop();//弹出堆顶元素（最大元素）
	cout << pque.top() << endl;

	return 0;
}

int main()
{
	priority_queue<int,vector<int>,greater<int>> pque;//变成小顶堆
	pque.push(1);
	cout << pque.top() << endl;//这种初始化下，.top()取出堆顶(堆中的最小值)
	pque.push(3);
	cout << pque.top() << endl;
	pque.push(2);
	cout << pque.top() << endl;
	pque.push(4);
	cout << pque.top() << endl;

	pque.pop();//弹出堆顶元素（最小元素）
	cout << pque.top() << endl;

	return 0;
}


//B.适用情形
//持续维护元素的有序性：每次向队列插入大小不定的元素，或者每次从队列里取出最大/最小的元素，元素数量n,插入操作数量k
//则：每次插入后进行快速排序：k* nlog(n)
//    使用优先队列维护：k* log(n)


//C.注意事项
//a.仅堆顶可读：只可访问堆顶，其他元素都无法取到
//b.堆中所有元素都是不可修改的
//c.如果你恰好要修改的是堆顶元素，那么是可以完成的：
int tp = pque.top();
pque.pop();
pque.push(tp+1);//现在堆顶是tp+1

	

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



//7.字符串 string
#include <string>
//顾名思义，就是存储字符串的
//A.常用方法
//string(长度,初值)
int main()
{
	string s;
	cin >> s;
	cout << s << endl;

	//用c语言的printf和scanf使用string
	/*string s1;
	char buf[100];
	scanf("%s", buf);
	s = buf;
	printf("%s", s1.c_str());*/


	string s1(100, '0');
	s1 = "awa";
	cout << s1 << endl;
	s1[0] = 'b';//可以直接修改
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
	//.substr(a,b)   a表示字串的起始下标，b表示a往后有b个字符；若参数未填写b，则从a开始的子字符串


	string sd = "123123123";
	cout << sd.find("312") << endl;//2    .find()返回的是起始点的下标
	cout << sd.find("312",5)<<endl;//5    .find(str,n)从下标为n开始查找字符串str
	if (sd.find("312") != string::npos)//如果找不到子字符串，.find()会返回 string::npos 这是设定好的
		cout << "Yes" << endl;


	string se = "123123123";
	int x = stoi(se);//stoi():将字符类型转化为整型   string to integer
	long long y = stoll(se);//string to long long
	float z = stof(se);
	double q = stod(se);
	long double w = stold(se);
	cout << x << endl;


	int integer = 6662;
	string sf = to_string(integer);
	cout << sf << endl;


	
	//在特定位置插入
	string str1="Working people ";
    string str2="Working soul ";
    string str3="Working people are Exalted";

    //string &insert(int p0, const char *s)
    //在原字符串下标为pos的字符前插入字符串str
    //返回值：插入字符串后的结果

    auto str=str1.insert(15,"Working soul ");
    cout<<"str1: "<<str1<<endl;                          		//str1: Working people Working soul
    cout<<"str: "<<str<<endl;                           	 	 //str: Working people Working soul

    //string &insert(int p0, const char *s, int n);
    //在p0位置插入字符串s的前n个字符
    //返回值：插入字符串后的结果

    str=str1.insert(28,"Working people are Exalted",26);
    cout<<"str1: "<<str1<<endl;                         	     //str1: Working people Working soul Working people are Exalted
    cout<<"str: "<<str<<endl;                                   //str: Working people Working soul Working people are Exalted


	return 0;
}


//B.适用情形
//    夯


//C.注意事项
//a.尾接字符串一定要用 +=
//string的+=运算符，将会在原字符串原地尾接字符串
//而+了再=赋值，会先生成一个临时变量，再复制给string，通常字符串长度可以很长，如果使用+字符串就很容易TLE了
// 
// 优化前：15139ms
// string s;
// for(int i = 0;i<5e5;i++)
//     s = s + "a";
// 
// 优化后：< 1ms （计时器显示0）
// string s;
// for(int i = 0;i<5e5;i++)
//     s+="a";

//b. .substr()方法的奇葩参数
//一定要注意，C++ string 的取子串的第一个参数是子串起点下标，第二个参数是子串长度
//第二个参数不是子串终点！！！

//c. .find方法的复杂度
//该方法实现为暴力实现，时间复杂度为O(n^2)



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
	p.first = 11;//可以直接修改
	int tmp = p.second;//也可以直接取值

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

//reverse
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


