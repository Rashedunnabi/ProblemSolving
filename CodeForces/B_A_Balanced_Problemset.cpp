#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

void solution()
{
    int sum, n, i;
    cin >> sum >> n;

    int ans = 0;
    for (i = 1; i * i <= sum; i++)
    {
        if (sum % i == 0)
        {
            int x = sum / i;

            if (x >= n)
                ans = max(ans, i);
            if (i >= n)
                ans = max(ans, x);
        }
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