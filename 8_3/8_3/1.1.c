#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int n = 0;
    int i = 0;
    int j = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            printf("* ");
        }
        printf("\n");
        for (j = 0; j < n - 2; j++)
        {
            printf("*");
            for (i = 0; i < 2 * n - 3; i++)
            {
                printf(" ");
            }
            printf("* ");
            printf("\n");

        }
        for (i = 0; i < n; i++)
        {
            printf("* ");
        }
        printf("\n");
    }
}