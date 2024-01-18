#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define all(v) v.begin(), v.end()

int main()
{
    Faster;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x = rand() % 20;
        int y = rand() % 20;
        cout << x << ' ' << y << '\n';
    }

    return 0;
}