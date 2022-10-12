![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/792150690d77a6510595a615d432cea7.png)


@[TOC]
这篇文章主要介绍**分支语句**和**循环语句**的使用。
|分支语句|  循环语句|
|--|--|
|if | while ， do...while|
|switch |for|

## 什么是语句
C语言中由一个分号 ; 隔开的就是一条语句。 比如：

> printf("hello world！");
   1+2;


只有一个分号也算一个语句，我们把它叫做空语句。
## 分支语句（选择结构）
人生处处充满选择，上大学好好学习是一种选择，在大学混四年也是一种选择。

在C语言中，选择结构有两种结构：

**if语句**

```c
     语法结构：
     if(表达式)
        语句;
     if(表达式)
        语句1;
     else
        语句2;
//多分支    
     if(表达式1)
        语句1;
     else if(表达式2)
        语句2;
     else
        语句3;
```

> 值得注意的是，若if语句中的条件表达式值为0，则不执行。 条件表达式为非0，则执行。 
> 因为在C语言中，0表示假，非0表示真。

下面是i语句的几个样例：

```c
//样例1
#include <stdio.h>
int main()
{
    int age = 0;
    scanf("%d", &age);
    if(age<18)
   {
        printf("未成年\n");
   }
   return 0；
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/d63ca0f6cf4d826e2836a24e59a1c431.png#pic_center)

```c
//样例二
#include <stdio.h>
int main()
{
 int age = 0;
    scanf("%d", &age);
    if(age<18)
   {
        printf("未成年\n");
   }
    else
   {
        printf("成年\n");
   }
   return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/9411518af2da4f6ef458f58bcacb2070.png#pic_center)

```c
//样例三
#include <stdio.h>
int main()
{
 int age = 0;
    scanf("%d", &age);
    if(age<18)
   {
        printf("少年\n");
   }
    else if(age>=18 && age<30)
   {
        printf("青年\n");
   }
    else if(age>=30 && age<50)
   {
        printf("中年\n");
        }
    else if(age>=50 && age<80)
   {
        printf("老年\n");
   }
    else
   {
        printf("寿星\n");
   }
    return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/971f33a435c63532c7e92ceb9874a44b.png#pic_center)
如果条件成立，要执行多条语句，就应该使用**代码块**。

```c
#include <stdio.h>
int main()
{
    if(表达式)
   {
        语句列表1；
   }
    else
   {
        语句列表2；
   }
    return 0;
}
```
这里的一对 { } 就是一个代码块。

**悬空else**
当你写了这个代码：

```c
#include <stdio.h>
int main()
{
    int a = 0;
    int b = 2;
    if(a == 1)
        if(b == 2)
            printf("hehe\n");
    else
        printf("haha\n");
    return 0;
}
```
下面的else只会和离它最近的if匹配，这样就失去了原本所要实行的效果。
改正方法：
适当的使用{}可以使代码的逻辑更加清楚。
```c
#include <stdio.h>
int main()
{
    int a = 0;
    int b = 2;
    if(a == 1)
   {
        if(b == 2)
       {
            printf("hehe\n");
       }
   }
    else
   {
            printf("haha\n");
   }      
    return 0;
}
```
if书写形式对比：

```c
//代码1
if (condition) {
    return x;
}
return y;
//代码2
if(condition)
{
    return x;
}
else
{
    return y;
}
//代码3
int num = 1;
if(num == 5)
{
    printf("hehe\n");
}
//代码4
int num = 1;
if(5 == num)
{
    printf("hehe\n");
}
```

> 先看代码一和代码二，虽然两个代码所表达的意思是一样的，但是代码二的逻辑更加清晰，代码的可读性比较强。

> 再看代码三和代码四，很多小白（包括我，会把判断表达式写成赋值表达式，而这时候编译器是找不出来错误的，如果我们把赋值表达式写成代码四的形式，这样一来如果再写成赋值表达式，编译器就会报警，因为常量不可以被赋值。

下面是if语句的小练习：
 判断一个数是否为奇数
 

```c
#include <stdio.h>
int main()
{
     int num;
     scanf("%d", &num);
     if(num%2==1)
     {
          printf("奇数\n");
     }
     return 0;
}
```
**switch语句**
switch语句也是一种分支语句。 常常用于多分支的情况。
比如：

> 输入1，输出星期一
输入2，输出星期二
输入3，输出星期三
输入4，输出星期四
输入5，输出星期五
输入6，输出星期六
输入7，输出星期七

如果写成if else的形式，代码会很复杂，下面介绍switch语句：

> switch(整型表达式)
{
    语句项；
}

而语句项又是什么呢？

> case （整型常量表达式）：
>         语句；
switch后面的表达式必须是整型表达式，即其后变量必须为整型。

**在switch语句中的break**
在switch语句中，我们没法直接实现分支，搭配break使用才能实现真正的分支。
当break用于开关语句switch中时,可使程序跳出switch而执行switch以后的语句；如果没有break语句,则将成为一个死循环而无法退出。
```c
#include <stdio.h>
int main()
{
    int day = 0;
    scanf("%d", &day);
 
    switch (day)//整型表达式
    {
    case 1://整型常量表达式
        printf("星期一\n");
        break;
    case 2:
        printf("星期二\n");
        break;
    case 3:
        printf("星期三\n");
        break;
    case 4:
        printf("星期四\n");
        break;
    case 5:
        printf("星期五\n");
        break;
    case 6:
        printf("星期六\n");
        break;
    case 7:
        printf("星期日\n");
        break;
 
    }
 
    return 0;
}

```
有时候我们的需求变了：

 - 输入1-5输出的是“weekday”;
 - 输入6-7输出“weekend”;

代码可以这样实现：
```c
#include <stdio.h>
//switch代码演示
int main()
{
    int day = 0;
    switch(day)
   {
        case 1：
        case 2:
        case 3:
        case 4:
        case 5:
            printf("weekday\n");
            break;
        case 6:
        case 7:
            printf("weekend\n");
            break;
   }
    return 0;
}
```
**break语句**的实际效果是把语句列表划分为不同的部分。

**default子句**

> 如果表达的值与所有的case标签的值都不匹配怎么办？ 
> 其实也没什么，结构就是所有的语句都被跳过而已。
> 程序并不会终止，也不会报错，因为这种情况在C中并不认为适合错误。
>  但是，如果你并不想忽略不匹配所有标签的表达式的值时该怎么办呢？
> 你可以在语句列表中增加一条default子句，把标签 default： 
> 写在**任何一个**case标签可以出现的位置。 
> 当 switch表达式的值并不匹配所有case标签的值时，这个default子句后面的语句就会执行。
> 所以，每个switch语句中只能出现一条default子句。
> 但是**它可以出现在语句列表的任何位置**，而且语句流会像贯穿一个case标签一样贯穿default子句。


**编程好习惯**
> 在每个 switch 语句中都放一条default子句是个好习惯，甚至可以在后边再加一个 break 。


练习：
下面运行的结果是多少？
```c
#include <stdio.h>
int main()
{
    int n = 1;
    int m = 2;
    switch (n)
   {
    case 1:
            m++;
    case 2:
            n++;
    case 3:
             switch (n)
           {//switch允许嵌套使用
             case 1:
                    n++;
             case 2:
                    m++;
                    n++;
                    break;
           }
    case 4:
            m++;
             break;
    default:
             break;
   }
    printf("m = %d, n = %d\n", m, n);
    return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/f859d5d31a9abbba03c8de620b307079.png#pic_center)

## 循环语句

 - while
 - for
 - do ..while
 
 **while循环**
我们已经学习了if语句：

> if（条件）
>     语句；

当条件满足的情况下，if语句后的语句执行，否则不执行。但是这个语句只会**执行一次**。
但是我们发现生活中很多的实际的例子是：同一件事情我们需要完成很多次。
那我们怎么做呢？ C语言中给我们引入了：**while语句**，可以实现**循环**。

> //while 语法结构
while(表达式)
 循环语句；


**while语句执行的流程**：
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/80012fc166359cacf6ccb3e77cc43a52.png#pic_center)
比如我们实现在屏幕打印1-10的数字：

```c
#include <stdio.h>
int main()
{
     int i = 1;
     while(i<=10)
     {
        printf("%d ", i);
        i = i+1;
     }
      return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/22b27aa252e689622f431cb259afa6c9.png)

这个代码已经帮我了解了while语句的基本语法，那我们再了解一下：
**while语句中的break和continue**

```c
#include <stdio.h>
int main()
{
    int i = 0;
    while (i <= 10)
    {
        i++;
        if (i == 5)
            break;
 
        printf("%d ", i);
    }
 
    return 0;
}
```

当i==5时，遇到break语句跳出循环，后面的5,6,7,8,9,10就不会打印
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/14e520fa2a665d30a7da822617ca339f.png)

```c
#include <stdio.h>
int main()
{
    int i = 0;
    while (i <= 10)
    {
        i++;
        if (i == 5)
            continue;

        printf("%d ", i);
    }

    return 0;
}
```
当i==5时，遇到continue语句，就会结束本次循环，直接跳到下一次循环。
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/f9e3fed8725336f5bafd8848215eaea2.png)
总结: **continue**在while循环中的作用就是：
continue是用于终止本次循环的，也就是本次循环中continue后边的代码不会再执行，而是直接
跳转到while语句的判断部分。进行下一次循环的入口判断。

**for循环**
我们已经知道了while循环，但是我们为什么还要一个for循环呢？ 首先来看看for循环的语法：

> for(表达式1；表达式2；表达式3)
     循环语句；
     
**表达式1** 表达式1为**初始化部分**，用于初始化循环变量的。 **表达式2** 表达式2为**条件判断部分**，用于判断循环时候终止。 **表达式3** 表达式3为**调整部分**，用于循环条件的调整。

for循环的执行流程图：

![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/d97f6f99f36ad719c2d301f88ec9642e.png)
实际问题：
在屏幕打印1-10的数字

```c
#include <stdio.h>
int main()
{
 int i = 0;
 //for(i=1/*初始化*/; i<=10/*判断部分*/; i++/*调整部分*/)
 for(i=1; i<=10; i++)
 {
 printf("%d ", i);
 }
 return 0;
}
```
现在我们对比一下for循环和while循环。

```c
int i = 0;
//实现相同的功能，使用while
     i=1;//初始化部分
  while(i<=10)//判断部分
  {
      printf("hehe\n");
      i = i+1;//调整部分
  }
//实现相同的功能，使用while
  for(i=1; i<=10; i++)
  {
     printf("hehe\n");
  }
```
可以发现在while循环中依然存在循环的三个必须条件，但是由于风格的问题使得三个部分很可能偏离
较远，这样查找修改就不够集中和方便。所以，for循环的风格更胜一筹。 for循环使用的频率也最高。

**break和continue在for循环中**
我们发现在for循环中也可以出现break和continue，他们的意义和在while循环中是一样的。 但是还是
有些差异：

```c
//代码1
#include <stdio.h>
int main()
{
    int i = 0;
    for(i=1; i<=10; i++)
    {
       if(i == 5)
           break;
       printf("%d ",i);
    }
    return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/34c15ce48c2d71a51758e9f702c557d4.png)

```c
//代码2
#include <stdio.h>
int main()
{
     int i = 0;
     for(i=1; i<=10; i++)
     {
          if(i == 5)
             continue;
          printf("%d ",i);
     }
     return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/c4b128e648e4762cc80a2b1a274d2b4b.png)
**for语句的循环控制变量**：
一些建议：

> 1. 不可在for 循环体内修改循环变量，防止 for 循环失去控制。
> 2. 建议for语句的循环控制变量的取值采用“前闭后开区间”写法。

```c
int i = 0;
//前闭后开的写法
for(i=0; i<10; i++)
{}
//两边都是闭区间
for(i=0; i<=9; i++)
{}
```
**一些for循环的变种**

```c
#include <stdio.h>
int main()
{
 //变种1
    for(;;)
    {
        printf("hehe\n");
    }
 //变种2
 int x, y;
    for (x = 0, y = 0; x<2 && y<5; ++x, y++)
   {
        printf("hehe\n");
   }
 return 0;
}
```
for循环三个部分的写法可以省略，也可以多个语句。

一道笔试题：
请问循环要循环多少次？
```c
#include <stdio.h>
int main()
{
    int i = 0;
    int k = 0;
    for(i =0,k=0; k=0; i++,k++)
         k++;
    return 0;
}
```
答案是：0次。
因为for循环中的判断语句为赋值语句k=0,判断的值为0，则不会进入for循环。

**do...while循环**
语法：

> do
>       循环语句
>  while（表达式）；

执行流程：
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/a1928a5e53f8d6c5029e0aa287fb36dc.png)


**do语句的特点**：
循环至少执行一次，使用的场景有限，所以不是经常使用。

```c
#include <stdio.h>
int main()
{
	int i = 10;
	do
	{
		printf("%d\n", i);
	} while (i < 10);
	return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/4b4b23a97d5b4ffc8bfb8fd53a59ef0b.png)
**do..while中的break和continue**

```c
#include <stdio.h>
int main()
{
    int i = 10;
    do
    {
        if (5 == i)
            break;
        printf("%d ", i);
        i--;
    } while (i < 10);
    return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/3ef05ed983b3215afa64aa72bf529973.png)

```c
#include <stdio.h>
int main()
{
    int i = 0;
    do
    { 
        i++;
        if (5 == i)
            continue;
        printf("%d ", i);
       
    } while (i < 10);
    return 0;

}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/7ca8b40b04819967875d38a59aefb2f6.png)

## 折半查找算法（二分查找）
代码实现：
```c
//实现在主函数中
#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int key = 7;
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
			break;
	}
	if (left <= right)
		printf("找到了,下标是%d\n", mid);
	else
		printf("找不到\n");
}
```
实现在函数中：
```c
int bin_search(int arr[], int left, int right, int key)
{
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right) >> 1;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
			return mid;//找到了，返回下标
	}
	return -1;//找不到
}
```

