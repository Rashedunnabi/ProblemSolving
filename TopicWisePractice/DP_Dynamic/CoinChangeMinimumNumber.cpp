#include <bits/stdc++.h>
using namespace std;

int dp[100005];
int func(vector<int> &v, int amount)
{
    if (amount == 0)
        return 0;
    int ans = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        if (amount - v[i] >= 0)
        {
            ans = min(ans, func(v, amount - v[i]) + 1);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, amount, i;
    cin >> n >> amount;

    vector<int> v(n);
    for (int &e : v)
        cin >> e;

    cout << func(v, amount) << '\n';

    return 0;
}