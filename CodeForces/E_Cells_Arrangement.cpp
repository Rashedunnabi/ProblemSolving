#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

void solution()
{
    int n;
    cin >> n;

    cout << "1 1\n";
    cout << n << ' ' << n << '\n';
    n -= 2;
    if (n)
    {
        cout << "1 2\n";
        n--;
    }

    for (int i = 3; n; i++, n--)
        cout << i << ' ' << 1 << '\n';

    cout << '\n';
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}