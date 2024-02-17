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
    ll n, i;
    cin >> n;
    ll arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    ll sum = 0;
    for (i = 1; i < n; i++)
    {
        sum += (arr[i] - arr[i - 1]);
    }
    cout << sum << '\n';
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