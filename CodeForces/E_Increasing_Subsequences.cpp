#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

void solution()
{
    ll x;
    cin >> x;

    ll val = log2l(x);
    vector<int> v;
    for (int i = 1; i <= val; i++)
        v.push_back(i);

    for (ll i = val - 1; i >= 0; i--)
    {
        bool flag = (x >> i) & 1;
        if (flag)
        {
            v.push_back(1);
            int n = v.size();
            for (int j = 0; j < i; j++)
            {
                swap(v[n - 1 - j], v[n - 1 - j - 1]);
            }
        }
    }
    cout << v.size() << '\n';
    for (auto val : v)
        cout << val << ' ';
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