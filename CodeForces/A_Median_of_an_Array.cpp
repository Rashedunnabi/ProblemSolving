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
    int n, i, cnt = 0, minInd;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    sort(all(v));
    minInd = (n - 1) / 2;
    for (i = minInd; i < n; i++)
    {
        if (v[i] == v[minInd])
            cnt++;
    }
    cout << cnt << '\n';
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