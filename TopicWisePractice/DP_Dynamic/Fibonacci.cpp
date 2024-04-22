#include <bits/stdc++.h>
using namespace std;

//  0 1 1 2 3 5 8 13 21 34 55 ......

int dp[1000006];

int fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));

    cout << fibo(n) << '\n';
}