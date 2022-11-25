@[TOC]
# 数据类型介绍
C语言基本的内置类型：

> <kbd> char </kbd>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **//字符数据类型**
<kbd> short </kbd> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**//短整型**
<kbd> int </kbd> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**//整形**
<kbd> long </kbd>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**//长整型**
<kbd> long long </kbd> &nbsp;**//更长的整形**
<kbd> float </kbd>**&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;//单精度浮点数**
<kbd> doule </kbd> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**//双精度浮点数**

**类型的意义：**

 1. 使用这个类型开辟内存空间的大小（大小决定了使用范围）。
2. 如何看待内存空间的视角。

## 类型的基本归类
**整型家族：**

> **char
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;unsigned char
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;signed char
short
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;unsigned short [int]
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;signed short [int]
int
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;unsigned int
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;signed int
long
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;unsigned long [int]
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;signed long [int]**

**浮点数家族：**

> **float
double**

**构造类型：**

> + **数组类型**
> + **结构体类型 <kbd> struct </kbd>**
> + **枚举类型 <kbd> enum </kbd>**
> + **联合类型 <kbd>union </kbd>**

**指针类型：**
>i**nt\* pi;
char\* pc;
float\* pf;
void\* pv;**

**空类型：**

> **void 表示空类型（无类型）
通常应用于函数的返回类型、函数的参数、指针类型。**

# 整型在内存中的存储
一个变量的创建是要在内存中开辟空间的。空间的大小是根据不同的类型而决定的。
比如：

> **int  a = 10;**
> **int   b  = -20;**

我们都知道为int分配四个字节，那究竟是如何存储的？

下来了解下面的概念：
## 原码、反码、补码
计算机中的有符号数有三种表示方法，即**原码、反码和补码**。
三种表示方法均有符号位和数值位两部分，符号位都是用**0表示“正”，用1表示“负”**，而数值位三种表示方法各不相同。

**正整数的原码反码补码相同。**
而负整数：
**原码**：
直接将二进制按照正负数的形式翻译成二进制就可以。
**反码**：
将原码的符号位不变，其他位依次按位取反就可以得到了。
**补码：**
反码+1就得到补码。

**对于整形来说：<font color=red size=3>数据存放内存中其实存放的是补码。</font>** 
![在这里插入图片描述](https://img-blog.csdnimg.cn/97f45a01a5c749749c75c948403bde85.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_36,color_FFFFFF,t_70,g_se,x_16)
为什么呢？

> 在计算机系统中，数值一律用补码来表示和存储。原因在于，使用补码，可以将符号位和数值域统一处理；
> 同时，加法和减法也可以统一处理（CPU只有加法器）此外，补码与原码相互转换，其运算过程是相同的，不需要额外的硬件电路。

在内存中的存储：
![在这里插入图片描述](https://img-blog.csdnimg.cn/598c4dc2e0434e608a8ebd9c6d15c968.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_25,color_FFFFFF,t_70,g_se,x_16)
我们可以发现a和b在内存中存储的都是补码。
**但是顺序却是反的。**这又是为什么？

<br>

## 大小端介绍
**大小端字节序：**

> **大端（存储）模式，是指数据的低位保存在内存的高地址中，而数据的高位，保存在内存的低地址中；
小端（存储）模式，是指数据的低位保存在内存的低地址中，而数据的高位,，保存在内存的高地址中。**

![在这里插入图片描述](https://img-blog.csdnimg.cn/896d617442dd4429be2956cacb39cbdf.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_32,color_FFFFFF,t_70,g_se,x_16)
**为什么有大端和小端：**

> **这是因为在计算机系统中，我们是以字节为单位的，每个地址单元都对应着一个字节，一个字节为8bit。但是在C语言中除了8bit的char之外，还有16bit的short型，32bit的long型（要看具体的编译器），另外，对于位数大于8位的处理器，例如16位或者32位的处理器，由于寄存器宽度大于一个字节，那么必然存在着一个如果将多个字节安排的问题。因此就导致了大端存储模式和小端存储模式。**


**百度2015年系统工程师笔试题：**
请简述大端字节序和小端字节序的概念，设计一个小程序来判断当前机器的字节序。（10分）

```c
#include <stdio.h>
int check_sys()
{
	int a = 1;
	return (*(char*)&a);
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}
```

> 站在char*的角度去解引用，拿到的是内存中第一个字节的内容，如果是1，就代表低位存储在低地址，就为小端字节序存储；如果是0，就代表高位存储在低地址，就为大端字节序存储。

![在这里插入图片描述](https://img-blog.csdnimg.cn/5bc45806826a4264a270952a589355d6.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_27,color_FFFFFF,t_70,g_se,x_16)
## 隐式类型转换
C的整型算术运算总是至少以缺省整型类型的精度来进行的。
为了获得这个精度，表达式中的字符和短整型操作数在使用之前被转换为普通整型，这种转换称为**整型提升**。
### 整型提升

> **表达式的整型运算要在CPU的相应运算器件内执行，CPU内整型运算器(ALU)的操作数的字节长度一般就是int的字节长度，同时也是CPU的通用寄存器的长度。因此，即使两个char类型的相加，在CPU执行时实际上也要先转换为CPU内整型操作数的标准长度。
通用CPU（general-purpose CPU）是难以直接实现两个8比特字节直接相加运算（虽然机器指令中可能有这种字节相加指令）。所以，表达式中各种长度可能小于int长度的整型值，都必须先转换为int或unsigned int，然后才能送入CPU去执行运算。**

例子：

```c
#include <stdio.h>
int main()
{
     char a = 3;
     char b = 127;
     char c = a + b;
     printf("%d", a):
     return 0;
}
```
a和b的值被提升为普通整型，然后再执行加法运算。
加法运算完成之后，结果将被截断，然后再存储于c中。

**如何进行整型提升呢？**

+  **整型提升是按照变量的数据类型的符号位来提升的。**

> **//负数的整形提升 char c1 = -1;** 
> **变量c1的二进制位(补码)中只有8个比特位： 1111111 
> 因为 char 为有符号的char** 
> **所以整形提升的时候，高位补充符号位，即为1 提升之后的结果是： 11111111111111111111111111111111**
> 
> **//正数的整形提升 char c2 = 1; 
>  变量c2的二进制位(补码)中只有8个比特位： 00000001
>   因为 char 为有符号的char
>    所以整形提升的时候，高位补充符号位，即为0 提升之后的结果是： 00000000000000000000000000000001**
>    
> **//无符号整形提升，高位补0**

运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/3192db78f91a4d3f893021cb9d078a73.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_18,color_FFFFFF,t_70,g_se,x_16)

![在这里插入图片描述](https://img-blog.csdnimg.cn/f4848da1ef59494d9e0b1ca48254e20a.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_22,color_FFFFFF,t_70,g_se,x_16)

## 例题
```c
1.
//输出什么？
#include <stdio.h>
int main()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("a=%d,b=%d,c=%d", a, b, c);
	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/822f865b91044578b5120af4a5c91416.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_18,color_FFFFFF,t_70,g_se,x_16)

![在这里插入图片描述](https://img-blog.csdnimg.cn/9fbf0b613cec4869a772ee04e2f01c5c.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_23,color_FFFFFF,t_70,g_se,x_16)

```c
2.
#include <stdio.h>
int main()
{
	char a = -128;
	printf("%u\n", a);
	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/291953685bef4aed87937d7bd98fbff8.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_14,color_FFFFFF,t_70,g_se,x_16)
![在这里插入图片描述](https://img-blog.csdnimg.cn/b1db8a44d7eb44e4b032f587e92a0ccc.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_22,color_FFFFFF,t_70,g_se,x_16)

```c
3.
#include <stdio.h>
int main()
{
	char a = 128;
	printf("%u\n", a);
	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/25de90cbcc594230a59bfcc3f18411c5.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_16,color_FFFFFF,t_70,g_se,x_16)

这题与第二题相似，整型提升后截断存入a的都是10000000，所以打印的值也是4294967168。

```c
4.
#include <stdio.h>
int main()
{
	int i = -20;
	unsigned int j = 10;
	printf("%d\n", i + j);
	//按照补码的形式进行运算，最后格式化成为有符号整数
	return 0;
}
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/c22c4e67af6446fe831a22c807d1030c.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_25,color_FFFFFF,t_70,g_se,x_16)

```c
5.
#include <stdio.h>
int main()
{
	unsigned int i;
	for (i = 9; i >= 0; i--)
	{
		printf("%u\n", i);
	}
	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/71b1d6550fd24bd48d543c3fd6c24c08.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_17,color_FFFFFF,t_70,g_se,x_16)
+ 因为i是无符号的int，i自减到0时，i = -1时补码存储的是32个1，而%u以无符号的形式打印，就会打印32个1所对应的十进制数字，造成程序死循环。

```c
6.
#include <stdio.h>
int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", strlen(a));
	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/18cfa8094f834b048e089d9a4cbdfcac.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_17,color_FFFFFF,t_70,g_se,x_16)
**题目要求字符长度，也就计算'\0'前面一共有几个字符，'\0'的ASCII码值是0，也就是计算0之前有几个字符。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/f951699b511d4e36854b487bf44779b1.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)
# 浮点型在内存中的存储
常见的浮点数：
3.14159 1E10 浮点数家族包括： **float、double、long double** 类型。 浮点数表示的范围：float.h中定义。

浮点数存储的例子：

```c
#include <stdio.h>
int main()
{
	int n = 9;
	float* pFloat = (float*)&n;
	printf("n的值为：%d\n", n);
	printf("*pFloat的值为：%f\n", *pFloat);
	*pFloat = 9.0;
	printf("num的值为：%d\n", n);
	printf("*pFloat的值为：%f\n", *pFloat);
	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/6b7a0a36fec7404f8ab32d2f82f5ea2f.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)
num 和 *pFloat 在内存中明明是同一个数，为什么浮点数和整数的解读结果会差别这么大？ 要理解这个结果，一定要搞懂浮点数在计算机内部的表示方法。

**根据国际标准IEEE（电气和电子工程协会） 754，任意一个二进制浮点数V可以表示成下面的形式**：
+ (-1)^S * M * 2^E
+ (-1)^s表示符号位，当s=0，V为正数；当s=1，V为负数。
+ M表示有效数字，大于等于1，小于2。
+ 2^E表示指数位。
![在这里插入图片描述](https://img-blog.csdnimg.cn/7c74525bdab0472a88ec30b3e9271131.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_19,color_FFFFFF,t_70,g_se,x_16)
**IEEE 754规定： 对于32位的浮点数，最高的1位是符号位s，接着的8位是指数E，剩下的23位为有效数字M。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/c9106353757f4fd0aa1fa3c7843e287a.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)
**对于64位的浮点数，最高的1位是符号位S，接着的11位是指数E，剩下的52位为有效数字M。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/ae8669b7ba864a2e8ddb77b42e014d96.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)
**IEEE 754对有效数字M和指数E，还有一些特别规定**。 前面说过， 1≤M<2 ，也就是说，M可以写成 1.xxxxxx 的形式，其中xxxxxx表示小数部分。IEEE 754规定，在计算机内部保存M时，默认这个数的第一位总是1，因此可以被舍去，只保存后面的xxxxxx部分。比如保存1.01的时候，只保存01，等到读取的时候，再把第一位的1加上去。这样做的目的，是节省1位有效数字。
以32位浮点数为例，留给M只有23位，将第一位的1舍去以后，等于可以保存24位有效数字。
**至于指数E，情况就比较复杂。**
**首先，E为一个无符号整数（unsigned int）** 这意味着，如果E为8位，它的取值范围为0\~255；如果E为11位，它的取值范围为0\~2047。但是，我们知道，科学计数法中的E是可以出现负数的，所以IEEE 754规定，存入内存时E的真实值必须再加上一个中间数，对于8位的E，这个中间数是127；对于11位的E，这个中间数是1023。比如，2^10的E是10，所以保存成32位浮点数时，必须保存成10+127=137，即10001001

**然后，指数E从内存中取出还可以再分成三种情况：**

**E不全为0或不全为1**

>**这时，浮点数就采用下面的规则表示，即指数E的计算值减去127（或1023），得到真实值，再将有效数字M前加上第一位的1。 比如： 0.5（1/2）的二进制形式为0.1，由于规定正数部分必须为1，即将小数点右移1位，则为1.0*2^(-1)，其阶码为-1+127=126，表示为01111110，而尾数1.0去掉整数部分为0，补齐0到23位00000000000000000000000，则其二进制表示形式为:0 01111110 00000000000000000000000.**

**E全为0**

> **这时，浮点数的指数E等于1-127（或者1-1023）即为真实值， 有效数字M不再加上第一位的1，而是还原为0.xxxxxx的小数。这样做是为了表示±0，以及接近于0的很小的数字。**

**E全为1**

> **这时，如果有效数字M全为0，表示±无穷大（正负取决于符号位s）；**

**解释前面的题目：**

下面，让我们回到一开始的问题：为什么 0x00000009 还原成浮点数，就成了 0.000000 ？ 首先，将 0x00000009 拆分，得到第一位符号位s=0，后面8位的指数 E=00000000 ，最后23位的有效数字M=000 0000 0000 0000 0000
1001。

> **9 -> 0000 0000 0000 0000 0000 0000 0000 1001**
> 
由于指数E全为0，所以符合上一节的第二种情况。因此，浮点数V就写成： V=(-1)^0 ×0.00000000000000000001001×2\^(-126)=1.001×2^(-146) 显然，V是一个很小的接近于0的正数，所以用十进制小数表示就是0.000000。


再看例题的第二部分。 请问浮点数9.0，如何用二进制表示？还原成十进制又是多少？ 首先，浮点数9.0等于二进制的1001.0，即1.001×2^3。

> **9.0 -> 1001.0 ->(-1)^01.0012^3 -> s=0, M=1.001,E=3+127=130**

那么，第一位的符号位s=0，有效数字M等于001后面再加20个0，凑满23位，指数E等于3+127=130，即10000010。 所以，写成二进制形式，应该是s+E+M，即

> **0 10000010 001 0000 0000 0000 0000 0000**
> 
这个32位的二进制数，还原成十进制，正是 1091567616 。
