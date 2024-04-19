#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()

void solution()
{
    int n, c, d, i, j, x;
    cin >> n >> c >> d;

    vector<int> arr, v;
    int sz = n * n;
    for (i = 0; i < sz; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    int mini = *min_element(all(arr));
    v.push_back(mini);
    for (int i = 0; i < n - 1; i++)
    {
        x = v.back();
        v.push_back(x + d);
    }

    vector<int> vans = v;
    for (int i = 0; i < n; i++)
    {
        x = v[i];
        for (int j = 0; j < n - 1; j++)
        {
            x += c;
            vans.push_back(x);
        }
    }

    sort(vans.begin(), vans.end());
    sort(arr.begin(), arr.end());

    bool flag = 0;
    for (int i = 0; i < (n * n); i++)
    {
        if (arr[i] != vans[i])
        {
            flag = 1;
        }
    }
    if (flag)
        no;
    else
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