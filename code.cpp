#include <bits/stdc++.h>
using namespace std;

int get(int l, int r)
{
    int x;
    cout << "? " << l << " " << r << endl;
    cin >> x;
    return x;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> f(n);
    for (int i = 2; i <= n; i++)
    {
        f[i - 1] = get(1, i);
    }

    string result(n, '0');
    int count_zeros = 0, count_ones = 0;

    for (int i = 1; i < n; i++)
    {
        if (f[i] == count_zeros + count_ones)
        {
            result[i] = '0';
            count_zeros++;
        }
        else
        {
            result[i] = '1';
            count_ones += count_zeros;
        }
    }

    if (count_zeros + count_ones != f[n - 1])
    {
        cout << "! IMPOSSIBLE" << endl;
    }
    else
    {
        cout << "! " << result << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
