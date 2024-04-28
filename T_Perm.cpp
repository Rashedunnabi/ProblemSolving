#include <iostream>

using namespace std;

int main()
{

    int t;

    cin >> t;

    while (t--)

    {

        int n;

        cin >> n;

        if (n % 3 == 0)
        {

            for (int i = 1; i <= n; i += 3)
            {

                cout << i << " " << (i + 2) << " " << (i + 1) << " ";
            }

            cout << "\n";

            continue;
        }

        if (n % 3 == 1)
        {

            for (int i = 1; i <= n - 4; i += 3)
            {

                cout << i << " " << (i + 2) << " " << (i + 1) << " ";
            }

            cout << n << " " << (n - 1) << " " << (n - 2) << " " << (n - 3);

            cout << "\n";

            continue;
        }

        cout << "4 5 2 1 3 ";

        for (int i = 6; i <= n; i += 3)
        {

            cout << (i + 2) << " " << (i + 1) << " " << i << " ";
        }

        cout << "\n";
    }

    return 0;
}
