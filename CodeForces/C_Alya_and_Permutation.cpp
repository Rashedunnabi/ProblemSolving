#include <bits/stdc++.h>
using namespace std;

void odd(int n)
{
    cout << n << '\n';
    for (int i = 2; i < n - 1; i++)
    {
        if (i == 3)
            continue;
        cout << i << ' ';
    }
    cout << 1 << ' ' << 3 << ' ' << n - 1 << ' ' << n << '\n';
}

void powerOfeven(int n)
{
    int lg = log2(n) + 1;
    int val = round(pow(2, lg)) - 1;

    cout << val << '\n';

    for (int i = 2; i < n - 2; i++)
    {
        if (i == 3)
            continue;
        cout << i << ' ';
    }
    cout << 1 << ' ' << 3 << ' ' << n - 2 << ' ' << n - 1 << ' ' << n << '\n';
}
void even(int n)
{
    int lg = log2(n);
    int val = round(pow(2, lg)) - 1;
    int ans = round(pow(2, lg + 1)) - 1;
    cout << ans << '\n';

    for (int i = 1; i < n - 1; i++)
    {
        if (i == val)
            continue;
        cout << i << ' ';
    }
    cout << n << ' ' << n - 1 << ' ' << val << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
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
    }
    return 0;
}