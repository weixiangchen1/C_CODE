
@[TOC]
# 指针是什么？

> 在计算机科学中，指针（Pointer）是编程语言中的一个对象，利用地址，它的值直接指向points to）存在电脑存储器中另一个地方的值。由于通过地址能找到所需的变量单元，可以说，<font color=red size=3>地址指向该变量单元</font> 。因此，将地址形象化的称为“指针”。意思是通过它能找到以它为地址的内存单元。
> 
![在这里插入图片描述](https://img-blog.csdnimg.cn/46513048cbb640a59800768094e96ff3.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)



代码应用：
```cpp
#include <stdio.h>
int main()
{
	int a = 10;   在内存中开辟一块空间
	int* p = &a;  这里我们对变量a，取出它的地址，可以使用&操作符。
	  将a的地址存放在p变量中，p就是一个之指针变量。
	return 0;
}
```
**总结：<font color=red size=3>指针就是变量，用来存放地址的变量。</font> （存放在指针中的值都被当成地址处理）。**

<br>

## 一个小的内存单元到底是多大?
对于32位的机器，假设有32根地址线，那么每根地址线在寻址的是产生一个电信号正电/负电（1或者0）。

那么32根地址线产生的地址就会是：
![在这里插入图片描述](https://img-blog.csdnimg.cn/3d958afca2fa4650bf819d507788fab1.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
经过仔细的计算和权衡我们发现<font color=red size=3>一个字节</font>给一个对应的地址是比较合适的。

**如何编址？**

+ 每个地址标识一个字节，那我们就可以给(2^32Byte == 2^32/1024KB == 2^32/1024/1024MB == 2^32/1024/1024/1024GB == 4G)4G的空闲进行编址。

**注意**：
+ 在32位的机器上，地址是32个0或者1组成二进制序列，那地址就得用4个字节的空间来存储，所以一个指针变量的大小就应该是4个字节。
+ 那如果在64位机器上，如果有64个地址线，那一个指针变量的大小是8个字节，才能存放一个地址。

**总结**：
+ 指针是用来存放地址的，地址是唯一标示一块地址空间的。
+ 指针的大小在**32位平台是4个字节**，在**64位平台是8个字节**。

<br>

# 指针和指针类型
我们都知道，变量有不同的类型，整形，浮点型等。那指针有没有类
型呢？ 准确的说：有的。

当有这样的代码：

```c
int num = 10;
p = &num;
```
要将&num（num的地址）保存到p中，我们知道p就是一个指针变量，那它的类型是怎样的呢？ 我们给指针变量相应的类型。

```c
char  *pc = NULL;
int   *pi = NULL;
short *ps = NULL;
long  *pl = NULL;
float *pf = NULL;
double *pd = NULL;
```
这里可以看到，指针的定义方式是：<kbd>  type + * </kbd> 。 其实： <kbd>  char* </kbd>类型的指针是为了存放 char 类型变量的地址。<kbd>   short* </kbd> 类型的指针是为了存放 short 类型变量的地址。<kbd>  int*  </kbd> 类型的指针是为了存放int 类型变量的地址。

<br>

## 指针类型的意义
**指针+\-整数**

```c
#include <stdio.h>
int main()
{
	int n = 10;
	char* pc = (char*)&n;
	int* pi = &n;

	printf("%p\n", &n);
	printf("%p\n", pc);
	printf("%p\n", pc + 1);
	printf("%p\n", pi);
	printf("%p\n", pi + 1);
	return  0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/7e2324ee50c345bc9494d27699d97fed.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
### 意义1
+ **指针的类型决定了指针向前或者向后走一步有多大（距离）。**

**指针的解引用**

```c
#include <stdio.h>
int main()
{
	int n = 0x11223344;
	char* pc = (char*)&n;
	int* pi = &n;
	*pc = 0;  
	*pi = 0;  
	return 0;
}
```
调试结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/6bee818a0ee2402eba52e5c047a9785b.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/71d1c5179d10463d9c546f6976d3893f.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)

> 在通过指针对内存进行操作时，指针的类型决定了操作的字节多少。
> char* pc操作一个字节，将十六进制的11改为00
> int* pi操作四个字节，将0x11223344改为0x00000000

### 意义2
+  **指针的类型决定了对指针解引用的时候有多大的权限**（**能操作几个字节**）。 **比如**：<kbd>  char*</kbd>**的指针解引用就只能访问一个字节**，**而**<kbd> int* </kbd>  **的指针的解引用就能访问四个字节**。

<br>

# 野指针

> 概念： 野指针就是指针指向的位置是不可知的（随机的、不正确的、没有明确限制的）

## 野指针成因
+  **指针未初始化**

```c
#include <stdio.h>
int main()
{
    int* p;//局部变量指针未初始化，默认为随机值
    *p = 20;
    return 0;
}
```
+ **指针越界访问**

```c
#include <stdio.h>
int main()
{
    int arr[10] = { 0 };
    int* p = arr;
    int i = 0;
    for (i = 0; i <= 11; i++)
    {
        //当指针指向的范围超出数组arr的范围时，p就是野指针
        *(p++) = i;
    }
    return 0;
}
```

+ **指针指向的空间未释放**

<br>

## 如何规避野指针

 1. **指针初始化**
2. **小心指针越界**
3. **指针指向空间释放即使置NULL**
4. **指针使用之前检查有效性**

例如：

```c
#include <stdio.h>
int main()
{
    int* p = NULL;
    //....
    int a = 10;
    p = &a;
    if (p != NULL)
    {
        *p = 20;
    }
    return 0;
}
```
<br>

# 指针运算
+ 指针+\-整数
+ 指针-指针
+ 指针运算关系

## 指针+ -整数

```c
#define N_VALUES 5
float values[N_VALUES];
float *vp;
//指针+-整数；指针的关系运算
for (vp = &values[0]; vp < &values[N_VALUES];)
{
     *vp++ = 0;
}
```
## 指针-指针

**例子**：
```c
#include <stdio.h>
int main()
{
	int arr[10] = { 0 };
	printf("%d\n", &arr[9] - &arr[0]);
	printf("%d\n", &arr[0] - &arr[9]);
	return 0;
}
```
**模拟实现strlen函数**

```c
int my_strlen(char* s)
{
	char* arr = s;
	while (*s != '\0')
	{
		s++;
	}
	return s - arr;
}

int my_strlen(char* s)
{
	int count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return count;
}

int my_strlen(char* s)
{
	if (*s != '\0')
	{
		return 1 + my_strlen(s + 1);
	}
	else
	{
		return 0;
	}
}

int main()
{
	char arr[10] = "abcdf";
	int ret = my_strlen(arr);
	printf("%d\n", ret);
}
```

**总结**：
+ 指针-指针的前提是两个指针**指向同一块区域**
+ 指针-指针 得到的数字的绝对值是**指针和指针之间元素的个数**
<br>
## 指针的关系运算

```c
for (vp = &values[N_VALUES]; vp > &values[0];)
{
    *--vp = 0;
}
```
代码简化, 这将代码修改如下：

```c
for(vp = &values[N_VALUES-1]; vp >= &values[0];vp--)
{
    *vp = 0;
}
```
实际在绝大部分的编译器上是可以顺利完成任务的，然而我们还是应该避免这样写，因为标准并不保证它可行。
两个代码的功能都是对value数组进行初始化赋值。

**标准规定：**
+ 允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较，但是不允许与指向第一个元素之前的那个内存位置的指针进行比较。

![在这里插入图片描述](https://img-blog.csdnimg.cn/1fcca912630d4e36944ef3be90b745b2.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)

# 指针和数组

数组名是什么？我们看一个例子：

```c
#include <stdio.h>
int main()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
    printf("%p\n", arr);
    printf("%p\n", &arr[0]);
    return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/265b9f33c681427d85ee6a158e1ac259.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
**可见数组名和数组首元素的地址是一样的。**

结论：<font color=red size=3>**数组名表示的是数组首元素的地址**。</font> 

那么这样写代码是可行的：

```c
int arr[10] = {1,2,3,4,5,6,7,8,9,0};
int* p = arr;//p存放的是数组首元素的地址
```
既然可以把数组名当成地址存放到一个指针中，我们使用指针来访问一个就成为可能。

例如：

```c
#include <stdio.h>
int main()
{
    int i = 0;
    int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
    int* p = arr; //指针存放数组首元素的地址
    int sz = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < sz; i++)
    {
        printf("&arr[%d] = %p   <====> p+%d = %p\n", i, &arr[i], i, p + i);
    }
    return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/77f5cfaadff7468988688ddbc5ee69ae.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
数组名是首元素的地址。

但是有2个例外：
+ **sizeof(数组名)  - 这里的数组名不是首元素的地址，是表示整个数组的，这里计算的是整个数组的大小，单位还是字节**。
+ **&数组名 - 这里的数组名不是首元素的地址，是表示整个数组的，拿到的是整个数组的地址**。

例子：

```c
#include <stdio.h>
int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);
	printf("%p\n", arr + 1);
	printf("%p\n", &arr[0]);
	printf("%p\n", &arr[0] + 1);
	printf("%p\n", &arr);
	printf("%p\n", &arr + 1);

	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/8d7b6bd8b4d541f9a2be3d413be6e81a.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)

+ **arr表示首元素地址**
+ **&arr[0]也表示首元素地址**
+ **&arr则表示整个数组的地址**

# 二级指针
指针变量也是变量，是变量就有地址，那指针变量的地址存放在哪里？

```c
#include <stdio.h>
int main()
{
	int a = 10;
	int* pa = a;//一级指针
	int** ppa = pa;//二级指针

	return 0;
}
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/54aed0bd61eb4ee9bdd39df07a55b070.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
对于二级指针的运算有：

+ <kbd>*ppa</kbd>通过对ppa中的地址进行解引用，这样找到的是 <kbd>pa</kbd>， <kbd>*ppa</kbd>其实访问的就是<kbd>pa</kbd> .

> **int b = 20;
\*ppa = &b;//等价于 pa = &b;**

+ <kbd>**ppa</kbd>先通过 <kbd>**ppa</kbd> 找到 <kbd>pa</kbd> ,然后对 <kbd>pa</kbd> 进行解引用操作： <kbd>*pa</kbd> ，那找到的是 <kbd>a</kbd>.

> **\*\*ppa = 30;
//等价于*pa = 30;
//等价于a = 30;**

<br>

# 指针数组
指针数组是指针还是数组？

答案：**是数组。是存放指针的数组。**

数组我们已经知道整形数组，字符数组.

```c
int arr1[5];
char arr2[5];
int* arr3[5];
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/f5852a21428e4a0e85e79b09be7f5f32.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)

