#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll give(ll p, ll q, ll r, ll s)
{
    ll dif = max({p, q, r, s}) - min({p, q, r, s});
    return dif;
}

vector<ll> TakeInput()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    return v;
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    vector<ll> caps = TakeInput();
    vector<ll> shirts = TakeInput();
    vector<ll> pants = TakeInput();
    vector<ll> shoes = TakeInput();

    ll n1 = caps.size(), n2 = shirts.size(), n3 = pants.size(), n4 = shoes.size();
    ll i1 = 0, i2 = 0, i3 = 0, i4 = 0, mn = LLONG_MAX, a = -1, b = -1, c = -1, d = -1;

    while (i1 < n1 && i2 < n2 && i3 < n3 && i4 < n4)
    {
        ll diff = give(caps[i1], shirts[i2], pants[i3], shoes[i4]);
        if (diff < mn)
        {
            mn = diff;
            a = i1, b = i2, c = i3, d = i4;
        }

        if (caps[i1] <= shirts[i2] && caps[i1] <= pants[i3] && caps[i1] <= shoes[i4])
            i1++;

        else if (shirts[i2] <= caps[i1] && shirts[i2] <= pants[i3] && shirts[i2] <= shoes[i4])
            i2++;

        else if (pants[i3] <= shirts[i2] && pants[i3] <= caps[i1] && pants[i3] <= shoes[i4])
            i3++;

        else if (shoes[i4] <= caps[i1] && shoes[i4] <= shirts[i2] && shoes[i4] <= pants[i3])
            i4++;
    }

    cout << caps[a] << " " << shirts[b] << " " << pants[c] << " " << shoes[d] << "\n";

    return 0;
}
