#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string x, y;
        cin >> x >> y;

        vector<pair<char, char>> pairs;

        // Finding pairs to swap
        for (int i = 0; i < x.size(); ++i)
        {
            if (x[i] < y[i])
            {
                pairs.push_back({x[i], y[i]});
            }
        }

        // Sorting the pairs in descending order based on second element
        sort(pairs.rbegin(), pairs.rend());

        // Swapping elements in x and y
        for (auto p : pairs)
        {
            for (int i = 0; i < x.size(); ++i)
            {
                if (x[i] == p.first && y[i] == p.second)
                {
                    swap(x[i], y[i]);
                    break;
                }
            }
        }

        cout << x << endl
             << y << endl;
    }

    return 0;
}
