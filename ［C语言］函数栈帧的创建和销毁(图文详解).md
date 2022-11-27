@[TOC]
# 函数栈帧定义

> **C语言中，每个栈帧对应着一个未运行完的函数。栈帧中保存了该函数的返回地址和局部变量。**

 
 <br>
 
 ## 寄存器

>  **寄存器是CPU内部用来存放数据的一些小型存储区域，用来暂时存放参与运算的数据和运算结果。**

**寄存器种类**：

> eax ebx ecx edx 
> ebp esp ...

<font color=red size=3>**其中ebp和esp这两个寄存器是用来存放维护函数栈帧的地址。**</font>



# 函数栈帧的创建
每一个函数调用，都要在**栈区**创建一个空间。
+ 注：栈区的存储是由高地址向低地址存储的。

测试代码：

```c
#include <stdio.h>
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	c = Add(a,b);
	printf("%d\n", c);

	return 0;
}
```

**在vs2013的环境下，main函数也是被其他函数调用的。**

![在这里插入图片描述](https://img-blog.csdnimg.cn/aaa7227216844e91a4f6e78cc0b4b490.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)

实质上main函数的调用过程是：
![在这里插入图片描述](https://img-blog.csdnimg.cn/315d8b33871940f5909216007ff8dbc2.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
**大致轮廓是：**
![在这里插入图片描述](https://img-blog.csdnimg.cn/cd70907065264279a859a7ec518809af.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
**反汇编代码**：

```c
     1: #include <stdio.h>
     2: int Add(int x, int y)
     3: {
008F13C0  push        ebp  
008F13C1  mov         ebp,esp  
008F13C3  sub         esp,0CCh  
008F13C9  push        ebx  
008F13CA  push        esi  
008F13CB  push        edi  
008F13CC  lea         edi,[ebp+FFFFFF34h]  
008F13D2  mov         ecx,33h  
008F13D7  mov         eax,0CCCCCCCCh  
008F13DC  rep stos    dword ptr es:[edi]  
     4: 	int z = 0;
008F13DE  mov         dword ptr [ebp-8],0  
     5: 	z = x + y;
008F13E5  mov         eax,dword ptr [ebp+8]  
008F13E8  add         eax,dword ptr [ebp+0Ch]  
008F13EB  mov         dword ptr [ebp-8],eax  
     6: 	return z;
008F13EE  mov         eax,dword ptr [ebp-8]  
     7: }
008F13F1  pop         edi  
008F13F2  pop         esi  
008F13F3  pop         ebx  
008F13F4  mov         esp,ebp  
008F13F6  pop         ebp  
008F13F7  ret  
     8: 
     9: int main()
    10: {
008F1410  push        ebp  
008F1411  mov         ebp,esp  
008F1413  sub         esp,0E4h  
008F1419  push        ebx  
008F141A  push        esi  
008F141B  push        edi  
008F141C  lea         edi,[ebp+FFFFFF1Ch]  
008F1422  mov         ecx,39h  
008F1427  mov         eax,0CCCCCCCCh  
008F142C  rep stos    dword ptr es:[edi]  
    11: 	int a = 10;
008F142E  mov         dword ptr [ebp-8],0Ah  
    12: 	int b = 20;
008F1435  mov         dword ptr [ebp-14h],14h  
    13: 	int c = 0;
008F143C  mov         dword ptr [ebp-20h],0  
    14: 	c = Add(a,b);
008F1443  mov         eax,dword ptr [ebp-14h]  
008F1446  push        eax  
008F1447  mov         ecx,dword ptr [ebp-8]  
008F144A  push        ecx  
008F144B  call        008F10E1  
008F1450  add         esp,8  
008F1453  mov         dword ptr [ebp-20h],eax  
    15: 	printf("%d\n", c);
008F1456  mov         esi,esp  
008F1458  mov         eax,dword ptr [ebp-20h]  
008F145B  push        eax  
008F145C  push        8F5858h  
008F1461  call        dword ptr ds:[008F9114h]  
008F1467  add         esp,8  
008F146A  cmp         esi,esp  
008F146C  call        008F113B  
    16: 
    17: 	return 0;
008F1471  xor         eax,eax  
    18: }
008F1473  pop         edi  
008F1474  pop         esi  
008F1475  pop         ebx  
    18: }
008F1476  add         esp,0E4h  
008F147C  cmp         ebp,esp  
008F147E  call        008F113B  
008F1483  mov         esp,ebp  
008F1485  pop         ebp  
008F1486  ret  
```
**初始状态：**
![在这里插入图片描述](https://img-blog.csdnimg.cn/1f715482e68c4591bd3d7c7cd29964ec.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
## main函数栈帧的创建

**第一步进行push指令，将ebp压入栈顶**
![在这里插入图片描述](https://img-blog.csdnimg.cn/e56b5bbcc4114c619a6cb4f9ac140251.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
**将ebp压入栈，esp的指向也随之发生改变。**
**根据内存和监视可以看出ebp确实被压进了栈区。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/65d3543e45de46faab312588c21a0b3b.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/51980dc0224f41f399d7199b439dcef9.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)

 **第二步进行move指令，将esp的值给ebp**
![在这里插入图片描述](https://img-blog.csdnimg.cn/c2ab7e910c6849468559a47acf3935c1.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
**通过观察内存：**
![在这里插入图片描述](https://img-blog.csdnimg.cn/6c0429dc62ec472b9ff2abbdee7ffc77.png)
**第三步进行sub指令，将esp指向的地址减去0E4h(十进制228)。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/638568b5561d47bd8ed876f10ce4ecb7.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
**随后分别把ebx，esi，edi压入栈顶**
![在这里插入图片描述](https://img-blog.csdnimg.cn/2af8d4c22d934ac4a82ec1933749bab2.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
**随后四句指令，把从edi(ebp-0E4h)开始的ecx(39h)个 空间改成eax(0CCCCCCCCh)。这么做是为了给main函数栈帧初始化。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/b1808182589b4c1a857230c67d56e122.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
**随后对变量a,b,c 进行创建和初始化。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/86c573c425bd4c23824963e4558209be.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
## Add函数栈帧的创建

**当abc变量创建好了之后，就要开始调用add函数。**
**随后分别将ebx(20)和ecx(10)压入栈顶。**
**这两个指令实际上是在为Add函数传参。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/26de80543b1e4370a3292e010462ee87.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
**随后call指令是调用函数指令，它会把call指令的下一条指令的地址压入栈顶。这样做的目的是等Add函数调用结束后，就会回到call指令的下一条指令继续执行。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/2b38227dcc824c8abe0171b80935be6e.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)

**进入Add函数后，前面的几条指令跟进入main之前的几条指令一样，是为了给函数准备栈帧和对其进行初始化。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/741596b547ab4afb89b43d86f987190a.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)

**随后在ebp-8的空间创建临时变量z并初始化为0，再通过ebp+8和
ebp+0Ch找到main函数中传递的a,b参数作为形参x,y，相加得到的值赋给eax，再由eax把值赋给z。**

**可以得出结论：<font color=red size=3>形参是实参的一份临时拷贝。</font>**
**随后把z的值放到eax寄存器里面，当函数调用结束后z变量销毁后回到主函数可以通过eax找到计算后的值。**
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/aee078afad9e4013a6d80b11cdf987cc.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
## Add函数栈帧的销毁

**随后三句pop指令分别把edi,esi,ebx弹出栈区，把ebp的值给esp，再弹出之前main函数的ebp地址给ebp，Add栈帧销毁，随后回到主函数执行接下来指令。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/841ab8b85b694086a6e4888291adfbaa.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
**随后ret指令找到之前已经压入栈的call指令的下一条指令的地址 ，就回到主函数的call指令的下一条指令。**
**再将esp指向的地址加8，把形参的内存释放。**
**在通过ebp-20h找到main函数的c变量，然后再把eax的值赋给c，实现了把Add函数计算结果带回到main。**
![在这里插入图片描述](https://img-blog.csdnimg.cn/f096cd32f053415d9862011ba83b312f.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl81MzAyNzkxOA==,size_16,color_FFFFFF,t_70)
# 总结
+ 局部变量是怎么创建的？

> **先给函数栈帧分配空间并初始化，在创建局部变量在栈帧里并赋值。**

+ 为什么局部变量的值是随机值？

> **因为如果局部变量不初始化，函数栈帧里面的值全是0xcccccccch，所以局部变量的值是随机值。**

+ 函数是怎么传参的？传参是顺序的怎样的？

>  **当函数调用之前，会先把参数从右向左压入栈区，随后进入函数通过指针的偏移量来找到形参。**

+ 形参和实参是什么关系？

> **形参和实参只是值相同，它们的空间是独立的，所以说形参是实参的一份临时拷贝。**

+ 函数调用结束后是怎么返回的？

> **函数在调用时会先把call指令的下一条指令的地址和调用上一个函数的ebp压入栈，当函数结束调用时弹出值就可以跳转到上一个函数的栈帧空间。**

