#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    ll n, k, i;
    cin >> n >> k;
    ll ar[n];
    for (i = 0; i < n; i++)
        cin >> ar[i];

    unordered_map<ll, int> freq;
    ll pref = 0;
    ll ans = 0;
    freq[pref]++;

    for (i = 0; i < n; i++)
    {
        pref += ar[i];
        ll need = pref - k;
        ans += freq[pref - k];
        freq[pref]++;
    }

    cout << ans << endl;

    return 0;
}
