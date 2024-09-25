#include <bits/stdc++.h>
using namespace std;

string solve(int A)
{
    if (A == 0 || A == 1)
        return "1";

    vector<int> result;
    result.push_back(1);

    for (int i = 2; i <= A; ++i)
    {
        int carry = 0;
        for (int j = 0; j < result.size(); ++j)
        {
            int product = result[j] * i + carry;
            result[j] = product % 10;
            carry = product / 10;
        }

        while (carry)
        {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    string factorial = "";
    for (int i = result.size() - 1; i >= 0; --i)
        factorial += to_string(result[i]);

    return factorial;
}

int32_t main()
{
    int n;
    cin >> n;

    cout << solve(n) << '\n';
    return 0;
}
