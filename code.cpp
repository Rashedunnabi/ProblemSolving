#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int arr[N];
bool dp[N];

bool func(int i, int amount)
{
    if (amount == 0)
        return 1;
    if (i < 0)
        return 0;

    bool flag = false;
    flag |= func(i - 1, amount);

    if (amount - arr[i] >= 0)
        flag |= func(i - 1, amount - arr[i]);

    return dp[amount] = flag;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, i, j;
    cin >> n;

    for (i = 0; i < n; i++)
        cin >> arr[i];

    int sum = 0;
    cin >> sum;

    if (func(n - 1, sum))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}