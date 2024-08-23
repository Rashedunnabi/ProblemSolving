#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

long long power(long long a, long long b, long long m = 1e9 + 7)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        multiset<int> ms;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            ms.insert(x);
        }

        int maxi = *ms.rbegin();
        while (k > 0)
        {
            int it = *ms.begin();
            if (it * 2 >= maxi)
                break;
            ms.erase(ms.begin());
            ms.insert((it * 2) % mod);
            k--;
        }

        int div = k / n, rem = k % n;
        int val2 = power(2, div);
        int val1 = val2 * 2LL % mod;

        int sum = 0LL;
        for (auto i : ms)
        {
            if (rem)
            {
                sum = (sum + i * val1 % mod) % mod;
                rem--;
            }
            else
                sum = (sum + i * val2 % mod) % mod;
        }
        cout << sum % mod << '\n';
    }
    return 0;
}
