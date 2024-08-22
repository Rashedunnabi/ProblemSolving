#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

void solution()
{
    int n, q, i;
    cin >> n >> q;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    int sum = accumulate(v.begin(), v.end(), 0);

    vector<pair<int, int>> vp;
    for (i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            vp.push_back({i, j});
        }
    }
    map<int, vector<int>> mp;
    for (auto val : vp)
    {
        int s = sum;
        for (i = 0; i < n; i++)
        {
            if (i == val.first || i == val.second)
                continue;
            s += v[i];
        }
        swap(v[val.first], v[0]);
        swap(v[val.second], v[n - 1]);
        mp[s] = v;
        swap(v[val.first], v[0]);
        swap(v[val.second], v[n - 1]);
    }

    while (q--)
    {
        int x;
        cin >> x;

        if (mp.find(x) == mp.end())
            cout << -1 << '\n';
        else
        {
            for (auto val : mp[x])
                cout << val << ' ';
            cout << '\n';
        }
    }
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