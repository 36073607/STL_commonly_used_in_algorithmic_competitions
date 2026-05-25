### 浅谈C++ std::bitset

`std::bitset` 是 C++ 标准库 (`<bitset>`) 中提供的一个非常强大的容器，专门用于存储和操作二进制位（0 和 1）。

与传统的位运算（使用 `int` 或 `unsigned int` 配合 `&`, `|`, `<<` 等）相比，`bitset` 的优势在于：**代码可读性极高、支持任意长度（不受 32/64 位整型限制）、自带越界检查，并且可以极其方便地与字符串和整型进行相互转换。**

下面详细介绍 `bitset` 及其高频常用方法。

### 一、 核心特性与构造

`bitset` 的大小（位数）必须在编译时确定，作为模板参数传入。

```cpp
#include <iostream>
#include <bitset>
#include <string>

int main() {
    // 1. 默认构造：所有位初始化为 0
    std::bitset<8> b1; 
    std::cout << b1 << std::endl; // 输出: 00000000

    // 2. 使用无符号整型构造（只能是 unsigned long long 或整型）
    // 从低位开始填充，多余高位截断，不足高位补0
    std::bitset<8> b2(42); // 42 的二进制是 101010
    std::cout << b2 << std::endl; // 输出: 00101010

    // 3. 使用字符串构造（极其常用！）
    // 注意：字符串的最右侧字符对应 bitset 的最低位 (下标0)
    std::bitset<8> b3("10101010"); 
    std::cout << b3 << std::endl; // 输出: 10101010

    // 4. 使用字符串的部分构造 (C++11)
    // 参数：字符串, 起始位置, 字符数量
    std::string s = "xx101010xx";
    std::bitset<8> b4(s, 2, 8); // 从索引2开始取8个字符
    std::cout << b4 << std::endl; // 输出: 10101010

    return 0;
}
```

**⚠️ 极其重要的坑（下标与顺序）**：

 `bitset` 的下标是从**右向左**计算的，这符合二进制的位权规则。

 `b[0]` 是最低位（最右边），`b[N-1]` 是最高位（最左边）。 

当你使用 `cout << b` 输出时，屏幕上最左边的是高位 `b[N-1]`，最右边的是低位 `b[0]`。



### 二、 元素访问

#### 1. `operator[]`

和数组一样，可以通过下标访问或修改某一位。

```cpp
std::bitset<8> b(42); // 00101010
b[0] = 1;             // 将最低位改为1
// b 现在是 00101011 (即 43)
```

#### 2. `test(size_t pos)`

与 `[]` 功能相同，但**自带越界检查**。如果 `pos` 超出范围，会抛出 `std::out_of_range` 异常。在需要安全访问时推荐使用。

```cpp
std::bitset<8> b(42);
bool bit1 = b.test(1); // 返回第1位的值 (true/false)
// bool bit_error = b.test(10); // 抛出异常
```



### 三、 修改与位操作（高频使用）

`bitset` 封装了常用的位运算，语义非常清晰，省去了手写 `mask` 的麻烦。

#### 1. 单个位的操作

- **`set(pos)`**：将第 `pos` 位置 1。
- **`set(pos, val)`**：将第 `pos` 位设为 `val` (0 或 1)。
- **`reset(pos)`**：将第 `pos` 位置 0。
- **`flip(pos)`**：将第 `pos` 位取反（0变1，1变0）。

如果不带参数，则作用于所有位：

- **`set()`**：所有位置 1。
- **`reset()`**：所有位置 0。
- **`flip()`**：所有位取反。

```cpp
std::bitset<8> b; // 00000000
b.set(3);         // 00001000
b.set();          // 11111111
b.reset(7);       // 01111111
b.flip();         // 10000000
```

#### 2. 整体位运算符重载

`bitset` 完美重载了 C++ 的位运算符，可以直接对两个 bitset 进行运算，代码可读性拉满：

```cpp
std::bitset<4> a("1010");
std::bitset<4> b("1100");

auto c_and = a & b;  // 按位与: 1000
auto c_or  = a | b;  // 按位或: 1110
auto c_xor = a ^ b;  // 按位异或: 0110
auto c_not = ~a;     // 按位取反: 0101

a <<= 2;             // 左移2位: 1000 (低位补0)
b >>= 1;             // 右移1位: 0110 (逻辑右移，高位补0)
```



### 四、 状态查询（高频使用）

在算法竞赛或状态机开发中，这些方法极其常用：

- **`count()`**：返回值为 1 的位的个数。（内部常使用 SIMD 指令优化，比自己写循环快得多）。
- **`size()`**：返回总位数。
- **`all()`**：是否**所有位**都为 1？（C++11 引入）
- **`any()`**：是否**至少有一位**为 1？
- **`none()`**：是否**所有位**都为 0？

```cpp
std::bitset<8> b("10101000");
std::cout << b.count() << std::endl; // 3
std::cout << b.any()   << std::endl; // 1 (true)
std::cout << b.none()  << std::endl; // 0 (false)
std::cout << b.all()   << std::endl; // 0 (false)
```



### 五、 类型转换与输出

#### 1. `to_string()`

将 bitset 转换为 `std::string`。这在打印、日志或网络传输时非常有用。 还可以自定义用什么字符表示 0 和 1：

```cpp
std::bitset<8> b(42);

// 默认转换
std::string s1 = b.to_string(); // "00101010"

// 自定义字符 (用 '*' 表示1，用 '.' 表示0) - 常用于终端绘制图形
std::string s2 = b.to_string('.', '*'); // "..*.*.*."
```

#### 2. `to_ullong()` / `to_ulong()`

将 bitset 转换回无符号整数。

- `to_ulong()`: 转换为 `unsigned long`。
- `to_ullong()`: 转换为 `unsigned long long` (C++11 引入)。

**注意**：如果 bitset 的位数超过了目标整型的位数，或者包含了无法用无符号整型表示的值，会抛出 `std::overflow_error` 异常。

```cpp
std::bitset<8> b("101010");
unsigned long val = b.to_ulong(); // val = 42
```



### 六、 高频实战用例

#### 用例 1：标志位管理

代替定义多个 `bool` 变量，用一个 `bitset` 管理多个开关，既省内存又好操作。

```cpp
std::bitset<4> flags; // 假设有4个开关，默认全关
flags.set(0);         // 打开开关 0
flags.set(2);         // 打开开关 2

if (flags.test(0)) {
    std::cout << "开关 0 处于开启状态" << std::endl;
}
```

#### 用例 2：状态压缩 (状态压缩 DP)

在算法中，当需要枚举子集或记录某个元素是否被使用时，常把一个整数的二进制位当作集合使用。但对于超过 64 个元素的集合，整型装不下，此时 `bitset` 是完美的替代品。

```cpp
// 检查两个集合是否有交集
std::bitset<100> setA; // ... 赋值
std::bitset<100> setB; // ... 赋值

if ((setA & setB).any()) {
    std::cout << "集合有交集" << std::endl;
}
```

#### 用例 3：进制转换工具

`bitset` 是最稳健的十进制转二进制字符串的工具，自动处理前导零和负数（补码）。

```cpp
int num = -5;
// 完美输出32位补码: 11111111111111111111111111111011
std::string bin_str = std::bitset<32>(num).to_string(); 
```



