#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void solution()
{
    ll n, m, i;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll &i : a)
        cin >> i;
    for (ll &i : b)
        cin >> i;

    sort(all(a));
    sort(rall(b));

    ll ans = 0, ii = 0, jj, j;
    i = 0;
    j = n - 1;
    jj = m - 1;

    while (i <= j)
    {
        ll afst1 = abs(a[i] - b[ii]); // a fst b fst
        ll afst2 = abs(a[i] - b[jj]); // a fst b lst

        ll alst1 = abs(a[j] - b[ii]); // a lst b fst
        ll alst2 = abs(a[j] - b[jj]); // a lst b lst

        ll fst = max(afst1, afst2);
        ll lst = max(alst1, alst2);

        ans += max(fst, lst);
        // cout << max(fst, lst) << ' ';

        if (fst >= lst)
        {
            i++;
            if (afst1 >= afst2)
            {
                ii++;
            }
            else
            {
                jj--;
            }
        }
        else
        {
            j--;
            if (alst1 >= alst2)
            {
                ii++;
            }
            else
            {
                jj--;
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    Faster;
    ll t;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
