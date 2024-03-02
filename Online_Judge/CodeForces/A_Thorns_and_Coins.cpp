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
    int n, i, ans = 0;
    cin >> n;
    char arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    for (i = 0; i < n; i++)
    {
        if (i + 2 < n && arr[i + 2] == '*' && arr[i + 1] == '*')
        {
            if (arr[i] == '@')
                ans++;
            break;
        }
        if (arr[i] == '@')
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