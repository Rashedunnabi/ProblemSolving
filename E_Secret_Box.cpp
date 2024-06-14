#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

// Function to calculate the maximum number of distinct placements of box S inside box B
int calculateMaxPlacements(int x, int y, int z, int k)
{
    int max_placements = 0;
    for (int length = 1; length <= x; ++length)
    {
        for (int weight = 1; weight <= y; ++weight)
        {
            if (k % (length * 1LL * weight) != 0)
                continue;

            int height = k / (length * 1LL * weight);
            if (height > z)
                continue;

            int placements_z = z + 1 - height, placements_y = y + 1 - weight, placements_x = x + 1 - length;
            int newVolume = placements_z * 1LL * placements_y * placements_x;
            max_placements = max(max_placements, newVolume);
        }
    }
    return max_placements;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int x, y, z, k;
        cin >> x >> y >> z >> k;
        int result = calculateMaxPlacements(x, y, z, k);
        cout << result << endl;
    }
    return 0;
}
