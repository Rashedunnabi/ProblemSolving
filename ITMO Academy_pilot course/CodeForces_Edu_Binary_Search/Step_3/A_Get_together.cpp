#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(double time, vector<int> &position, vector<int> &valocity)
{
    double mini = -1e12, maxi = 1e12;
    for (int i = 0; i < position.size(); i++)
    {
        double right = position[i] + valocity[i] * time;
        double left = position[i] - valocity[i] * time;
        mini = max(mini, left);
        maxi = min(maxi, right);
    }
    return mini < maxi;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    ll n, i;
    cin >> n;
    vector<int> position(n), valocity(n);
    for (i = 0; i < n; i++)
        cin >> position[i] >> valocity[i];

    double lo = 0.0, hi = 2e9 + 100, mid;
    for (int i = 0; i <= 100; i++)
    {
        mid = (lo + hi) / 2.0;
        if (check(mid, position, valocity))
            hi = mid;
        else
            lo = mid;
    }
    cout << fixed << setprecision(10) << hi << '\n';

    return 0;
}