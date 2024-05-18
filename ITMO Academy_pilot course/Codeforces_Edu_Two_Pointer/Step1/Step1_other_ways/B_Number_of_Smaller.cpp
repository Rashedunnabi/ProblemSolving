#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, i;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;

    for (int &i : b)
    {
        int dis = lower_bound(a.begin(), a.end(), i) - a.begin();
        cout << dis << ' ';
    }
    cout << '\n';
    return 0;
}