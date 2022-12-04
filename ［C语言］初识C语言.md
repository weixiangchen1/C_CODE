今天我们接着上次的初识C语言系列。
@[TOC]
## 一、字符串+转义字符+注释
**1.字符串**

> "Hello World！"


这种由双引号（Double Quote）引起来的一串字符称为字符串字面值（String Literal），或者简称字符串。

```c
#include <stdio.h>
//下面代码，打印结果是什么？为什么？（突出'\0'的重要性）
int main()
{
    char arr1[] = "bit";
    char arr2[] = {'b', 'i', 't'};
    char arr3[] = {'b', 'i', 't'， '\0'};
    printf("%s\n", arr1);
    printf("%s\n", arr2);
    printf("%s\n", arr3);
    return 0;
}
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210715150835542.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70#pic_center)


上面是字符串的三种定义方式，其中注意字符串的结束标志是一个 \0 的转义字符，所以第二种定义方式是错误的，导致了乱码。
第一种直接用字符串初始化数组，计算机会提前把\0转义字符输入进去，所以可以正常打印。



**2.计算字符串长度**

下面使用strlen（）函数计算字符串长度。

```c
#include <stdio.h>
#include <string.h>//要使用strlen函数要引入string.h头文件
int main()
{
     char arr1[10] = "Hello";
     char arr2[] = {'H', 'e', 'l', 'l', 'o', '\0'};
     char arr3[] = {'H', 'e', 'l', 'l', 'o'};
     printf("%d\n", strlen(arr1));
     printf("%d\n", strlen(arr2));
     printf("%d\n", strlen(arr3));
     return 0；
}
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210715152027447.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70#pic_center)
注意：在计算字符串长度的时候 \0 是结束标志，不算作字符串内容。
因为arr3中未添加\0，计算机不知道那个位置是结束标志，所以结果与arr1和arr2不相同。

**3.转义字符**
假如我们要在屏幕上打印一个目录： c:\code\test.c
我们应该如何写代码？

```c
#include <stdio.h>
int main()
{
 printf("c:\code\test.c\n");
    return 0;
}
```
大部分小白可能都是这样写代码的。
但实际的运行结果是:
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210715152714791.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70#pic_center)
在这里就不得不引入转义字符了。
| 转义字符 | 含义     |
|--|--|
|  \\'| 用于表示字符常量' |
| \\'' | 用于表示一个字符串内部的双引号 |
|\\\\|用于表示一个反斜杠，防止它被解释为一个转义序列符。|
| \a |警告字符 |
|\?|在书写连续多个问号时使用，防止他们被解析成三字母词|
| \b | 退格符 |
|\f|进纸符|
| \n  |  换行|
|\r|空格|
|  \t|  水平制表符|
|  \v|  垂直制表符|
|\ddd  | ddd表示1~3个八进制的数字。 如： \130 X|
| \xdd | dd表示2个十六进制数字。 如： \x30 0 |
在屏幕上打印一个单引号'，怎么做？
在屏幕上打印一个字符串，字符串的内容是一个双引号“，怎么做？

```c
#include <stdio.h>
int main()
{
    printf("%c\n", '\'');\\在'前面加上\即可
    printf("%s\n", "\"");\\在"前面加上\即可
    return 0;
}
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/2021071515391147.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70#pic_center)
下面跟小伙伴分享一道笔试题：

```c
//程序输出什么？
#include <stdio.h>
int main()
{
    printf("%d\n", strlen("abcdef"));
    printf("%d\n", strlen("c:\test\328\test.c"));
    return 0;
}
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210715154232542.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70#pic_center)

其中\t和\32被解释为转义字符，只代表一个字符，故答案是14。

**4.注释**

> 1. 代码中有不需要的代码可以直接删除，也可以注释掉
> 2. 代码中有些代码比较难懂，可以加一下注释文字

介绍两种注释风格

 - C语言风格的注释 /*xxxxxx*/ 
  缺陷：不能嵌套注释 
 - C++风格的注释 //xxxxxxxx 
 -可以注释一行也可以注释多行

实例：

```c
#include <stdio.h>
int Add(int x, int y)
{
    return x+y;
}
/*C语言风格注释
int Sub(int x, int y)
{
    return x-y;
}
*/
int main()
{
    //C++注释风格
    //int a = 10;
    //调用Add函数，完成加法
    printf("%d\n", Add(1, 2));
    return 0;
}
```

## 二、选择语句
如果好好打代码，就有可能收获好offer。
如果不好好打代码，就得回家种红薯。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210715155616506.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70#pic_center)

```c
#include <stdio.h>
int main()
{
    int coding = 0;
    printf("你会去敲代码吗？（选择1 or 0）:>");
    scanf("%d", &coding);
    if(coding == 1)
   {
       prinf("坚持，你会有好offer\n");
   }
    else
   {
       printf("放弃，回家卖红薯\n");
   }
    return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210715155803953.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70#pic_center)



## 三、循环语句

有些事必须日复一日的循环的做，比如学习，打代码。
那么C语言是如何实现循环的呢？
有三种结构：

 - while语句
 - for语句
 - do...while语句




下面举例while语句的样例，for和do...while语句在后续会详细提到。
```c
#include <stdio.h>
int main()
{
    int line = 0;
    while(line<=20000)
   {
        line++;
        printf("我要继续努力敲代码\n");
   }
    if(line>20000)
        printf("赢取白富美\n");
    return 0;
}
```
## 四、函数
此函数非彼函数，C语言中的函数的作用是可以将一段经常需要使用的代码封装起来，在需要使用时可以直接调用。

```c
#include <stdio.h>
int main()
{
    int num1 = 0;
   int num2 = 0;
    int sum = 0;
    printf("输入两个操作数:>");
    scanf("%d %d", &a, &b);
    sum = num1 + num2;
    printf("sum = %d\n", sum);
    return 0;
}
```
上述的代码我们可以把它写成函数，起到简化代码，增强代码的可读性、反复调用的作用。
上述代码，写成函数如下：

```c
#include <stdio.h>
int Add(int x, int y)
{
   int z = x+y;
   return z;
}
int main()
{
    int num1 = 0;
   int num2 = 0;
    int sum = 0;
    printf("输入两个操作数:>");
    scanf("%d %d", &num1, &num2);
    sum = Add(num1, num2);
    printf("sum = %d\n", sum);
    return 0;
}
```
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210718235905125.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70#pic_center)
## 五、数组
数组就是一组**相同类型元素**的集合，用来存放多个相同类型的元素


**1.数组的定义**
```c
int arr[10] = {1,2,3,4,5,6,7,8,9,10};//定义一个整形数组，最多放10个整形元素
```

> int 是数组的类型；arr是数组的名字；[10]是数组的大小，数组的大小也可以不写，编译器会自动识别数组的大小；{ }内是数组的每个元素。

**2.数组的使用**

```c
#include <stdio.h>
int main()
{
 int i = 0;
 int arr[10] = {1,2,3,4,5,6,7,8,9,10};
 for(i=0; i<10; i++)
 {
       printf("%d ", arr[i]);//用循环的方式打印数组中的每个元素
 }
 printf("\n");
    return 0;
 }

```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719000258179.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70#pic_center)

