#include <bits/stdc++.h>
using namespace std;
#define int long long

void func(int x)
{
    vector<int> v(1000, 0);
    int cnt = 0;
    for (int i = 2; i <= 400; i++)
    {
        for (int j = i; j < 400; j += i)
        {
            v[j] ^= 1;
        }
        int cnt = 0;
        for (int k = 0; k <= i; k++)
            cnt += v[k] == 1;
        if (cnt == x)
        {
            cout << "for: " << x << ' ' << i << '\n';
            return;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    for (int x = 1; x <= 100; x++)
    {
        func(x);
    }

    return 0;
}