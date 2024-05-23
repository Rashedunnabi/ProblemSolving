#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void solution()
{
    ll n, i;
    cin >> n;
    vector<ll> v(n);
    for (ll &i : v)
        cin >> i;

    stack<ll> st;
    stack<ll> ind;
    ll cost = 0;
    for (i = 0; i < n; i++)
    {
        while (st.size() > 1 && st.top() > v[i])
        {
            ll v1 = st.top();
            st.pop();
            if (v1 >= st.top())
                ind.pop();
            else
            {
                st.push(v1);
                break;
            }
        }
        st.push(v[i]);
        ind.push(i);
    }

    ll last = st.top();
    st.pop();
    ll j = ind.top();
    ind.pop();
    while (!st.empty())
    {
        cost += max(last, st.top()) * (j - ind.top());
        last = st.top();
        st.pop();
        j = ind.top();
        ind.pop();
    }
    cout << cost << '\n';
}

int main()
{
    Faster;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}