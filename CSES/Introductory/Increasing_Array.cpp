#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, i, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &e : v)
        cin >> e;

    for (i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1])
        {
            ans += abs(v[i] - v[i - 1]);
            v[i] = v[i - 1];
        }
    }
    cout << ans << endl;
    return 0;
}