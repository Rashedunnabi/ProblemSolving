#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> tmp;

bool check(int mid, vector<int> &v)
{
    int sum = 0LL;
    for (int i = 0; i < v.size(); i++)
    {
        int x = (mid / v[i]) + 1;
        sum += x;
        tmp.push_back(x);
    }
    bool flag = 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (tmp[i] * v[i] <= sum)
            flag = 0;
    }
    return flag;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        int high = -1;
        for (i = 0; i <= 32; i++)
        {
            tmp.clear();
            int m = 1LL << i;
            if (check(m, v))
            {
                high = m;
                break;
            }
        }

        if (high == -1)
        {
            cout << -1 << '\n';
            continue;
        }
        for (auto val : tmp)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}