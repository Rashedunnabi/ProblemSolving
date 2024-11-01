#include <bits/stdc++.h>
using namespace std;
#define int long long

void odd(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                for (int d = 1; d <= n; d++)
                {
                    if (i == j || i == k || i == d || j == k || j == d || k == d)
                        continue;
                    int ans = ((i & j) | k) & d;
                    if (ans == n)
                    {
                        cout << i << ' ' << j << ' ' << k << ' ' << d << '\n';
                    }
                }
            }
        }
    }
}

void powerOfeven(int n)
{
    int lg = log2(n) + 1;
    int val = round(pow(2, lg)) - 1;
    cout << val << '\n';

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (i == j || i == k || j == k)
                    continue;
                int ans = (((1 | i) & j) | k);
                if (ans == val)
                {
                    cout << i << ' ' << j << ' ' << k << '\n';
                }
            }
        }
    }
}
void even(int n)
{
    int lg = log2(n) + 1;
    int val = round(pow(2, lg)) - 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {

                if (i == j || i == k || j == k)
                    continue;
                int ans = (i & j) | k;
                if (ans == val)
                {
                    cout << i << ' ' << j << ' ' << k << '\n';
                }
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;

    int lg = log2(n) + 1;
    int val = round(pow(2, lg)) - 1;
    if (pow(2, lg - 1) == n)
        powerOfeven(n);
    else if (n & 1)
        odd(n);
    else
        even(n);

    return 0;
}