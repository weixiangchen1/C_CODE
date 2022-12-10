![在这里插入图片描述](https://img-blog.csdnimg.cn/20210721172849512.jpeg)
## goto语句
C语言中提供了可以随意滥用的 goto语句和标记跳转的标号。
从理论上 goto语句是没有必要的，实践中没有goto语句也可以很容易的写出代码。
但是某些场合下goto语句还是用得着的，最常见的用法就是终止程序在某些深度嵌套的结构的处理过
程，例如**一次跳出两层或多层循环**。
这种情况使用break是达不到目的的。它只能从最内层循环退出到上一层的循环。
goto语言适合的场景如下：

```c
for (...)
for (...)
{
    for (...)
    {
        if (disaster)
            goto error;
    }
}
…
error :
if (disaster)
```
用于跳出多重循环和处理错误情况。

下面介绍一个好玩的小程序：
（关机程序）

```c
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char input[10] = { 0 };
    system("shutdown -s -t 60");
again:
    printf("电脑将在1分钟内关机，如果输入：我是猪，就取消关机!\n请输入:>");
    scanf("%s", input);
    if (0 == strcmp(input, "我是猪"))
    {
        system("shutdown -a");
    }
    else
    {
        goto again;
    }
    return 0;
}
```
程序运行后，如果在一分钟之内不输入我是猪，电脑就会自动关机。
![在这里插入图片描述](https://img-blog.csdnimg.cn/img_convert/57fbd258443f96bffe332a1d0a50efcb.png)
程序运用到了Windows 系统自带一个名为Shutdown.exe的程序，可以用于关机操作。
**shutdown 基本命令**：
 shutdown -s 关机
 shutdown -s -t 时间　设置关机倒计时
 shutdown-a　取消关机
 at 1：00 shutdown -s 定时关机
 shutdown -f　强行关闭应用程序
 shutdown -h 休眠
 shutdown -m \计算机名　控制远程计算机
 shutdown -l　注销当前用户
 shutdown -r　关机并重启
 shutdown -i　显示“远程关机”图形用户界面


而如果不适用goto语句，则可以使用循环：

```c
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char input[10] = { 0 };
    system("shutdown -s -t 60");
    while (1)
    {
        printf("电脑将在1分钟内关机，如果输入：我是猪，就取消关机!\n请输入:>");
        scanf("%s", input);
        if (0 == strcmp(input, "我是猪"))
        {
            system("shutdown -a");
            break;
        }
    }
    return 0;
}
```
快去恶搞你的朋友吧！
