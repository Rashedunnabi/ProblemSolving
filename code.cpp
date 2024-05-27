#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> makeBinary(ll n)
{
    vector<ll> v;
    ll sz = log2(n);
    for (ll i = 1 << sz; i > 0; i = i / 2)
    {
        if ((n & i) != 0)
            v.push_back(1);
        else
            v.push_back(0);
    }
    // cout << n << '\n';
    // for (auto val : v)
    //     cout << val << ' ';
    // cout << '\n';
    reverse(v.begin(), v.end());
    return v;
}

bool check(vector<ll> &v)
{
    bool flag = true;
    for (int i = 0; i < (int)v.size() - 1; i++)
    {
        if (v[i] != 0 && v[i + 1] != 0)
            flag = false;
    }
    return flag;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll x;
        cin >> x;
        ll lg = log2(x);
        ll val = round(pow(2, lg));
        ll val2 = round(pow(2, lg + 1));

        if (val == x)
        {
            cout << lg + 1 << '\n';
            for (ll i = 0; i < lg; i++)
            {
                cout << 0 << ' ';
            }
            cout << 1 << '\n';
        }
        else if (x == val2 - 1)
        {
            cout << lg + 2 << '\n';
            cout << -1 << ' ';
            for (ll i = 0; i < lg; i++)
            {
                cout << 0 << ' ';
            }
            cout << 1 << '\n';
        }
        else
        {
            vector<ll> v = makeBinary(x);
            if (check(v))
            {
                cout << v.size() << '\n';
                for (auto val : v)
                    cout << val << ' ';
                cout << '\n';
            }
            else
            {
                ll sz = log2(x), val1 = 0, val2 = 0;
                vector<int> v(sz + 2);
                v[sz + 1] = 1;
                val1 = round(pow(2, sz + 1));
                x -= val1;

                int c = 10;
                while (c--)
                {
                    vector<ll> temp = makeBinary(abs(x));
                    if (check(temp))
                    {
                        for (int i = 0; i < temp.size(); i++)
                        {
                            v[i] = temp[i] * (x < 0 ? -1 : 1);
                        }
                        break;
                    }

                    if (x < 0)
                    {
                    }
                    else
                    {
                    }
                }
                cout << v.size() << '\n';
                for (auto val : v)
                    cout << val << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}