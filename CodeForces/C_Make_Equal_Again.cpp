#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

void solution()
{
    ll n, fst = 0, lst = 0, ans = 0;
    cin >> n;

    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[0])
        {
            fst = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != arr[0])
        {
            lst = i;
            break;
        }
    }
    ans = lst - fst + 1;
    fst = lst = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[n - 1])
        {
            fst = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != arr[n - 1])
        {
            lst = i;
            break;
        }
    }
    ans = min(ans, lst - fst + 1);
    sort(arr, arr + n);
    if (arr[0] == arr[n - 1])
        ans = 0;
    cout << ans << endl;
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