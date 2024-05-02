#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

void solution()
{
    ll i, n, k, b, s;
    cin >> n >> k >> b >> s;

    vector<ll> p(n), a(n);
    for (ll &i : p)
        cin >> i;
    for (ll &i : a)
        cin >> i;

    ll sz = min(n, k), posB = b - 1, posS = s - 1;

    vector<ll> vb, vs;
    for (i = 0; i < sz; i++)
    {
        vb.push_back(a[posB]);
        vs.push_back(a[posS]);
        posB = p[posB] - 1;
        posS = p[posS] - 1;
    }

    ll sumB = 0, sumS = 0, bob = 0, sasha = 0;
    for (i = 0; i < sz; i++)
    {
        sumB += vb[i];
        sumS += vs[i];
        bob = max(bob, sumB + (k - i - 1) * vb[i]);
        sasha = max(sasha, sumS + (k - i - 1) * vs[i]);
    }

    if (bob == sasha)
        cout << "Draw\n";
    else if (bob < sasha)
        cout << "Sasha\n";
    else
        cout << "Bodya\n";
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