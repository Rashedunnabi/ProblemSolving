#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> &a)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < a.size(); i++)
    {
        max_ending_here = max_ending_here + a[i];
        // If max_ending_here becomes more than
        // the current result
        max_so_far = max(max_so_far, max_ending_here);
        // If max_ending_here becomes negative
        max_ending_here = max(max_ending_here, 0);
    }
    return max_so_far;
}

// Driver Code
int main()
{
    int n, i;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    cout << maxSubArraySum(v) << '\n';
    return 0;
}
