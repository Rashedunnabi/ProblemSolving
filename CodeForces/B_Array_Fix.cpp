#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solution()
{
    int n, i;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    bool flag = 0;
    int prev = v[n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        if (v[i] <= prev)
            prev = v[i];
        else
        {
            int a = v[i] / 10;
            int b = v[i] % 10;
            if (a <= b && b <= prev)
            {
                prev = a;
            }
            else
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