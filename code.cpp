#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"


void solution()
{
    int n, i;
    cin >> n;

    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    vector<int> v;
    map<int, int> mp;

    for (i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto val : mp)
    {
        cout << val.first << ' ' << val.second << '\n';
        v.push_back(val.first);
    }

    int ans = 0;
    for (i = 0; i < v.size(); i++)
    {
        int x = mp[v[i]];
        if (x > 1)
        {
            v[i] = (x * 1LL * (x - 1) / 2);
            cout << x << ' ' << v[i] << endl;
        }
    }

    cout << "Vector:\n";
    for (int &i : v)
        cout << i << ' ';
    cout << '\n';

    vector<int> pre(n);
    pre[0] = v[0];
    for (i = 1; i < n; i++)
        pre[i] = pre[i - 1] + v[i];

    cout << "Presum: \n";
    for (int &i : pre)
        cout << i << ' ';
    cout << '\n'
         << endl;
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