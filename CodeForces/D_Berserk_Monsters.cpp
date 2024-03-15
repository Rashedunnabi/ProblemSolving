#include <bits/stdc++.h>
using namespace std;
struct monster
{
    int a, d, prev, next;
};
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int a[n], d[n];
        for (i = 0; i < n; i++)
            cin >> a[i];
        for (i = 0; i < n; i++)
            cin >> d[i];
        vector<monster> v(n);
        for (i = 0; i < n; i++)
        {
            v[i].a = a[i];
            v[i].d = d[i];
            v[i].prev = i - 1;
            v[i].next = i + 1;
            if (i == n - 1)
                v[i].next = -1;
        }
        set<int> st;
        for (i = 0; i < n; i++)
            st.insert(i);
        auto kill = [&](int i)
        {
            int prev = v[i].prev;
            int next = v[i].next;
            if (prev != -1)
                v[prev].next = next;
            if (next != -1)
                v[next].prev = prev;
        };
        for (i = 0; i < n; i++)
        {
            set<int> ans, temp;
            for (auto it : st)
            {
                int prev = v[it].prev;
                int next = v[it].next;
                int attack = 0;
                if (prev != -1)
                    attack += v[prev].a;
                if (next != -1)
                    attack += v[next].a;
                if (attack > v[it].d)
                    ans.insert(it);
            }
            for (auto it : ans)
            {
                int prev = v[it].prev;
                int next = v[it].next;
                kill(it);
                if (temp.count(it))
                    temp.erase(it);
                if (prev != -1)
                    temp.insert(prev);
                if (next != -1)
                    temp.insert(next);
            }
            cout << ans.size() << ' ';
            st = temp;
        }
        cout << '\n';
    }
    return 0;
}