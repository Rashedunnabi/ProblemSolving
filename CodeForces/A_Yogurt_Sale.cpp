#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, a, b, ans1, ans2;
        cin >> n >> a >> b;
        ans1 = (n * a);
        ans2 = (n % 2) * a + (n / 2) * b;
        cout << min(ans1, ans2) << '\n';
    }
    return 0;
}