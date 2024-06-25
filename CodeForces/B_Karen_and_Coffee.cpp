#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200010;
int ar[N], ans[N];

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ar[a]++;
        ar[b + 1]--;
    }

    for (int i = 1; i <= N; i++)
        ar[i] += ar[i - 1];

    for (int i = 1; i <= N; i++)
        ans[i] = (ar[i] >= k) + ans[i - 1];

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        int x = ans[b] - ans[a - 1];
        cout << x << '\n';
    }
    return 0;
}