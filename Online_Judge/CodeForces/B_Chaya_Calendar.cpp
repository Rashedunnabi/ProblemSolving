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
    int n, i, c = 0, cc = 0;
    cin >> n;

    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;

    for (i = 1; i < n; i++)
    {
        c = 2, cc = arr[i];
        while (arr[i] <= arr[i - 1])
        {

            arr[i] = c * cc, c++;
        }
    }

    // for (i = 0; i < n; i++)
    //     cout << arr[i] << ' ';
    // cout << '\n';

    if (n == 1)
        cout << arr[0] << '\n';
    else
        cout << arr[n - 1] << endl;
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