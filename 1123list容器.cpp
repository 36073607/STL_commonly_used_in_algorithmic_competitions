#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//list 双向链表容器
#include <list>

//push_back(const T& val)	         在链表末尾添加元素
//push_front(const T& val)	         在链表头部添加元素
//pop_back()	                     删除链表末尾的元素
//pop_front()	                     删除链表头部的元素
//insert(iterator pos, val)	         在指定位置插入元素
//erase(iterator pos)	             删除指定位置的元素
//clear()	                         清空所有元素
//size()	                         返回链表中的元素数量
//empty()	                         检查链表是否为空
//front()	                         返回链表第一个元素
//back()	                         返回链表最后一个元素
//remove(const T& val)	             删除所有等于指定值的元素
//sort()	                         对链表中的元素进行排序
//merge(list& other)	             合并另一个已排序的链表
//reverse()	                         反转链表
//begin() / end()	                 返回链表的起始 / 结束迭代器

#include <iostream>
#include <list>

int main() {
    // 创建一个整数类型的列表
    std::list<int> numbers;

    // 向列表中添加元素
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // 访问并打印列表的第一个元素
    std::cout << "First element: " << numbers.front() << std::endl;

    // 访问并打印列表的最后一个元素
    std::cout << "Last element: " << numbers.back() << std::endl;

    // 遍历列表并打印所有元素
    std::cout << "List elements: ";
    for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 删除列表中的最后一个元素
    numbers.pop_back();

    // 再次遍历列表并打印所有元素
    std::cout << "List elements after removing the last element: ";
    for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}


//1、基本操作
#include <iostream>
#include <list>

int main() {
    std::list<int> lst = { 10, 20, 30 };

    // 插入和删除元素
    lst.push_front(5);           // 在头部插入5
    lst.push_back(40);           // 在尾部插入40
    lst.pop_front();             // 删除头部元素
    lst.pop_back();              // 删除尾部元素

    // 输出链表内容
    std::cout << "List elements: ";
    for (const auto& elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

//2、插入和删除特定位置的元素
#include <iostream>
#include <list>

int main() {
    std::list<int> lst = { 1, 2, 3, 4, 5 };
    auto it = lst.begin();
    std::advance(it, 2);          // 移动迭代器到第3个元素（值为3）

    lst.insert(it, 10);           // 在第3个元素前插入10
    lst.erase(it);                // 删除第3个元素

    // 输出链表内容
    std::cout << "List elements: ";
    for (const auto& elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

//3、排序和去重
#include <iostream>
#include <list>
//sort() 函数模板定义在头文件 algorithm 中，要求使用随机访问迭代器。
//但 list 容器并不提供随机访问迭代器，只提供双向迭代器，因此不能对 list 中的元素使用 sort() 算法。
int main() {
    std::list<int> lst = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    lst.sort();                    // 排序
    lst.unique();                  // 删除相邻重复元素

    // 输出链表内容
    std::cout << "Sorted and unique list: ";
    for (const auto& elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
//list.sort()自定义排序：
bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    list<int> L1 = { 1,4,2,7 };
    L1.sort();
    for (auto it = L1.begin(); it != L1.end(); it++)
    {
        cout << *it;
    }
    cout << endl;

    list<int> L2 = { 1,4,2,7 };
    L2.sort(cmp);
    for (list<int>::iterator it = L2.begin(); it != L2.end(); it++)
        cout << *it;


    return 0;
}


//4、合并和反转
#include <iostream>
#include <list>

int main() {
    std::list<int> lst1 = { 1, 3, 5, 7 };
    std::list<int> lst2 = { 2, 4, 6, 8 };

    lst1.merge(lst2);              // 合并两个已排序的链表
    lst1.reverse();                // 反转链表

    // 输出链表内容
    std::cout << "Merged and reversed list: ";
    for (const auto& elem : lst1) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
