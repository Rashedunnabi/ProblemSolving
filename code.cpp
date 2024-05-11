#include <iostream>
#include <cmath>

using namespace std;

int countLatticePoints(int r)
{
    int count = 0;
    for (int x = 0; x <= r + 1; ++x)
    {
        for (int y = 0; y <= r + 1; ++y)
        {
            if (x * x + y * y >= r * r && x * x + y * y < (r + 1) * (r + 1))
            {
                cout << x << ' ' << y << '\n';
                ++count;
            }
        }
    }
    return 4 * count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r;
        cin >> r;
        cout << countLatticePoints(r) << endl;
    }
    return 0;
}
