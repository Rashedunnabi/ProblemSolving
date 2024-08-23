#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, fast1, last1, fast2, last2, fast3, last3, x;
        fast1 = fast2 = fast3 = -1;

        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (arr[i] == 1)
            {
                last1 = i;
                if (fast1 == -1)
                    fast1 = i;
            }
            else if (arr[i] == 2)
            {
                last2 = i;
                if (fast2 == -1)
                    fast2 = i;
            }
            else
            {
                last3 = i;
                if (fast3 == -1)
                    fast3 = i;
            }
        }

        auto func = [&](int fast, int last, int val) -> int
        {
            int cnt = 0;
            for (int i = fast; i <= last; i++)
            {
                if (arr[i] == val)
                    cnt++;
            }

            if (cnt)
                return 0;
            int a = 1, b = 1;
            for (int i = fast - 1; i >= 0; i--)
            {
                if (arr[i] == val)
                    break;
                a++;
            }
            for (int i = last + 1; i < n; i++)
            {
                if (arr[i] == val)
                    break;
                b++;
            }
            return a * b;
        };

        int total = 1LL * n * (n + 1) / 2;
        total -= func(fast1, last1, 3);
        total -= func(fast2, last2, 1);
        total -= func(fast3, last3, 2);
        cout << total << '\n';
    }
    return 0;
}
