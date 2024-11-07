#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 7;
vector<int> spf(N + 1, 1);
void sieve()
{
    spf[0] = 0;
    for (int i = 2; i <= N; i++)
    {
        if (spf[i] == 1)
        {
            for (int j = i; j <= N; j += i)
            {
                if (spf[j] == 1)
                    spf[j] = i;
            }
        }
    }
}
int getFactorization(int x)
{
    int res = 0;
    while (x != 1)
    {
        x = x / spf[x];
        res++;
    }
    return res++;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;

    sieve();

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int lg = log2(k);
        int ans = getFactorization(n) + lg;
        cout << ans << '\n';
    }
}