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
	arr8.resize(5,3);//ʣ������Ԫ��Ϊ3
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



//2.ջ stack
#include <stack>
//ͨ�����η�װ˫�˶���(deque)������ʵ���Ƚ������ջ���ݽṹ
//A.���÷���
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


//B.��������
//����ֱ������������Ҫ��дջ��
//���⣬vectorҲ���Ե�ջ�ã�vector�� .back() ȡβ��Ԫ�أ����൱��ջ��
//.push_back()�൱�ڽ�ջ��.pop_back()�൱�ڳ�ջ
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


//C.ע������
//���ɷ����ڲ�Ԫ�أ�ֻ��ѹջ�ͳ�ջ



//3.���� queue
#include <queue>
//ͨ�����η�װ˫�˶���(deque)������ʵ���Ƚ��ȳ��Ķ������ݽṹ
//A.���÷���
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


//B.��������
//����ֱ��ʹ�ö�������д����


//C.ע������
//�����Է����ڲ�Ԫ�أ�



//4.���ȶ��� priority queue (��)
#include <queue>
//�ṩ����ʱ������Ԫ�ز��ң�����ʱ��Ĳ�������ȡ���ײ�ԭ���Ƕ����
//A.���÷���
//a.����
//priority_queue<����,����,�Ƚ���> pque
//���ͣ�Ҫ�洢����������
//�������������ݵĵײ�������Ĭ��Ϊ vector<����> �������б���Ĭ�ϼ���
//�Ƚ������Ƚϴ�Сʹ�õıȽ�����Ĭ��Ϊ less<����> �����Զ���
int main()
{
	priority_queue<int> pque;
	pque.push(1);
	cout << pque.top() << endl;//�����ֳ�ʼ��1�£�.top()ȡ���Ѷ�(���е����ֵ)����Ȼ�����ǰѶѶ���ɾ��
	pque.push(3);
	cout << pque.top() << endl;
	pque.push(2);
	cout << pque.top() << endl;
	pque.push(4);
	cout << pque.top() << endl;

	pque.pop();//�����Ѷ�Ԫ�أ����Ԫ�أ�
	cout << pque.top() << endl;

	return 0;
}

int main()
{
	priority_queue<int,vector<int>,greater<int>> pque;//���С����
	pque.push(1);
	cout << pque.top() << endl;//���ֳ�ʼ���£�.top()ȡ���Ѷ�(���е���Сֵ)
	pque.push(3);
	cout << pque.top() << endl;
	pque.push(2);
	cout << pque.top() << endl;
	pque.push(4);
	cout << pque.top() << endl;

	pque.pop();//�����Ѷ�Ԫ�أ���СԪ�أ�
	cout << pque.top() << endl;

	return 0;
}


//B.��������
//����ά��Ԫ�ص������ԣ�ÿ������в����С������Ԫ�أ�����ÿ�δӶ�����ȡ�����/��С��Ԫ�أ�Ԫ������n,�����������k
//��ÿ�β������п�������k* nlog(n)
//    ʹ�����ȶ���ά����k* log(n)


//C.ע������
//a.���Ѷ��ɶ���ֻ�ɷ��ʶѶ�������Ԫ�ض��޷�ȡ��
//b.��������Ԫ�ض��ǲ����޸ĵ�
//c.�����ǡ��Ҫ�޸ĵ��ǶѶ�Ԫ�أ���ô�ǿ�����ɵģ�
int tp = pque.top();
pque.pop();
pque.push(tp+1);//���ڶѶ���tp+1

	

//5.���� set
#include <set>
//�ṩ����ʱ��Ĳ��룬ɾ�������ҵļ������ݽṹ���ײ�ԭ���Ǻ����
//������Ҫ��               ����                         set               multiset                 unordered_set
//  ȷ����     һ��Ԫ��Ҫô�ڼ����У�Ҫô����           ��                   ��                         ��
//  ������     һ��Ԫ�ؽ������ڼ����г���һ��           ��                   ��(�����)                 ��
//  ������     �����е�Ԫ����û��˳���                 ��(��С����)         ��(��С����)               ��

//A.���÷���
//a.����
//set<����,�Ƚ���> st
//���ͣ�Ҫ�������������
//�Ƚ������Ƚϴ�Сʹ�õıȽ�����Ĭ��Ϊ less<����> ,���Զ���
int main()
{
	set<int> st;
	st.insert(1);
	st.insert(2);
	st.insert(2);
	st.insert(0);
	//���ڻ����ԣ�������ֻ�� 1��2��0����Ԫ��
	st.erase(2);//��Ԫ��2ɾ��
	for (auto& ele : st)
	{
		cout << ele << endl;
	}

	if (st.find(1) != st.end())//.find()����һ��������������ҵ�1�Ļ��᷵��һ��ָ��һ�ĵ����������������set���Ҳ������᷵��β������
	{
		cout << "Yes" << endl;
	}

	if (st.count(1))//.count()���ص��Ǹ�Ԫ���ڼ������м���  ������set�Ļ����ԣ�.count()ֻ�����ַ���ֵ��1��0��������multiset�е��þͻ᷵�ؾ����м������ˣ�
	{
		cout << "Yes" << endl;
	}

	cout << st.size() << endl;
	st.clear();
	cout << st.empty() << endl;


	//������
	//ʹ�õ�������ѭ����
	for (set<int>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout << *it << endl;
	}
	//���ڷ�Χ��ѭ����C++ 11��
	for (auto& ele : st)//&����
	{
		cout << ele << endl;
	}

	return 0;
}
//��ɾ���ʱ�临�ӶȾ�Ϊ��O(log n)


//B.��������
//a.Ԫ��ȥ�أ�[1,1,3,2,4,4]->[1,2,3,4]
//b.ά��˳��[1,5,3,7,9]->[1,3,5,7,9]
//c.Ԫ���Ƿ���ֹ���Ԫ�ش�С[-10^18,10^18]��Ԫ������10^8��vis�����޷�ʵ�֣�ͨ��set�������
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


//C.ע������
//a.�������±�������set��˵���Ա�����������ʹ�õ��������б��������������±���һ����޷�ͨ���±���ʵ�����
cout << *st.begin() << endl;//����ͨ������������
//b.Ԫ��ֻ����set�ĵ�����ȡ����Ԫ����ֻ����(��Ϊ��const������)�������޸���ֵ�����Ҫ����Ҫ��erase��insert
//c.�����õ����������±�



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



//8.��Ԫ�� pair
#include <utility>
//����˼�壬���Ǵ����Ԫ���
//A.���÷���
//pair<��һ��ֵ����,�ڶ���ֵ����> pr
//��һ��ֵ���ͣ�Ҫ�洢�ĵ�һ��ֵ����������
//�ڶ���ֵ���ͣ�Ҫ�洢�ĵڶ���ֵ����������
int main()
{
	pair<int, int> p = { 1,2 };
	pair<int, int> p1 = make_pair(1, 2);   //��ʽ�ķ�ʽ
	cout << p.first << " " << p.second << endl;
	p.first = 11;//����ֱ���޸�
	int tmp = p.second;//Ҳ����ֱ��ȡֵ

	if (p == p1)
		cout << "Yes" << endl;

	pair<char, int> pp = { 'a',2 };

	pair<pair<char, int>, char> px;//��Ԫ��
	pair<pair<int, int>, pair<int, int>> pxx;//��Ԫ��

	return 0;
}


//B.��������
//������Ҫ��Ԫ��ĳ�������ʹ�ã�Ч�ʺ��Լ�����Ľṹ����


//C.ע������
//��






//������
//1.��������ʲô
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
//a.begin()��һ����������ָ����ǵ�һ��Ԫ��
//a.end()��һ����������ָ��������һ��Ԫ���ٺ���һλ
//����������������������������������������һ��Ԫ���ƶ�
//��������ָ�����ƣ��������ʹ�ý�����1���������� *it ������ȡ����Ӧֵ��


//2.Ϊ����Ҫ������
//�ܶ����ݽṹ���������Եģ����������������ڷ����Խṹ���±���������ģ��޷�ʹ���±��������������ݽṹ
//�����������þ��Ƕ���ĳ�����ݽṹ�ı�����ʽ��ͨ���������������������������λ�ã�ͨ�����������ܳɹ����������Խṹ��
//���磬set��ʵ���Ǻ������������û��ͨ���±�������Ԫ�صģ�����ͨ�������������ǾͿ��Ա���set�е�Ԫ���ˣ�
int main()
{
	set<int> st;
	for (set<int>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout << *it << endl;
	}
}



//3.�������÷�
//����vector���������ĵ��������ܱȽ����ƣ�����������
//.begin()  ͷ������
//.end()  β������
//.rbegin()  ����ͷ������
//.rend()  ����β������
//������+���ͣ��������������ƶ�
//������-���ͣ�����������ǰ�ƶ�
//������++��������������ƶ�һλ
//������--������������ǰ�ƶ�һλ
//������-�������������������ľ���
//prev(it)������it��ǰһ��������
//next(it)������it�ĺ�һ��������
//��������������������ṹ���ԣ�����Ĺ��ܲ�һ�����У�����set�ĵ������ǲ�����������ģ�


//4.��������
//a. .end()��.rend()ָ���λ�����������ֵ
//b. ��ͬ�����ĵ��������ܿ��ܲ�һ��
//c. ɾ������ʱ��Ҫ���裨���õ���������������������






//�㷨
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

//sort ����������
int main()
{
	vector<int> arr{ 1,9,1,9,8,1,0 };
	sort(arr.begin(), arr.end());//��С������
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}


	sort(arr.begin(), arr.end(), greater<int>());//�Ӵ�С��
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;

	return 0;
}
//�Զ���Ƚ���
bool cmp(pair<int, int> a, pair<int, int> b)//��cmp��������true,��ʾ����Ԫ��λ������ȷ�ģ�����Ҫ����λ��
{
	//pair�ڶ�λ��С����
	if (a.second != b.second)
		return a.second < b.second;//ע�ⲻҪ���Ⱥ�
	//pair��һλ�Ӵ�С
	return a.first > b.first;//ע�ⲻҪ���Ⱥ�
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

//���ֲ��� : lower_bound()  /  upper_bound()
//�� ���������� ��Ԫ���У�Ӧ�ö��ֲ��Ҽ���ָ��Ԫ�أ����ض�ӦԪ�ص�����λ�ã��Ҳ����򷵻�β������
//lower_bound() ��Ѱ��>=x�ĵ�һ��Ԫ�ص�λ��
//upper_bound() ��Ѱ��>x�ĵ�һ��Ԫ�ص�λ��
//Q:��ô�� <=x / <x �ĵ�һ��Ԫ�أ�
// >x �ĵ�һ��Ԫ�ص�ǰһ��Ԫ�أ�����У�����<=x�ĵ�һ��Ԫ��
// >=x �ĵ�һ��Ԫ�ص�ǰһ��Ԫ�أ�����У�����<x�ĵ�һ��Ԫ��
//Q:���ص��ǵ����������ת���±������أ���ȥͷ����������
int main()
{
	vector<int> arr{ 0,1,1,1,8,9,9 };
	int pos1 = lower_bound(arr.begin(), arr.end(), 8) - arr.begin();
	int pos2 = upper_bound(arr.begin(), arr.end(), 8) - arr.begin();
	cout << pos1 << " " << pos2 << endl;//4 5

	int posa = lower_bound(arr.begin() + 2, arr.end(), 0) - arr.end();//�����Լ����ڲ��ҷ�Χ

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

	reverse(arr.begin() + 2, arr.begin() + 6);//�����Զ�����ת��һС������

	return 0;
}

//max/min
int main()
{
	cout << max(max(1, 3), 4) << endl;
	cout << max({ 1,3,5,2 }) << endl;//C++11�Ժ��������д
	cout << min(1, 3) << endl;

	return 0;
}

//unique ȥ��
//����������ظ�����Ԫ�أ����鳤�Ȳ��䣬������Ч�������̣����ص�����Ч����λ�õĽ�β������
//���磺[1,1,4,5,1,4]--->>[1,4,5,1,4,?]
//ע��
//����ʹ��unique�����ܴ��ȥ��Ч������Ϊ��ֻ�������ڵ��ظ�Ԫ�أ������������������ô������ȥ����
//������ȥ�غ�����β�������һЩ��Ч���ݣ�[1,1,2,4,4,4,5]-->>[1,2,4,5,?,?,?],Ϊ��ɾ����Щ��Ч���ݣ�������Ҫ���erase
int main()
{
	vector<int> arr{ 1,2,1,4,5,4,4 };
	sort(arr.begin(), arr.end());
	//1,1,2,4,4,4,5
	//1,2,4,5,*,?,?
	//unique(arr.begin(), arr.end());//unique()�ķ���ֵ��*��λ�õĵ�����
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (auto& ele : arr)
	{
		cout << ele << endl;
	}

	return 0;
}

//��ѧ����
//����ֵ abs()
//e^x  exp()
//lnx  log()
//x^y  pow()
//����x  sqrt()
//����ȡ��  ceil()
//����ȡ��  floor()
//��������  round()

//gcd()���Լ�� / lcm()��С������   C++17֧��
//�Լ��ִ�һ��Ҳͦ��
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
