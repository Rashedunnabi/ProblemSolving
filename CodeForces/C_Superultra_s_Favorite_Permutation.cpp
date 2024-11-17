#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(int sum)
{
    for (int i = 2; i * i <= sum; i++)
    {
        if (sum % i == 0)
            return true;
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v, even;
        set<int> st;
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
                v.push_back(i);
            else
            {
                even.push_back(i);
                st.insert(i);
            }
        }

        bool flag = false;
        for (int i = 0; i < even.size(); i++)
        {
            if (check(v.back() + even[i]))
            {
                flag = true;
                st.erase(even[i]);
                v.push_back(even[i]);
                break;
            }
        }
        while (!st.empty())
        {
            v.push_back(*st.begin());
            st.erase(st.begin());
        }
        if (flag)
        {
            for (auto val : v)
                cout << val << ' ';
            cout << '\n';
        }
        else
            cout << -1 << '\n';
    }
    return 0;
}