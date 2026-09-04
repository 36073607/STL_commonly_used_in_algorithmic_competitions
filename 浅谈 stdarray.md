## 浅谈 std::array

`std::array` 是 C++11 引入的一个容器，它是对原生 C 语言数组的封装。你可以把它理解为**“一个知道自己大小、支持迭代器、且不会退化成指针的 C 数组”**。

如果你常用 `std::vector`，理解 `std::array` 最核心的一点是：**`std::array` 的大小在编译期就已经确定，且不可改变。** 它不会在堆上动态分配内存，而是直接分配在栈上（或作为对象的一部分连续分配）。

下面为你详细梳理 `std::array` 的用法，并与 `vector` 做对比。

### 1. 基本用法与初始化

使用前需要包含头文件 `#include <array>`。声明时必须指定**元素类型**和**大小**（大小必须是编译期常量）。

```cpp
#include <array>
#include <iostream>

int main() {
    // 1. 默认初始化（未初始化的元素值是未定义的，与 C 数组一样）
    std::array<int, 5> arr1; 

    // 2. 列表初始化（推荐）
    std::array<int, 5> arr2 = {1, 2, 3, 4, 5};
    
    // 3. C++17 的 CTAD（类模板参数推导），可以省略类型
    std::array arr3 = {1.0, 2.0, 3.0}; // 自动推导为 std::array<double, 3>

    // 4. 全部初始化为 0（这在刷题或算法中很常用）
    std::array<int, 5> arr4 = {}; // 所有元素均为 0
    
    // 5. 全部初始化为特定值（例如 -1）
    std::array<int, 5> arr5;
    arr5.fill(-1); // 使用 fill 方法
}
```

### 2. 常用成员函数

`std::array` 的接口设计得和 `std::vector` 非常像，但由于不能改变大小，所以没有 `push_back`、`pop_back` 等方法。

```cpp
std::array<int, 5> arr = {10, 20, 30, 40, 50};

// --- 元素访问 ---
arr[0] = 100;          // 类似 vector，不做边界检查，速度快
arr.at(1) = 200;       // 做边界检查，越界抛出 std::out_of_range 异常
int first = arr.front(); // 访问第一个元素 (100)
int last = arr.back();   // 访问最后一个元素 (50)

// --- 迭代器 ---
// 支持 C++11 范围 for 循环
for (int x : arr) { 
    std::cout << x << " ";
}
auto it = arr.begin(); // 正向迭代器
auto rit = arr.rbegin(); // 反向迭代器

// --- 容量 ---
// 注意：array 没有 resize 和 reserve
bool isEmpty = arr.empty(); // false
size_t size = arr.size();   // 5
size_t maxSize = arr.max_size(); // 5 (对于 array，max_size 和 size 总是相等的)

// --- 修改操作 ---
arr.fill(0); // 将所有元素重置为 0
std::array<int, 5> arr2 = {1, 2, 3, 4, 5};
arr.swap(arr2); // 交换两个 array 的内容（要求大小和类型完全一致）
```

### 3. `std::array` 与 `std::vector` 的核心对比

| 特性         | `std::vector`                    | `std::array`                   |
| :----------- | :------------------------------- | :----------------------------- |
| **大小**     | 动态变化 (`push_back`, `resize`) | 编译期固定，不可改变           |
| **内存位置** | 堆 (Heap) 动态分配               | 栈 (Stack) 或连续内嵌于对象中  |
| **分配开销** | 有（可能触发扩容拷贝）           | 无（零开销抽象）               |
| **内存布局** | 指针指向另一块堆内存             | 数据本身就在原地（连续内存）   |
| **大小信息** | 运行期保存在对象内部             | 编译期就已经确定，类型的一部分 |

### 4. 为什么用 `array` 替代 `vector` 能解决你的超时（TLE）问题？

回到你之前的三维 DP 代码：
```cpp
// 旧代码：导致 TLE
vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(3, vector<ll>(3, -1)));

// 新代码：优化后
vector<array<array<ll, 3>, 3>> dp(n);
```

**这其中的性能差异是巨大的，原因如下：**

1. **内存分配次数暴降**：
   * 旧代码：1次外层 `vector` 分配 + $n$ 次中层 `vector` 分配 + $3n$ 次内层 `vector` 分配 = **$4n + 1$ 次堆内存分配**。当 $n = 10^5$ 时，需要 40万次 `new` 操作，极度耗时。
   * 新代码：只有 1 次外层 `vector` 的堆内存分配。内层的 `array<array<ll, 3>, 3>` 是直接嵌入在 `vector` 的连续内存块里的，不需要额外分配。

2. **缓存局部性极强**：
   * 旧代码：内层 `vector` 的数据散落在堆的各个角落。当递归访问 `dp[i][cnt][pre]` 时，CPU 经常会发生 Cache Miss，去缓慢的主存中取数据。
   * 新代码：所有数据紧密排列在一块连续内存中。CPU 预取器 能轻松预测并加载数据到 L1/L2 缓存，访问速度成倍提升。

### 5. 多维 `std::array` 怎么写和用？

多维 `array` 看起来有些“吓人”，因为尖括号嵌套比较多，但它其实非常直观：

```cpp
// 定义一个 3行 4列 的二维 array
std::array<std::array<int, 4>, 3> matrix;

// 初始化二维 array
matrix = {{
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
}};

// 访问元素：和 vector 一样
int val = matrix[1][2]; // 7

// 使用类型别名让代码更整洁 (非常推荐的做法)
using Row = std::array<int, 4>;
using Matrix = std::array<Row, 3>;

Matrix mat2 = {{...}}; // 这样写就清晰多了
```

### 6. 什么时候该用谁？

*   **用 `vector` 当**：你不知道元素的确切数量，数据需要动态增删（如 `push_back`），或者数据量非常大。
*   **用 `array` 当**：
    1.  你确切知道数组的大小，且大小是固定的（比如维度已知是 3，或者转移状态表大小固定）。
    2.  你需要一个固定大小的局部缓存，且不想承受堆分配的开销。
    3.  作为类的成员变量，且大小固定，能让类对象的内存布局更加紧凑。
    4.  **在嵌套容器时（如 `vector<vector<T>>` 优化为 `vector<array<T, N>>`）**，这是在算法竞赛/刷题中最常用的优化手段之一。

**总结**：你可以把 `std::array` 当作一个带有 STL 接口（`.size()`, `.begin()`, `.fill()` 等）的“超级 C 数组”。在不涉及动态扩容的场景下，优先使用它能为你省去很多隐性的性能开销。



