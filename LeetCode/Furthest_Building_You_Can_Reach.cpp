#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // paste code here
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int i = 0, n = heights.size();
        priority_queue<int> pq;

        for (i = 0; i < n - 1; i++)
        {
            if (heights[i] >= heights[i + 1])
                continue;

            int dif = heights[i + 1] - heights[i];
            if (bricks >= dif)
            {
                bricks -= dif;
                pq.push(dif);
            }
            else
            {
                if (ladders <= 0)
                    break;

                if (!pq.empty() && pq.top() > dif)
                {
                    bricks += pq.top() - dif;
                    pq.pop();
                    pq.push(dif);
                }
                ladders--;
            }
        }
        return i;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, b, l;
        cin >> n >> b >> l;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.furthestBuilding(arr, b, l);
    }
    return 0;
}