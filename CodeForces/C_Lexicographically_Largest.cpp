#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

void solution()
{
    int n, i;
    cin >> n;
    vector<ll> arr(n);
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] += i + 1;
    }
    sort(arr.rbegin(), arr.rend());

    cout << arr[0] << ' ';
    for (i = 1; i < n; i++)
    {
        arr[i] = min(arr[i], arr[i - 1] - 1);
        cout << arr[i] << ' ';
    }
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