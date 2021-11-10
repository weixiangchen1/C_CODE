//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <cstring>
//
//typedef long long ll;
//
//ll arr[20], x[20];
//
//ll maxSum = 0;
//ll tmp;
//
//int N;
//
//void justDoIt(ll arr[], ll x[])
//{
//	tmp = 0;
//	for (int i = 0; i < N; i++)
//	{
//		if (tmp != 0 && x[i] == 1)
//		{
//			tmp = 0;
//			break;
//		}
//
//		if (x[i] == 1)
//		{
//			for (int j = i; j < N; j++)
//			{
//				if (x[j] == 1)
//				{
//					tmp += arr[j];
//				}
//				else
//				{
//					i = j + 1;
//					break;
//				}
//			}
//		}
//	}
//	maxSum = tmp > maxSum ? tmp : maxSum;
//}
//
//void dfs(ll arr[], int i, ll x[])
//{
//	if (i >= N)
//	{
//		justDoIt(arr, x);
//	}
//	else
//	{
//		x[i] = 0;
//		dfs(arr, i + 1, x);
//		x[i] = 1;
//		dfs(arr, i + 1, x);
//	}
//}
//
//void solve()
//{
//	maxSum = 0;
//	dfs(arr, 0, x);
//
//
//	std::cout << maxSum << std::endl;
//}
//
//int main()
//{
//	while (std::cin >> N)
//	{
//		memset(arr, 0, N);
//		for (int i = 0; i < N; i++)
//		{
//			std::cin >> arr[i];
//		}
//		solve();
//	}
//
//	return 0;
//}
