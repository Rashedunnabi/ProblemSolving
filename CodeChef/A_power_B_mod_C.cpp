#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test_cases;
    cin >> test_cases;

    for (int t = 0; t < test_cases; ++t)
    {
        long long A;
        cin >> A;

        long long B = 2 * A, C = A * A;
        if (A == 2)
            B = 4, C = 8;
        cout << B << " " << C << endl;
    }

    return 0;
}
