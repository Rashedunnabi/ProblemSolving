#include <bits/stdc++.h>
using namespace std;
#define ll long long

const long long N = 2e5 + 7;
long long bit[N + 1];

long long sum(long long i)
{
    long long ans = 0;
    for (; i > 0; i -= (i & -i))
    {
        ans += bit[i];
    }
    return ans;
}

void update(long long i, long long x)
{
    for (; i <= N; i += (i & -i))
    {
        bit[i] += x;
    }
}

long long getInversions(long long *arr, int n)
{
    int i = 0;
    map<long long, long long> mp;
    for (i = 0; i < n; i++)
        mp[arr[i]];
    i = 1;

    for (auto &e : mp)
        e.second = i++;

    vector<long long> v;
    for (i = 0; i < n; i++)
    {
        v.push_back(mp[arr[i]]);
    }

    long long ans = 0, mx = *max_element(v.begin(), v.end()) + 1;

    for (i = 0; i < n; i++)
    {
        ans += (sum(mx) - sum(v[i]));
        update(v[i], 1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < N; i++)
            bit[i] = 0;

        int n, i;
        cin >> n;
        ll arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];

        cout << getInversions(arr, n) << endl;
    }
    return 0;
}