#include <bits/stdc++.h>
using namespace std;
void solution()
{
    int n, i;
    string s;
    cin >> n >> s;

    vector<int> divisors;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            if (i != n / i)
                divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());

    int ans = n;
    for (int len : divisors)
    {
        string k = s.substr(n - len, len);
        int mitmatch = 0, cnt = 0;

        for (i = 0; i < n; i++)
        {
            if (s[i] != s[i % len])
                mitmatch++;
            if (s[i] != k[i % len])
                cnt++;
        }

        if (min(mitmatch, cnt) <= 1)
        {
            ans = len;
            break;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
