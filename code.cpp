#include <bits/stdc++.h>
using namespace std;
#define ll long long

const double EPSILON = 1e-9;

bool check(double time, vector<int> &position, vector<int> &velocity)
{
    double mini = -1e12, maxi = 1e12;

    for (int i = 0; i < position.size(); i++)
    {
        double left = position[i] + velocity[i] * time;
        double right = position[i] - velocity[i] * time;
        mini = max(mini, right);
        maxi = min(maxi, left);
    }
    return mini < maxi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll n;
    cin >> n;
    vector<int> position(n), velocity(n);
    for (int i = 0; i < n; i++)
        cin >> position[i] >> velocity[i];

    double lo = 0.0, hi = 2e9;
    double result = -1.0;

    for (int i = 0; i < 100; i++)
    {
        double mid = (lo + hi) / 2.0;
        if (check(mid, position, velocity))
        {
            result = mid;
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    cout << fixed << setprecision(10) << result << '\n';
    return 0;
}
