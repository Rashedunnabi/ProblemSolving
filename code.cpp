#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti += 1)
    {
        int n, k;
        cin >> n >> k;
        vector<int> p(n + 1);
        for (int i = 1, l = 1, r = n; i <= k; i += 1)
        {
            for (int j = i; j <= n; j += k)
            {
                p[j] = i % 2 ? l++ : r--;
            }
        }
        for (int i = 1; i <= n; i += 1)
        {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
}