#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//    string str;
//    char max_ch = 0;
//    int max = -2000;
//    int count[26] = { 0 };
//    cin >> str;
//    for (int i = 0; i < str.size(); ++i)
//    {
//        count[str[i] - 'a']++;
//    }
//    for (int i=25; i>=0; i--)
//    {
//
//        if (count[i] >= max)
//        {
//            max = count[i];
//            max_ch = 'a' + i;
//        }
//    }
//
//    cout << max_ch << endl;
//    cout << max << endl;
//
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//char x[10][10] = {
//					  'U','D','D','L','U','U','L','R','U','L',
//					  'U','U','R','L','L','L','R','R','R','U',
//					  'R','R','U','U','R','L','D','L','R','D',
//					  'R','U','D','D','D','D','U','U','U','U',
//					  'U','R','U','D','L','L','R','R','U','U',
//					  'D','U','R','L','R','L','D','L','R','L',
//					  'U','L','L','U','R','L','L','R','D','U',
//					  'R','D','L','U','L','L','R','D','D','D',
//					  'U','U','D','D','U','D','U','D','L','L',
//					  'U','L','R','D','L','U','U','R','R','R'
//};
//
//
//int main()
//{
//
//
//
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//class Test {
//    int val;
//public:
//    Test()
//    {
//        cout << "Default.\n";
//    }
//    Test(int i) :val(i)
//    {
//        cout << "Con.\n";
//    }
//    Test(const Test& t) {
//        val = t.val; cout << "Copy Con." << endl;
//    }
//};
//int main() {
//    Test t1(6);
//    Test t2 = t1;
//    Test t3;
//    t3 = t1;
//    return 0;
//}
//
//class exam {
//    int x;
//public:
//    exam(int n) { x = n; }
//};
//
//int main()
//{
//    exam ob[4] = { exam(11), exam(11) ,exam(11) ,exam(11) };
//
//    return 0;
//}

//class Z {
//    static int a;
//public:
//    static void fStatic(Z&);
//};
//int Z::a = 0;
//Z objZ;
//
//void Z::fStatic(Z& objZ)
//{
//    this->a = 0;
//}
//int main()
//{
//    return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//    int n, score;
//    scanf("%d", &n);
//    int goodStu = 0, passStu = 0;
//    for(int i=0; i<n; i++)
//    {
//        scanf("%d", &score);
//        if (score >= 60)
//        {
//            passStu++;
//        }
//        if (score >= 85)
//        {
//            goodStu++;
//        }
//    }
//    double x1 = (double)goodStu / (double)n;
//    double x2 = (double)passStu / (double)n;
//
//    printf("%.0f%%\n", x2*100);
//    printf("%.0f%%\n", x1*100);
//
//    return 0;
//}
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int monthDay[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//bool checkTrue(int year, int month, int day)
//{
//    if (month >= 1 && month <= 12)
//    {
//        if (((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0)) && month == 2)
//        {
//            return day <= monthDay[month] + 1 ? true : false;
//        }
//        else
//        {
//            return day <= monthDay[month] ? true : false;
//        }
//    }
//    else
//    {
//        return false;
//    }
//}
//
//    
//
//bool f1(int i)
//{
//    string str = to_string(i);
//    string s(str);
//    reverse(str.begin(), str.end());
//
//    return s == str ? true : false;
//
//}
//
//bool f2(int i)
//{
//    if (!f1(i))
//        return false;
//
//    string str = to_string(i);
//    string str1 = str.substr(0, 2);
//    string str2 = str.substr(2, 2);
//    string str3 = str.substr(4, 2);
//    string str4 = str.substr(6, 2);
//
//    reverse(str1.begin(), str1.end());
//    reverse(str2.begin(), str2.end());
//
//    return (str1 == str2 && str2 == str3 && str3 == str4) ? true : false;
//
//}
//
//
//int main()
//{
//    int num = 0;
//    int ans1=0, ans2=0;
//    bool flag1 = true, flag2 = true;
//    cin >> num;
//
//    for (int i = num + 1; ; ++i)
//    {
//        int year = i / 10000;
//        int month = (i % 10000) / 100;
//        int day = i % 100;
//
//        if (checkTrue(year, month, day) && flag1 && f1(i))
//        {
//            flag1 = false;
//            ans1 = i;
//        }
//
//        if (checkTrue(year, month, day) && flag2 && f2(i))
//        {
//            flag2 = false;
//            ans2 = i;
//        }
//
//        if (!flag1 && !flag2)
//            break;
//    }
//
//    cout << ans1 << endl;
//    cout << ans2 << endl;
//
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int cnt = 0;
//	for (int i = 1; i <= 2020; ++i)
//	{
//		int cur = i;
//		while (cur)
//		{
//			if (cur % 10 == 2)
//			{
//				cnt++;
//			}
//			cur /= 10;
//		}
//	}
//
//	cout << cnt << endl;
//
//
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//int main()
//{
//    int n;
//    int a[101][101];
//    int dp[101][101];
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= i; j++)
//        {
//            cin >> a[i][j];
//        }
//    }
//    dp[1][1] = a[1][1];
//    for (int i = 2; i <= n; i++)
//    {
//        for (int j = 1; j <= i; j++)
//        {
//            dp[i][j] = a[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
//        }
//    }
//
//    if (n % 2 == 0)
//        cout << max(dp[n][n / 2], dp[n][n / 2 + 1]) << endl;
//    else
//        cout << dp[n][n / 2 + 1] << endl;
//
//
//
//    return 0;
//}

	#include <iostream>
	using namespace std;

	int monthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	int main()
	{
		int ans = 0;
		int beginDay = 6;
		for (int year = 2000; year <= 2020; year++)
		{
			if ((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0))
				monthDay[2] = 29;
			else
				monthDay[2] = 28;

			for (int month = 1; month <= 12; month++)
			{
				for (int day = 1; day <= monthDay[month]; day++)
				{
					ans++;
					if (beginDay == 8)
					{
						beginDay = 1;
					}
					if (beginDay == 1 || day == 1)
					{
						ans++;
					}
					beginDay++;

					if (year == 2020 && month == 10 && day == 1)
					{
						cout << ans << endl;
					}

				}
			}
		}

		return 0;
	}