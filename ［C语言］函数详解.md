![在这里插入图片描述](https://img-blog.csdnimg.cn/8aa66bfc800c4d368e00107c38aac6f3.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70#pic_center)
@[TOC]

## 函数是什么？
数学中我们常见到函数的概念。但是你了解C语言中的函数吗？ 维基百科中对函数的定义：子程序。

> 在计算机科学中，子程序（英语：Subroutine, procedure, function, routine, method,subprogram, callable unit），是一个大型程序中的某部分代码， 由一个或多个语句块组成。它负责完成某项特定任务，而且相较于其他代 码，具备相对的独立性。
> 一般会有输入参数并有返回值，提供对过程的封装和细节的隐藏。这些代码通常被集成为软件库。

**C语言函数的分类**：
 - 库函数
 - 自定义函数

## 库函数

为什么会有库函数？
1. 我们知道在我们学习C语言编程的时候，总是在一个代码编写完成之后迫不及待的想知道结果，想把这个结果打印到我们的屏幕上看看。这个时候我们会频繁的使用一个功能：将信息按照一定的格
式打印到屏幕上（printf）。
2. 在编程的过程中我们会频繁的做一些字符串的拷贝工作（strcpy）。
3. 在编程是我们也计算，总是会计算n的k次方这样的运算（pow）。

像上面我们描述的基础功能，它们不是业务性的代码。我们在开发的过程中每个程序员都可能用的到，
为了支持可移植性和提高程序的效率，所以C语言的基础库中提供了一系列类似的库函数，方便程序员
进行软件开发。

库函数学习：[cplusplus.com](http://www.cplusplus.com/)
![在这里插入图片描述](https://img-blog.csdnimg.cn/12f297a2d1bc483cb40b39e3c90c76ce.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)


简单的总结，C语言常用的库函数都有：

 - IO函数
 - 字符串操作函数
 - 字符操作函数
 - 内存操作函数
 - 时间/日期函数
 - 数学函数
 - 其他库函数


我们参照文档，学习几个库函数：

[strcpy](http://www.cplusplus.com/reference/cstring/strcpy/?kw=strcpy)
> char * strcpy ( char * destination, const char * source );

```c
#include <stdio.h>
#include <string.h>

int main()
{
	char arr1[20] = "xxxxxxxxx";//目标空间
	char arr2[] = "hello";

	char* ret = strcpy(arr1, arr2);

	printf("%s\n", arr1);
	printf("%s\n", ret);

	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/8f7f6ba846444f06b8c6706c5edc02b4.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
在使用这个函数的时候，我们需要向函数参数传入arr1和arr2两个字符串，同时该函数的返回值是char* ，它会将拷贝后的arr1起始地址返回给我们，可以选择使用一个字符指针还接受它也可以直接使用。



[memset](http://www.cplusplus.com/reference/cstring/memset/?kw=memset)

> void * memset ( void * ptr, int value, size_t num );

```c
#include <stdio.h>
#include <string.h>

int main()
{
	char arr[] = "hello world";//xxxxx world
	int n = 5;
	char* ret = (char* )memset(arr, 'x', n);
	printf("%s\n", ret);

	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/f64a536964b74561886f450299ed167e.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
memset是将ptr指向的内存块的前num个字节设置为指定值

## 自定义函数
如果库函数能干所有的事情，那还要程序员干什么？
所有更加重要的是**自定义函数**。
自定义函数和库函数一样，有函数名，返回值类型和函数参数。 但是不一样的是这些都是我们自己来设计。这给程序员一个很大的发挥空间。
**函数的组成**：

> ret_type fun_name(para1,...)
{
       statment;//语句项
}
ret_type//返回类型
fun_name//函数名
para//参数

下面举个例子：
**写一个函数可以找出两个整数中的最大值。**

```c
#include <stdio.h>
//get_max函数的设计
int get_max(int x, int y)
{
	return (x > y) ? (x) : (y);
}
int main()
{
	int num1 = 10;
	int num2 = 20;
	int max = get_max(num1, num2);
	printf("max = %d\n", max);
	return 0;
}
```
**写一个函数可以交换两个整形变量的内容。**

```c
void Swap1(int x, int y) {
	int t = 0;
	t = x;
	x = y;
	y = t;
}
void Swap2(int* px, int* py){
	int t = 0;
	t = *px;
	*px = *py;
	*py = t;
}
int main(){
	int a = 10;
	int b = 20;
    Swap1(a,b);
	printf("Swap1：a=%d,b=%d\n", a, b);
	Swap2(&a, &b);
	printf("Swap2：a=%d,b=%d\n", a, b);
	return 0;
}
```
**函数的参数**：
实际参数（实参）：

> 真实传给函数的参数，叫实参。实参可以是：常量、变量、表达式、函数等。无论实参是何种类型的量，在进行函数调用时，它们都必须有确定的值，以便把这些值传送给形参。

形式参数（形参）：

> 形式参数是指函数名后括号中的变量，因为形式参数只有在函数被调用的过程中才实例化（分配内存单元），所以叫形式参数。形式参数当函数调用完成之后就自动销毁了。因此形式参数只在函数中有效。

上面Swap1和Swap2函数中的参数 x，y，px，py 都是形式参数。在main函数中传给Swap1的num1，
num2和传给Swap2函数的&num1，&num2是实际参数。
![在这里插入图片描述](https://img-blog.csdnimg.cn/dca0de7242e641b2bf0e100038571cbe.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)

可以看到，Swap1函数是不能交换两个值的，因为Swap1函数调用的时候，x、y拥有自己的空间，有了和实际参数一模一样的值，是**相当于对实参的一份临时拷贝**，在Swap1函数中改变值并不会影响实参的值。而Swap2函数将参数的地址传入函数，这种传参方式可以让函数和函数外边的变量建立起真正的联系，在函数中使用地址改变形参的值就可以改变实参的值。

## 函数的调用
**传值调用**

> 函数的形参和实参分别占有不同内存块，对形参的修改不会影响实参。

**传址调用**

> 传址调用是把函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式。
这种传参方式可以让函数和函数外边的变量建立起正真的联系，也就是函数内部可以直接操作函数外部的变量。

**练习**
1. 写一个函数可以判断100到200有几个素数。

```c
#include <stdio.h>
#include <math.h>
int isPrime (int x)
{
	if (x == 1 || x == 2) return 1;
	int i = 0;
	for (i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
			return 0;
	} 

	return 1;
}

int main()
{
	int count = 0;
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		if (isPrime(i))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d", count);
	return 0;
}
```
2. 写一个函数判断一年是不是闰年。

```c
#include <stdio.h>

int is_leap_year(int x)
{
	if ((x % 400 == 0) || ((x % 4 == 0) && (x % 100 != 0)))
		return 1;
	else
		return 0;
}

int main()
{
	int y;
	for (y = 1000; y <= 2000; y++)
	{
		if (is_leap_year(y))
		{
			printf("%d ", y);
		}
	}
	return 0;
}
```
3. 写一个函数，实现一个整形有序数组的二分查找。

```c
int binary_search(int arr[], int x, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] > x)
		{
			right = mid - 1;
		}
		else if (arr[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

#include <stdio.h>
int main()
{
	int k = 7;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = binary_search(arr, k, sz);
	if (ret= -1)
	{
		printf("找到了，下标是%d\n", ret);
	}
	else
	{
		printf("找不到\n");
	}
}
```

## 函数的嵌套调用和链式访问

> 函数和函数之间是可以有机的组合的。

**嵌套调用**

```c
#include <stdio.h>

void new_line()
{
	printf("hello\n");
}
void three_line()
{
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        new_line();
    }
}
int main()
{
    three_line();
    return 0;
}
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/637f8b3c54af4860bd72e23b689511e9.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
以上代码在main函数中调用three_line函数，在three_line函数中又调用了new_line函数，这就是函数的嵌套调用。

**链式访问**

> 把一个函数的返回值作为另外一个函数的参数。

```c
#include <stdio.h>
#include <string.h>
int main()
{
    char arr[20] = "hello";
    int ret = strlen(strcat(arr,"world"));
    printf("%d\n", ret);
    return 0;
}
```
这个代码用strcat函数的返回值作为strlen函数的参数，这就是函数的链式访问。

**例子**

```c
#include <stdio.h>
int main()
{
    printf("%d", printf("%d", printf("%d", 43)));
    return 0;
}
```
上面代码的运行结果是什么呢？
![在这里插入图片描述](https://img-blog.csdnimg.cn/6b73cbfc2aac41f0b9c43fce38ba73ba.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
答案是4321。因为printf函数的返回值是返回所打印的元素个数，最内层的printf打印43，返回值是2，次内层printf打印2，返回值是1，最后最外层打印1，结果就为4321。

## 函数的声明和定义
**函数声明**

> 1. 告诉编译器有一个函数叫什么，参数是什么，返回类型是什么。但是具体是不是存在，无关紧要。
> 2. 函数的声明一般出现在函数的使用之前。要满足**先声明后使用**。
> 3. 函数的声明一般要放在头文件中的。

**函数定义**

> 函数的定义是指函数的具体实现，交待函数的功能实现。



## 函数递归
**什么是递归？**

> 程序调用自身的编程技巧称为递归（ recursion）。 递归做为一种算法在程序设计语言中广泛应用。 一个过程或函数在其定义或说明中有直接或间接调用自身的一种方法，它通常把一个大型复杂的问题层层转化为一个与原问题相似的规模较小的问题来求解，递归策略只需少量的程序就可描述出解题过程所需要的多次重复计算，大大地减少了程序的代码量。 **递归的主要思考方式在于：把大事化小。**

**递归的两个必要条件**

 - 存在限制条件，当满足这个限制条件的时候，递归便不再继续。 
 - 每次递归调用之后越来越接近这个限制条件。

练习1：

接收一个整型值（无符号），按照顺序打印它的每一位。 例如： 输入：1234，输出 1 2 3 4.

```c
#include <stdio.h>
void print(int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}
int main()
{
	int num = 1234;
	print(num);
	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/7abb1cf23b9c4fa5b93cb661abfc0bad.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
画图分析：
![在这里插入图片描述](https://img-blog.csdnimg.cn/26936692aadb4c3f94aa5f44dc610c59.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
如果没有if (n > 9)这个限制条件会怎么样？
![在这里插入图片描述](https://img-blog.csdnimg.cn/0943aa4ffb1a4b448324d816773b2e7c.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
如果没有if (n > 9)这个限制条件，编译器就会报错，因为函数中内存的开辟是在栈区的，如果没有限制条件，就会无限递归下去，就会无限为print函数开辟空间，栈的空间是有限的，最终导致栈满，程序崩溃。
![在这里插入图片描述](https://img-blog.csdnimg.cn/9d26443eea9b4779a3f6ac414ad05128.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
练习2：

编写函数不允许创建临时变量，求字符串的长度。

```c
#include <stdio.h>
int Strlen(const char* str)
{
	if (*str == '\0')
		return 0;
	else return 1 + Strlen(str + 1);
}
int main()
{
	char* p = "abcdef";
	int len = Strlen(p);
	printf("%d\n", len);
	return 0;
}

```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/f699e69bfb7740538c3349adf8240586.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
画图讲解：
![在这里插入图片描述](https://img-blog.csdnimg.cn/b1b57efb2afe47f8a31ace453724b056.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
**递归与迭代**

练习3：
求n的阶乘。（不考虑溢出）

```c
int factorial(int n)
{
    if(n <= 1)
    return 1;
    else
    return n* factorial(n-1);
}
```
但是当我们运行时会发现有问题：

 - 在使用 fib 这个函数的时候如果我们要计算第50个斐波那契数字的时候特别耗费时间。
 -  使用 factorial函数求10000的阶乘（不考虑结果的正确性），程序会崩溃。

**那我们如何改进呢？**
在调试 factorial 函数的时候，如果你的参数比较大，那就会报错： `stack overflow（栈溢出） 这样的信息。 系统分配给程序的栈空间是有限的，但是如果出现了死循环，或者（死递归），这样有可能导致一直开辟栈空间，最终产生栈空间耗尽的情况，这样的现象我们称为栈溢出。

**那如何解决上述的问题：**
1. 将递归改写成非递归。
2. 使用static对象替代nonstatic局部对象。在递归函数设计中，可以使用static对象替代nonstatic局部对象（即栈对 象），这不仅可以减少每次递归调用和返回时产生和释放nonstatic对象的开销，而且static对象还可以保存递归调用的中间状态，并且可为各个调用层所访问。

下面用非递归来实现阶乘：


```c
int factorial(int n)
{
        int result = 1;
        while (n > 1)
       {
             result *= n ;
             n -= 1;
       }
        return result;
}
```

**提示：**
1. 许多问题是以递归的形式进行解释的，这只是因为它比非递归的形式更为清晰。
2. 但是这些问题的迭代实现往往比递归实现效率更高，虽然代码的可读性稍微差些。
3. 当一个问题相当复杂，难以用迭代实现时，此时递归实现的简洁性便可以补偿它所带来的运行时开销。
