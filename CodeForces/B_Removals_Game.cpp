#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;

        bool flag = (a == b);
        reverse(b.begin(), b.end());
        flag |= (a == b);
        cout << (flag ? "Bob\n" : "Alice\n");
    }
    return 0;
}