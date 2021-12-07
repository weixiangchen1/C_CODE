//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>  
//#define MAX 1050
//
//int dp[MAX][MAX];
//int arr[MAX][MAX];
//int n, m;
//
//int min(int x, int y)
//{
//	return x > y ? y : x;
//}
//
//int Search()
//{
//	int i, j;
//	
//	dp[0][0] = arr[0][0];
//	//��һ��
//	for (i = 1; i < m; i++)
//	{
//		dp[0][i] = dp[0][i - 1] + arr[0][i];
//	}
//	//��һ��
//	for (i = 1; i < n; i++)
//	{
//		dp[i][0] = dp[i - 1][0] + arr[i][0];
//	}
//	//����
//	for (i = 1; i < n; i++)
//	{
//		for (j = 1; j < m; j++)
//		{
//			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
//		}
//	}
//
//
//	return dp[n - 1][m - 1];
//
//}
//
//int main()
//{
//	scanf("%d%d", &n, &m);
//	memset(dp, 0, sizeof(dp));
//	memset(arr, 0, sizeof(arr));
//
//	printf("%d\n", 0x7fffffff);
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	printf("%d\n", Search());
//	//for (int i = 0; i < n; i++)
//	//{
//	//	for (int j = 0; j < m; j++)
//	//	{
//	//		printf("%d ", dp[i][j]);
//	//	}
//	//	printf("\n");
//	//}
//
//	return 0;
//}