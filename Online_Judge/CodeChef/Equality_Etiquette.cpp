#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }

        int diff = abs(b - a);
        int ans = -1;

        int val = diff * 2;
        val = sqrt(val);

        for (int i = val; i <= val + 5; i++)
        {
            int curSum = i * (i + 1) / 2;
            int extra = curSum - diff;

            if (extra >= 0 && extra % 2 == 0)
            {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}