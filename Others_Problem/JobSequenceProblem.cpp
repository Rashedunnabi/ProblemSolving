#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

class Solution
{
public:
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, [&](Job a, Job b)
             { return a.profit > b.profit; });

        int maxDeadline = 0;
        for (int i = 0; i < n; i++)
            maxDeadline = max(maxDeadline, arr[i].dead);

        vector<int> slots(maxDeadline + 1, -1);
        int maxProfit = 0, jobCount = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slots[j] == -1)
                {
                    slots[j] = arr[i].id;
                    maxProfit += arr[i].profit;
                    jobCount++;
                    break;
                }
            }
        }
        return {jobCount, maxProfit};
    }
};

int main()
{
    int n;
    cin >> n;
    Job arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i].id >> arr[i].dead >> arr[i].profit;

    Solution ob;
    vector<int> result = ob.JobScheduling(arr, n);

    cout << result[0] << " " << result[1] << "\n";

    return 0;
}
