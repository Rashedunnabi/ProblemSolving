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
    int a, b;
    string s;
    cin >> s;
    a = b = 0;
    for (int i = 0; i < 5; i++)
    {
        if (s[i] == 'A')
            a++;
        else
            b++;
    }
    if (a > b)
        cout << "A\n";
    else
        cout << "B\n";
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