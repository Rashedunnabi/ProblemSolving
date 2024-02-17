#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solution()
{
    ll i, n, rem = 0, need = 0, sum = 0;
    cin >> n;
    vector<ll> arr(n);
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    need = sum / n;

    for (i = 0; i < n; i++)
    {
        if (arr[i] > need)
        {
            rem += (arr[i] - need);
        }
        if (arr[i] < need)
        {
            rem -= (need - arr[i]);
            if (rem < 0)
            {
                no;
                return;
            }
        }
    }
    yes;
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