#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<pair<int, int>> intervals;
    int n, maxi = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        intervals.push_back({x, y});
        maxi = max(maxi, max(x, y));
    }

    vector<int> diff(maxi + 1, 0); // Difference array
    // Processing the intervals
    for (const auto &interval : intervals)
    {
        int l = interval.first - 1; // Convert to 0-based index
        int r = interval.second - 1;
        int value = r - l + 1;

        // Mark the start and end of the range in the difference array
        diff[l] = max(diff[l], value); // Update start of range
        if (r + 1 < maxi)
        {
            diff[r + 1] = max(diff[r + 1], 0); // Update after the range to stop the effect
        }
    }

    // Create final array by applying prefix max
    vector<int> ar(maxi, 0);
    ar[0] = diff[0];
    for (int i = 1; i < maxi; i++)
    {
        ar[i] = max(ar[i - 1], diff[i]); // Prefix max to propagate maximum values
    }

    // Output the result
    for (int i = 0; i < maxi; i++)
    {
        cout << ar[i] << ' ';
    }
    cout << '\n';

    return 0;
}
