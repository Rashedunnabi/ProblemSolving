#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

void selectionSort(vector<int> &arr)
{
    int size = arr.size();

    for (int step = 0; step <= 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {
            if (arr[i] < arr[min_idx])
                min_idx = i;
        }
        swap(arr[min_idx], arr[step]);
    }
}

bool check(vector<int> &ar, int mid)
{
    vector<int> v = ar;
    for (int i = 0, c = 0; i < v.size() && c < mid; i++, c++)
        v[i] = v.back();
    selectionSort(v);
    return v[0] + v[1] > v.back();
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> ar(n);
        for (auto &i : ar)
            cin >> i;
        sort(all(ar));
        int lo = -1, hi = n + 1;
        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(ar, mid))
                hi = mid;
            else
                lo = mid;
        }
        cout << hi << '\n';
    }
    return 0;
}