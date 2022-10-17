

@[TOC](操作符分类)
# 算术操作符

> \+    &nbsp;&nbsp;&nbsp;&nbsp;   \-  &nbsp;&nbsp;&nbsp;  &nbsp;*&nbsp;&nbsp;&nbsp;&nbsp;/&nbsp;&nbsp;&nbsp;&nbsp;%
 
 **注**：
 1. 除了 <kbd>% </kbd>操作符之外，其他的几个操作符可以作用于整数和浮点数。
 2. 对于 <kbd>/ </kbd>操作符如果两个操作数都为整数，执行整数除法。而只要有浮点数执行的就是浮点数除法。
 3. <kbd>% </kbd>操作符的两个操作数必须为整数。返回的是整除之后的余数。  
   <br />
# 移位操作符
> <font color=red size=3><<</font> &nbsp;&nbsp;&nbsp;左移操作符
> <font color=red size=3>>></font> &nbsp;&nbsp;&nbsp;右移操作符

  <br />
  
## 原码、补码、反码
+ 正整数的原码补码反码是相等的。
+ 负整数的原码是按数字正负写出的二进制序列。
+ 负整数的反码是符号位不变，其他位按位取反。
+ 负整数的补码是反码+1。

<font color=red size=3>在计算机系统中，整数一律用**补码**来表示和存储。</font>
 <br />
## 左移操作符移位规则
> 左边弃位、右边补0

![在这里插入图片描述](https://img-blog.csdnimg.cn/314c6f1300cc4c4888bae1c062b454e2.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
例如：

```c
int a = 5;
int b = a << 5;
```

> 00000000000000000000000000000101 - a的补码
> 00000000000000000000000000001010 - 左移后的补码
> 正整数原反补码相同，可得b的值为10。

**注意**：

&nbsp;&nbsp;&nbsp;&nbsp; **实际上num在没有被赋值的情况下，左移后自身的值不会变化。**
 <br />
## 右移操作符 移位规则

> 首先右移运算分两种：
>1. **逻辑移位** 左边用0填充，右边丢弃
>2. **算术移位** 左边用原该值的符号位填充，右边丢弃

![在这里插入图片描述](https://img-blog.csdnimg.cn/090179dab04e48dbbcf7e65234634397.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
**补充**：
+ 左移使原数值增大2倍，右移是原数值缩小两倍。
+ 对于移位运算符，不要移动负数位，这个是标准未定义的。

<br>

# 位操作符

> <kbd> &</kbd>  &nbsp;&nbsp;&nbsp;&nbsp; <font color=orange size=3>//按位与</font> 
> <kbd> |</kbd>  &nbsp;&nbsp;&nbsp;&nbsp; <font color=orange size=3>//按位或</font> 
> <kbd> \^</kbd>  &nbsp;&nbsp;&nbsp;&nbsp; <font color=orange size=3>//按位异或</font> 

**练习**：

```c
#include <stdio.h>
int main()
{
	int num1 = 1;
	int num2 = 2;
	num1& num2;
	num1 | num2;
	num1^ num2;
	return 0;
}
```
**num1&num2**：
![在这里插入图片描述](https://img-blog.csdnimg.cn/40fe1634afe545e28cfc62239731e269.png)
**num1 | num2**：
![在这里插入图片描述](https://img-blog.csdnimg.cn/1284d250e72a4ebabbdb60e045a99716.png)
**num1\^num2**:
![在这里插入图片描述](https://img-blog.csdnimg.cn/e85b37e6a7a243a4bad408d0f680810b.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
**一道变态的面试题**：

> 不能创建临时变量（第三个变量），实现两个数的交换。

```c
#include <stdio.h>
int main()
{
	//方法1
	int a = 10;
	int b = 20;
	printf("a=%d,b=%d\n", a, b);
	//1.
	a = a + b;
	b = a - b;//(a+b)-b = a
	a = a - b;//(a+b)-a = b
	printf("a=%d,b=%d\n", a, b);//存在溢出风险

	//方法2
	int a = 10;
	int b = 20;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a = %d b = %d\n", a, b);//可读性差，只适用于整数
	return 0;
}
```

**补充**
 + <kbd> a ^ a = 0</kbd>
 + <kbd>  a ^ 0 = a</kbd>

<br />

# 赋值操作符
赋值操作符是一个很棒的操作符，他可以让你得到一个你之前不满意的值。也就是你可以给自己重新赋值。

```c
    int a = 10;
    int x = 0;
    int y = 20;
    a = x = y+1;
```

> 上面代码表示的是：y+1把计算结果赋值给x，x再把值赋给a。

 那同样的语义，你看看：

```c
    x = y+1;
    a = x;
```

> 这样的写法更加清晰爽朗而且易于调试。

<br>

## 复合赋值符

> <kbd> +=</kbd> <kbd> -=</kbd> <kbd> *=</kbd> <kbd> /=</kbd> <kbd> %=</kbd> <kbd> >>=</kbd> <kbd> <<=</kbd> <kbd> &=</kbd> <kbd> \^=</kbd> 

这些运算符都可以写成复合的效果。 比如：

```c
int x = 10;
x = x + 10;
x += 10;//复合赋值
```
**其他运算符一样的道理。这样写更加简洁。**

<br/>

# 单目操作符

> <kbd> ! </kbd> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;逻辑反操作
><kbd>\- </kbd> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  负值
><kbd>\+</kbd> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;正值
><kbd>&</kbd> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;取地址
><kbd>sizeof </kbd>     &nbsp;&nbsp;&nbsp;&nbsp;操作数的类型长度（以字节为单位）
<kbd>~ </kbd>          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;对一个数的二进制按位取反
<kbd>- -</kbd>     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;前置、后置- -
<kbd>++</kbd>          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;前置、后置++
<kbd>\* </kbd>      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;     间接访问操作符(解引用操作符)
<kbd>(类型) </kbd>     &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 强制类型转换

<br>

## 逻辑反操作符
<kbd> ! </kbd> 表示如果不为真，表达式就为真。

例子：
```c
#include <stdio.h>
int main()
{
	int x = 0;
	if (!x)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/b201a0b4a81240459ae3f542f8718c1d.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)

## sizeof和数组

```c
#include <stdio.h>
void test1(int arr[])
{
	printf("%d\n", sizeof(arr));//(2)
}
void test2(char ch[])
{
	printf("%d\n", sizeof(ch));//(4)
}
int main()
{
	int arr[10] = { 0 };
	char ch[10] = { 0 };
	printf("%d\n", sizeof(arr));//(1)
	printf("%d\n", sizeof(ch));//(3)
	test1(arr);
	test2(ch);
	return 0;
}
```
问：
（1）、（2）两个地方分别输出多少？
（3）、（4）两个地方分别输出多少？

答案是： 40  4  10  4

> <kbd>sizeof(数组名) </kbd> 计算的是数组的大小，但是通过函数传递数组名，会降级为**首元素地址**传进函数，本质是一个指针，所以在32位机器下，指针大小为4。

<br>

## 自增和自减运算符
++和- -运算符分为前置++、前置- -和后置++、后置- -。

+ <font color=red size=3>前置++：先++，后使用</font> 
+ <font color=red size=3>后置++：先使用，后++</font> 
+  <font color=red size=3>自减操作符亦然
```c
#include <stdio.h>
int main()
{
	int a = 10;
	int x = ++a;
	int y = --a;
	return 0;
}
```
先对a进行自增，然后对使用a，也就是表达式的值是a自增之后的值。x为11。
先对a进行自减，然后对使用a，也就是表达式的值是a自减之后的值。y为10;
<br>

# 关系操作符

> <kbd> ></kbd> <kbd>>=</kbd> <kbd><=</kbd> <kbd><=</kbd> 
> <kbd>!=</kbd> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;用于测试“不相等”
> <kbd>==</kbd> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;用于测试“相等”

这些关系运算符比较简单，但是我们要注意一些运算符使用时候的陷阱。
**要注意在编程的过程中== 和=不小心写错导致的错误。**

<br/>

# 逻辑操作符

> <kbd>&&</kbd>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;逻辑与
> <kbd>||</kbd>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;逻辑或

区分**逻辑与**和**按位与** 区分**逻辑或**和**按位或**

> 1 & 2----> 0
1 && 2----> 1
1 | 2-----> 3
1 || 2----> 1

逻辑与<kbd>&&</kbd>两边条件都为真，整个条件才为真，逻辑或<kbd>||</kbd>两边条件有一个是真，则整个条件就为真。

例题：

```c
#include <stdio.h>
int main()
{
    int i = 0,a=0,b=2,c =3,d=4;
    i = a++ && ++b && d++;
    printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);
    return 0;
}
```
程序输出的结果是什么？

答案是：1 2 3 4

> a++先使用后自增，故第一个表达式值为0，由于是&&操作符，第一个表达式值为0，后面的表达式就不会再计算，所以b、c和d的值都不会改变。
> 
<br>

## 短路运算
+ 逻辑运算符 &&(短路与) 特点:只要碰到了false或者等价于false的就短路,只要短路了就不会继续往后执行了。如果短路了,得到造成短路的这个值。
+ 逻辑运算符 || (短路或) 特点:只要碰到了true或者等价于true的就短路,只要短路了就不会继续往后执行了。如果短路了,得到造成短路的这个值。
 
<br>

# 条件操作符

> <kbd>exp1 ?exp2 : exp3</kbd>

练习：

1.转换成条件表达式，是什么样？

```c
if (a > 5)
        b = 3;
else
        b = -3;
```

> 答案：a > 5 ? b = 3 : b = -3;

2.使用条件表达式实现找两个数中较大值。

> 答案：max = x > y ? x : y;

<br>

# 逗号表达式

> <kbd> exp1, exp2, exp3, …expN </kbd>

逗号表达式，就是用逗号隔开的多个表达式。 逗号表达式，从左向右依次执行。整个表达式的结果是<font color=orange size=3>最后一个表达式</font>的结果。

```c
//代码1
int a = 1;
int b = 2;
int c = (a>b, a=b+10, a, b=a+1);//逗号表达式
```
Q ：c是多少？
从左到右依次计算 ，得到c的值为14。
<br>
# 下标引用、函数调用和结构成员
## 1.[ ] 下标引用操作符
操作数：一个数组名 + 一个索引值

```c
#include <stdio.h>
int main()
{
	int i = 0;
	int arr[10];
	for (i = 0; i < 10; i++)
	{
		printf("%p------%p\n", &arr[i], (arr + i));
	}

	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/56a9b258089f4f00845eb370c62a4800.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
**arr [ i ] = \*(arr + i) = \*(i + arr) = i [ arr ]**

```c
#include <stdio.h>
int main()
{
	int i = 0;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", i[arr]);
	}

	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/cadeebaa8f4441a3bf673af59f8c79ea.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
 ## 2.( ) 函数调用操作符 
 **接受一个或者多个操作数：第一个操作数是函数名，剩余的操作数就是传递给函数的参数。**
 

```c
#include <stdio.h>
void test1()
{
	printf("hello\n");
}
void test2(const char* str)
{
	printf("%s\n", str);
}
int main()
{
	test1();            //使用（）作为函数调用操作符。
	test2("hello world.");//使用（）作为函数调用操作符。
	return 0;
}
```
## 3.访问一个结构的成员

> <kbd>.</kbd>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;结构体.成员名
> <kbd>-></kbd>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;结构体指针->成员名

```c
#include <stdio.h>
struct Stu
{
	char name[10];
	int age;
	char sex[5];
	double score;
}；
void set_age1(struct Stu stu)
{
	stu.age = 18;
}
void set_age2(struct Stu* pStu)
{
	pStu->age = 18;//结构成员访问
}
int main()
{
	struct Stu stu;
	struct Stu* pStu = &stu;//结构成员访问

	stu.age = 20;//结构成员访问
	set_age1(stu);

	pStu->age = 20;//结构成员访问
	set_age2(pStu);
	return 0;
}
```

