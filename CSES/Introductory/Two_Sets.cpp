#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    set<int> s1, s2;
    int n, i, sum1 = 0, sum2 = 0, temp;
    cin >> n;

    temp = n;
    if (n & 1)
        temp = n - 1;

    for (i = 1; i <= (n / 2); i++)
    {
        if (i & 1)
        {
            sum1 += i + temp - i + 1;
            s1.insert(i);
            s1.insert(temp - i + 1);
        }
        else
        {
            sum2 += i + temp - i + 1;
            s2.insert(i);
            s2.insert(temp - i + 1);
        }
    }

    if (n & 1)
        s2.insert(n), sum2 += n;

    if (sum1 != sum2)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    cout << s1.size() << endl;

    for (auto val : s1)
        cout << val << " ";
    cout << "\n";

    cout << s2.size() << endl;
    for (auto val : s2)
        cout << val << " ";
    cout << "\n";

    return 0;
}