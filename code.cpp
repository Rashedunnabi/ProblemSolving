#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestMountain(int *arr, int n)
    {
        int i = 0, ans = 0;
        while (i < n)
        {
            int pre = i, c1 = 0, c2 = 0;
            while (i + 1 < n && arr[i + 1] > arr[i])
                i++, c1 = 1;
            while (i + 1 < n && arr[i] > arr[i + 1])
                i++, c2 = 1;
            if (c1 + c2 == 2)
                ans = max(ans, i - pre + 1);
            if (i == pre)
                i++;
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.longestMountain(arr, n) << '\n';
    }
    return 0;
}