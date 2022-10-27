@[TOC]
# 动态内存分配的意义
我们惯用的内存开辟方式有：
```
int val = 10；
char str[] = "hello world";
```
但是上述的开辟空间的方式有两个特点：
1. **空间开辟大小是固定的。**
2. **数组在申明的时候，必须指定数组的长度，它所需要的内存在编译时分配。**

但是对于空间的需求，不仅仅是上述的情况。有时候我们需要的空间大小在程序运行的时候才能知道，那数组的编译时开辟空间的方式就不能满足了。 这时候就只能试试动态存开辟了。

<br>

# 动态内存函数的介绍
## malloc和free
C语言提供了一个动态内存开辟函数：
```
void* malloc( size_t size );
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/aaaaecfad6164d358d16e8d5f3b04d83.png)
这个函数向内存申请一块空间为 size 字节的**连续可用**的空间，并返回指向这块空间的void*类型的指针，使用该指针时应强制转换为对应类型。

 - **如果开辟成功，则返回一个指向开辟好空间的指针。**
- **如果开辟失败，则返回一个NULL指针，因此<font color=red size=3>malloc的返回值一定要做检查</font>**。
-  **返回值的类型是 void\* ，所以malloc函数并不知道开辟空间的类型，具体在使用的时候使用者自己来决定**。
- **如果参数 size 为0，malloc的行为是标准是未定义的，取决于编译器**。

C语言提供了另外一个函数free，专门是用来做动态内存的释放和回收的，函数原型如下：
```
void free (void* ptr);
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/00a6a102c2d64e37be7f4d65ab5b3d07.png)
free函数用来释放动态开辟的内存。

- **如果参数 ptr 指向的空间不是动态开辟的，那free函数的行为是未定义的**。
- **如果参数 ptr 是NULL指针，则函数什么事都不做**。

**注意**：

- malloc函数申请的内存空间是在**堆区**上开辟的。
- malloc函数是搭配free函数来使用的，使用malloc函数申请的空间需要使用free函数来释放并置为NULL指针，避免**内存泄漏**和**野指针**问题。

## calloc
C语言还提供了一个函数叫 calloc ， calloc 函数也用来动态内存分配。原型如下：
```
void* calloc (size_t num, size_t size);
```
- **函数的功能是为 num 个大小为 size 的元素开辟一块空间，并且把空间的每个字节初始化为0。**

calloc函数与malloc函数的区别是calloc会把**申请的内存空间初始化为0**，所以如果我们对申请的内存空间的内容要求初始化，那么可以很方便的使用calloc函数来完成任务。
![在这里插入图片描述](https://img-blog.csdnimg.cn/4c64fdd1b7eb410da629bb696d09e3a6.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)
## realloc
有时申请的空间会或大或小，为了合理管理内存，我们会对内存大小进行合理的管理，realloc函数是用来对所申请的动态内存进行容量调整。

函数原型：
```
void* realloc (void* ptr, size_t size);
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/bfb4abe0c9a642e496188cdad47af1a3.png)

- **返回值为调整之后的内存起始位置。**
- **ptr 是要调整的内存地址，size 调整之后新大小**。
- **函数调整原内存空间大小的基础上，会将原来内存中的数据移动到 新 的空间。**

**realloc在调整内存空间的是存在两种情况**：
![在这里插入图片描述](https://img-blog.csdnimg.cn/a9f817daceff45f2a3c0f14346001762.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)
当是**情况1** 的时候，要扩展内存就直接原有内存之后直接追加空间，原来空间的数据不发生变化。 当是**情况2** 的时候，原有空间之后没有足够多的空间时，扩展的方法是：在堆空间上另找一个合适大小的连续空间来使用。这样函数**返回的是一个新的内存地址**。 由于上述的两种情况，realloc函数的使用就要注意一些。

<br>

# 常见的动态内存错误

 - **对NULL指针的解引用操作**

```cpp
void test()
{
	int* p = (int*)malloc(INT_MAX / 4);
	*p = 20;
	free(p);
}
```

> **如果p申请空间失败，返回NULL指针，对NULL指针进行解引用就会有问题**。

- **对动态开辟空间的越界访问**

```cpp
void test()
{
	int i = 0;
	int* p = (int*)malloc(10 * sizeof(int));
	if (NULL == p)
	{
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= 10; i++)
	{
		*(p + i) = i;
	}
	free(p);
}
```

> **当i是10的时候越界访问，程序就会有问题**

- **对非动态开辟内存使用free释放**

```cpp
void test()
{
	int a = 10;
	int* p = &a;
	free(p);
}
```

> **对于非动态开辟的局部变量，有相应的生命周期，函数结束后会自动销毁，free函数只能用于释放malloc、calloc和realloc动态申请的内存空间**。

- **使用free释放一块动态开辟内存的一部分**

```cpp
void test()
{
	int* p = (int*)malloc(100);
	p++;
	free(p);
}
```

> **free函数传入的参数必须是所申请动态内存的起始地址，此时的p不再指向动态内存的起始位置，所以程序有问题**。

- **对同一块动态内存多次释放**

```c
void test()
{
	int* p = (int*)malloc(100);
	free(p);
	free(p);
}
```

> **对同一块动态内存只能释放一次，重复释放会造成非法访问**。

- **动态开辟内存忘记释放（内存泄漏）**

```c
void test()
{
	int* p = (int*)malloc(100);
	if (NULL != p)
	{
		*p = 20;
	}
}
int main()
{
	test();
	while (1);
}
```

> **动态申请的空间未释放，如果程序一直运行，该程序就会一直占用那一块内存，会造成内存泄露问题**。

**切记： 动态开辟的空间一定要释放，并且正确释放** 。

# 经典的笔试题
## 题目1

```c
void GetMemory(char* p)
{
	p = (char*)malloc(100);
}
void Test(void)
{
	char* str = NULL;
	GetMemory(str);
	strcpy(str, "hello world");
	printf(str);
}
```

> **1.GetMemory函数为传值调用，函数中形参p改变不影响str，函数结束后str仍为NULL指针对str进行strcpy函数调用会导致程序崩溃。
> 2.GetMemory函数中p动态申请内存后未释放，会导致内存泄露。**

## 题目2

```c
char* GetMemory(void)
{
	char p[] = "hello world";
	return p;
}

void Test(void)
{
	char* str = NULL;
	str = GetMemory();
	printf(str);
}
```

> **GetMemory函数中p数组的生命周期是在GetMemory中的，出了函数p数组就销毁了，函数调用结束后Test函数使用p的地址属于非法访问内存空间**。

## 题目3

```c
void GetMemory(char** p, int num)
{
	*p = (char*)malloc(num);
}
void Test(void)
{
	char* str = NULL;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	printf(str);
}
```

> **p申请的空间没有被释放，存在内存泄露问题**

## 题目4

```c
void Test(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
}
```

> **str申请的内存虽然被释放，但是它仍然会记住原本申请的那一块空间不为NULL，只是使用权限交还给操作系统。
str是一个野指针，对其进行strcpy操作是非法的。**

# C/C++程序的内存开辟
![在这里插入图片描述](https://img-blog.csdnimg.cn/76679508e7874fa3a8329b8b76b36fd6.png?x-oss-process=image/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBA6L-Y5bCP57uZ5Liq6Z2i5a2Q,size_20,color_FFFFFF,t_70,g_se,x_16)

C/C++程序内存分配的几个区域：

 1. **栈区**（stack）：在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束时这些存储单元自动被释放。栈内存分配运算内置于处理器的指令集中，效率很高，但是分配的内存容量有限。 栈区主要存放运行函数而分配的局部变量、函数参数、返回数据、返回地址等。
2. **堆区**（heap）：一般由程序员分配释放， 若程序员不释放，程序结束时可能由OS回收 。分配方式类似于链表。
3. **数据段（静态区）**（static）存放全局变量、静态数据。程序结束后由系统释放。
4. **代码段**：存放函数体（类成员函数和全局函数）的二进制代码。

注意：
- 实际上普通的局部变量是在栈区分配空间的，栈区的特点是在上面创建的变量出了作用域就销毁。
- 但是被static修饰的变量存放在数据段（静态区），数据段的特点是在上面创建的变量，直到程序结束才销毁所以生命周期变长。


# 柔性数组
柔性数组既数组大小待定的数组， C语言中结构体的最后一个元素可以是大小未知的数组，也就是所谓的0长度，所以我们可以用结构体来创建柔性数组。
```
typedef struct st_type
{
	int i;
	int a[0];//柔性数组成员
}type_a;
```
**柔性数组的特点：**

 - 结构中的柔性数组成员前面必须至少一个其他成员。
- sizeof 返回的这种结构大小不包括柔性数组的内存。
- 包含柔性数组成员的结构用malloc ()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小。

```c
typedef struct st_type
{
int i;
int a[0];//柔性数组成员
}type_a;
printf("%d\n", sizeof(type_a));//输出的是4
```

> **代码输出的结果是4，可以得到结论柔性数组不占用结构体的内存**。

**柔性数组的优势：**

```c
struct st_type
{
	int i;
	int a[];//柔性数组成员
};

int main()
{
	int i = 0;
	struct st_type* pc;
	printf("%d\n", sizeof(struct st_type));//4
	struct st_type* ptr = (struct st_type*)malloc(sizeof(struct st_type) + 10 * sizeof(int));
	if (ptr == NULL)
	{
		return -1;
	}
	pc = ptr;
	for (i = 0; i < 10; i++)
	{
		*(pc->a + i) = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", * (pc->a + i));
	}
	free(pc);
	pc = NULL;
	return 0;
}
```
**优势1：方便内存释放**

- 如果我们的代码是在一个给别人用的函数中，你在里面做了二次内存分配，并把整个结构体返回给用户。用户调用free可以释放结构体，但是用户并不知道这个结构体内的成员也需要free，所以你不能指望用户来发现这个事。所以，如果我们把结构体的内存以及其成员要的内存一次性分配好了，并返回给用户一个结构体指针，用户做一次free就可以把所有的内存也给释放掉。

**优势2：这样有利于访问速度**

- 连续的内存有益于提高访问速度，也有益于减少内存碎片。
