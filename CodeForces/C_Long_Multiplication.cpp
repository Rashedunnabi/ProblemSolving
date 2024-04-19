// 9876543210...???
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl "\n"

long long power(long long A, long long B)
{
    if (B == 0)
        return 1;
    long long ress = power(A, B / 2);
    if (B % 2)
        return ress * ress * A;
    else
        return ress * ress;
}

void primeFactors(ll ww)
{
    while (ww % 2 == 0)
    {
        ww = ww / 2;
    }
    for (ll ii = 3; ii <= sqrt(ww); ii = ii + 2)
    {
        while (ww % ii == 0)
        {
            ww = ww / ii;
        }
    }
}

void solve()
{
    string str1, str2;
    cin >> str1 >> str2;
    if (str1 < str2)
        swap(str1, str2);

    bool flag = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] > str2[i] && flag)
            swap(str1[i], str2[i]);
        if (str1[i] != str2[i])
            flag = 1;
    }
    cout << str1 << '\n'
         << str2 << endl;
}

int main()
{

    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
