#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        n = (n < k) ? n : k;
        m = (m < k) ? m : k;
        cout << (n * m) << '\n';
    }
    return 0;
}