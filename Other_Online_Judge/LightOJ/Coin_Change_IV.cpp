#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[20], b[20];
vector<ll> v;
set<ll> st;
ll sz1, sz2;

void makeSubset(ll pos, ll sum, ll choice)
{
    if (pos >= sz1 && choice == 1)
    {
        v.push_back(sum);
        return;
    }
    if (pos >= sz2 && choice == 2)
    {
        st.insert(sum);
        return;
    }

    ll num = 0;
    if (choice == 1)
        num = a[pos];
    else
        num = b[pos];

    makeSubset(pos + 1, sum, choice);
    makeSubset(pos + 1, sum + num, choice);
    makeSubset(pos + 1, sum + num + num, choice);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int i, testCase;
    cin >> testCase;
    for (int t = 1; t <= testCase; t++)
    {
        cout << "Case " << t << ": ";

        ll n, k, i;
        cin >> n >> k;

        sz1 = n / 2;
        sz2 = n - sz1;
        for (i = 0; i < sz1; i++)
            cin >> a[i];
        for (i = 0; i < sz2; i++)
            cin >> b[i];

        makeSubset(0, 0, 1);
        makeSubset(0, 0, 2);

        bool flag = false;
        for (i = 0; i < v.size(); i++)
        {
            ll need = k - v[i];
            if (st.find(need) != st.end())
            {
                flag = true;
                break;
            }
        }

        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";

        v.clear();
        st.clear();
    }
    return 0;
}