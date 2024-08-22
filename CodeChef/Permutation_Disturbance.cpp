#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        int cnt = 0;
        for (i = 0; i < n; i++)
        {
            if (v[i] == i + 1)
            {
                if (i < n - 1)
                    swap(v[i], v[i + 1]);
                else
                    swap(v[i], v[i - 1]);
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}