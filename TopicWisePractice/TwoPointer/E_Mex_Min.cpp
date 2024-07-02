#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    set<int> all;
    for (int i = 0; i <= n; i++)
        all.insert(i);

    multiset<int> current;
    for (int i = 0; i < m; i++)
    {
        current.insert(a[i]);
        all.erase(a[i]);
    }

    int ans = *all.begin();

    for (int i = m; i < n; i++)
    {
        int prev = a[i - m];
        current.erase(current.find(prev));

        if (current.find(prev) == current.end())
            all.insert(prev);

        current.insert(a[i]);
        all.erase(a[i]);

        ans = min(ans, *all.begin());
    }

    cout << ans << endl;
}