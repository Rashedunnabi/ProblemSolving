#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> v(n), p(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
            p[i] = n + 1 - v[i];
        }
        set<int> st;
        for (i = 1; i <= n; i++)
            st.insert(i);

        for (i = 1; i < n - 1; i++)
        {
            int maxi = max(v[i - 1], v[i + 1]);
            if (maxi == *st.rbegin())
                continue;
            p[i] = *st.rbegin();
            st.erase(*st.rbegin());
        }

        for (i = 1; i < n - 1; i++)
        {
            if (p[i])
            {
                int sum = p[i] + v[i];
                int left = sum - v[i - 1] - 1, right = sum - v[i + 1] - 1;
                if (st.find(left) != st.end())
                {
                    p[i - 1] = left;
                    st.erase(left);
                }
                if (st.find(right) != st.end())
                {
                    p[i + 1] = right;
                    st.erase(right);
                }
                if (p[i - 1] == 0)
                {
                    p[i - 1] = *st.begin();
                    st.erase(st.begin());
                }
                if (p[i + 1] == 0)
                {
                    p[i + 1] = *st.begin();
                    st.erase(st.begin());
                }
                i++;
            }
        }

        vector<pair<int, int>> remain;
        for (i = 0; i < n; i++)
        {
            if (p[i])
                continue;
            remain.push_back({v[i], i});
        }
        sort(remain.rbegin(), remain.rend());

        for (auto it : remain)
        {
            int ind = it.second;
            p[ind] = *st.begin();
            st.erase(st.begin());
        }

        int ans = 0;
        for (i = 1; i < n - 1; i++)
        {
            if (v[i] > v[i - 1] && v[i] > v[i + 1])
                ans++;
        }
        cout << ans << '\n';

        for (auto val : p)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}