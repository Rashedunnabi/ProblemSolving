#include <bits/stdc++.h>
using namespace std;
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
const int N = 2e5 + 7;
int arr[N];
void solution()
{
    int n, i, ans = 0, gc = 0;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> arr[i];

    for (i = 1; i <= n; i++)
    {
        if (n % i != 0)
            continue;
        gc = 0;
        for (int j = 0; j + i < n; j++)
        {
            gc = __gcd(gc, abs(arr[j] - arr[j + i]));
        }
        if (gc != 1)
            ans++;
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