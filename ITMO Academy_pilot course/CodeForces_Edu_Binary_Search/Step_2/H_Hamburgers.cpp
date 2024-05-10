#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;
ll nb, ns, nc, pb, ps, pc, amount;
map<char, ll> mp;
bool check(ll mid)
{
    ll needB, needS, needC;
    needB = needS = needC = 0LL;
    for (auto val : mp)
    {
        if (val.first == 'B')
            needB = (val.second * 1LL * mid);
        if (val.first == 'C')
            needC = (val.second * 1LL * mid);
        if (val.first == 'S')
            needS = (val.second * 1LL * mid);
    }
    needB -= nb, needC -= nc, needS -= ns;
    ll totalPrice = 0LL;
    if (needB > 0)
        totalPrice += (needB * 1LL * pb);
    if (needC > 0)
        totalPrice += (needC * 1LL * pc);
    if (needS > 0)
        totalPrice += (needS * 1LL * ps);

    return totalPrice <= amount;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> amount;

    ll i, n = s.length();
    for (i = 0; i < n; i++)
        mp[s[i]]++;

    ll lo = 0, hi = 2e13, mid; // by default you can set hi 1e12+101 or 1e13

    // finind high value
    for (ll i = 0; i < 62; i++)
    {
        ll mid = 1LL << i;
        if (!check(mid))
        {
            hi = mid;
            break;
        }
    }

    while (hi - lo > 1)
    {
        mid = lo + (hi - lo) / 2;
        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }
    cout << lo << '\n';
    return 0;
}