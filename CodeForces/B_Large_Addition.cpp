#include <bits/stdc++.h>
using namespace std;
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

bool IsGood(ll n)
{
    while (n != 0)
    {
        ll rem = n % 10;
        n /= 10;
        if (rem < 5)
            return false;
    }
    return true;
}

int main()
{
    Faster;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll num;
        cin >> num;
        ll numA = 0, numB = 0, i = 0;
        bool flag = 0;

        while (num != 0)
        {
            ll rem = num % 10;
            if (rem == 9 || num < 10)
            {
                flag = true;
                break;
            }

            num -= 10;
            rem += 10;
            ll x = rem / 2, y = rem - x;

            y *= round(pow(10, i));
            x *= round(pow(10, i));
            numA += x, numB += y;

            i++;
            num /= 10;
        }
        if (flag || !IsGood(numA) || !IsGood(numB))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}