#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
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

	//在指定位置插入：
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


	//删除
	string reverse_str(string str)
	{
    	int count = 0;
    	for (int i = 0; i < str.size(); i++)
    	{
        	if (str[i] == '0')
            	count++;
        	else
            	break;
    	}
    	str.erase(str.begin(), str.begin() + count);
	}
	return 0;
}


//append
//append函数常用的三个功能：
//直接添加另一个完整的字符串:如str1.append(str2);
//添加另一个字符串的某一段子串:如str1.append(str2, 11, 7);
//添加几个相同的字符:如str1.append(5, ‘.’);注意,个数在前字符在后.上面的代码意思为在str1后面添加5个"."

	string str1="I like C++";  
    string str2=",I like the world.";  
    string str3="Hello";  
    string str4("Hi");  
    //====================================  
    str1.append(str2);  
    str3.append(str2, 11, 7);  
    str4.append(5, '.');  
    //====================================  
    cout<<str1<<endl;  //I like C++,I like the world.
    cout<<str3<<endl;  //Hello World.
    cout<<str4<<endl;  //Hi.....



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




