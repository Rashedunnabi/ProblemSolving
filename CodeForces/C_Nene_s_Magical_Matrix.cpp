#include <bits/stdc++.h>
using namespace std;
#define ll long long

void printVector(int n)
{
    for (int i = 1; i <= n; i++)
        cout << i << ' ';
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i, c = 1;
        cin >> n;
        ll sum = 0;
        for (i = 1; i <= n; i++)
        {
            sum += (c * i);
            c += 2;
        }
        cout << sum << ' ' << (2 * n) << '\n';
        for (i = n; i >= 1; i--)
        {
            cout << 1 << ' ' << i << ' ';
            printVector(n);
            cout << 2 << ' ' << i << ' ';
            printVector(n);
        }
    }
    return 0;
}