#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
void solution()
{
    ll length, windowSize, threshold;
    cin >> length >> windowSize >> threshold;
    vector<ll> arr(length), brr(windowSize);
    unordered_map<ll, ll> fr;
    for (int i = 0; i < length; i++)
        cin >> arr[i];
    for (int i = 0; i < windowSize; i++)
    {
        cin >> brr[i];
        fr[brr[i]]++;
    }
    multiset<ll> st;
    unordered_map<ll, ll> mp;
    ll ans = 0;
    for (int i = 0; i < windowSize; i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] <= fr[arr[i]])
            st.insert(arr[i]);
    }
    if (st.size() >= threshold)
        ans++;
    for (int i = 1; i + windowSize <= length; i++)
    {
        mp[arr[i - 1]]--;
        if (mp[arr[i - 1]] < fr[arr[i - 1]])
        {
            auto it = st.find(arr[i - 1]);
            st.erase(it);
        }
        mp[arr[i + windowSize - 1]]++;
        if (mp[arr[i + windowSize - 1]] <= fr[arr[i + windowSize - 1]])
            st.insert(arr[i + windowSize - 1]);
        if (st.size() >= threshold)
            ans++;
    }
    cout << ans << '\n';
}

int main()
{
    Faster;
    int testCases;
    cin >> testCases;
    while (testCases--)
        solution();
    return 0;
}
