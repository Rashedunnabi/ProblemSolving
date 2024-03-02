#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define all(v) v.begin(), v.end()

void solution()
{
    ll n, m, i;
    cin >> n >> m;
    vector<ll> ar(n), br(n);
    for (i = 0; i < n; i++)
    {
        cin >> ar[i];
        br[i] = ar[i];
    }
    string s;
    cin >> s;

    ll left = 0, right = n - 1, res = 1;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            left++;
        if (s[i] == 'R')
            right--;
    }
    reverse(all(s));
    reverse(all(br));

    left--, right++;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'R')
        {
            res = (res * 1LL * ar[right++]) % m;
        }
        if (s[i] == 'L')
        {
            res = (res * 1LL * ar[left--]) % m;
        }
        br[i] = res;
        if (res == 0)
            res += m;
    }
    reverse(all(br));
    for (auto e : br)
        cout << e << ' ';
    cout << '\n';
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}