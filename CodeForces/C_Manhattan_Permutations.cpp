#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        ll n, k, maxSum = 0;
        cin >> n >> k;

        for (int i = 1, j = n; i <= n; i++, j--)
            maxSum += abs(i - j);

        if (k & 1 || k > maxSum)
            cout << "No\n";
        else
        {
            cout << "Yes\n";
            vector<int> p(n + 1);
            for (int i = 1; i <= n; i++)
                p[i] = i;
            for (int i = 1, j = n; i <= (n + 1 / 2); i++, j--)
            {
                int value = abs(i - j) * 2;
                if (k == 2)
                {
                    swap(p[i], p[i + 1]);
                    break;
                }
                if (k >= value)
                {
                    swap(p[i], p[j]);
                    k -= value;
                }
                else
                {
                    swap(p[i], p[i + k]);
                    break;
                }
            }
            for (int i = 1; i <= n; i++)
                cout << p[i] << ' ';
            cout << '\n';
        }
    }
    return 0;
}
