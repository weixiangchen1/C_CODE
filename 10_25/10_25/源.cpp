#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

long long ans;
int n, tmp;

void dfs()
{
    if (tmp == n) {
        ++ans;
        return;
    }

    if (tmp > n)
        return;

    for (int i = 1; i <= 6; ++i) {
        tmp += i;
        dfs();
        tmp -= i;
    }
}
int main()
{
    while ((ans = tmp = 0) || cin >> n) {
        dfs();
        cout << ans << endl;
    }
    return 0;
}
