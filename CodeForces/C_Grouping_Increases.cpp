#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int mod = 1e9 + 7;
const int N = 2e5 + 7;

void solution()
{
    int n, i;
    cin >> n;

    int a, b, ans = 0;
    a = b = 1e7;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (a > b)
            swap(a, b);

        if (x <= a)
            a = x;
        else if (x <= b)
            b = x;
        else
            a = x, ans++;
    }
    cout << ans << '\n';
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