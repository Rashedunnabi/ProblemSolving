
#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define all(v) v.begin(), v.end()

int func(vector<int> &v, int element)
{
    reverse(all(v));

    int cnt = 0;
    while (v.size() > 1)
    {
        int last1 = v.back();
        v.pop_back();
        int last2 = v.back();
        v.pop_back();
        int maxi = max(last1, last2);
        if (maxi > element)
            break;
        if (maxi == element)
            cnt++;
        v.push_back(maxi);
    }
    return cnt;
}

void solution()
{
    int n, k, i;
    cin >> n >> k;
    vector<int> v(n), arr;
    for (int &i : v)
        cin >> i;

    arr = v;

    int ind = -1, element = v[k - 1];

    k--;
    for (i = 0; i < n; i++)
    {
        if (v[i] > v[k])
        {
            ind = i;
            break;
        }
    }

    if (ind == -1)
    {
        cout << n - 1 << '\n';
        return;
    }

    swap(v[k], v[ind]);
    int ans = func(v, element);
    swap(arr[0], arr[k]);
    ans = max(ans, func(arr, element));
    cout << ans << '\n';
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}