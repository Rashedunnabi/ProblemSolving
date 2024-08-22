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
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    int mini = *min_element(all(v));
    int maxi = *max_element(all(v));
    if (mini == 0 && maxi == 0)
    {
        yes;
        return;
    }

    for (i = 0; i < n - 2; i++)
    {
        int x = v[i];
        v[i] -= x;
        v[i + 2] -= x;
        v[i + 1] -= (x + x);

        if (v[i] < 0 || v[i + 2] < 0 || v[i + 1] < 0)
        {
            no;
            return;
        }
    }
    mini = *min_element(all(v));
    maxi = *max_element(all(v));
    if (mini == 0 && maxi == 0)
        yes;
    else
        no;
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