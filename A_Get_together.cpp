#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(double mid, vector<int> &position, vector<int> &valocity)
{
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    ll n, i;
    cin >> n;
    vector<int> position(n), valocity(n);
    for (i = 0; i < n; i++)
        cin >> position[i] >> valocity[i];

    double lo = 0.0, hi = 1e10, mid;
    for (int i = 0; i <= 100; i++)
    {
        mid = (lo + hi) / 2.0;
        if (check(mid, position, valocity))
            hi = mid;
        else
            lo = mid;
    }

    return 0;
}