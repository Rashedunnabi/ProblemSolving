#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, i;
        cin >> n;
        vector<ll> v(n);
        for (ll &i : v)
            cin >> i;

        stack<ll> val, ind;
        for (i = 0; i < n; i++)
        {
            while (val.size() > 1 && val.top() >= v[i])
            {
                ll tp = val.top();
                val.pop();

                if (tp >= val.top())
                    ind.pop();
                else
                {
                    val.push(tp);
                    break;
                }
            }
            val.push(v[i]);
            ind.push(i);
        }

        ll cost = 0;
        ll tp = val.top();
        val.pop();
        ll index = ind.top();
        ind.pop();
        while (!val.empty())
        {
            cost += max(tp, val.top()) * (index - ind.top());
            tp = val.top();
            val.pop();
            index = ind.top();
            ind.pop();
        }
        cout << cost << '\n';
    }
    return 0;
}