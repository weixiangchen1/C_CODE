#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int cmp_int(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}
int main()
{
    int n, m, i, j;
    int arr[3000] = { 0 };
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (j = i; j < i + m; j++)
        scanf("%d", &arr[j]);
    qsort(arr, n + m, 4, cmp_int);
    for (i = 0; i < n + m; i++)
        printf("%d ", arr[i]);
    return 0;
}