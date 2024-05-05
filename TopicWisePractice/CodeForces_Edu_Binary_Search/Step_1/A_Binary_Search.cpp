#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, q, i;
    cin >> n >> q;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    while (q--)
    {
        int x;
        cin >> x;

        int lo = 0, hi = n, mid;
        while (hi - lo > 1)
        {
            mid = (lo + hi) / 2;
            if (v[mid] > x)
                hi = mid;
            else
                lo = mid;
        }
        if (v[lo] == x)
            cout << "YES\n";
        else
            cout << "NO\n";

        /*
        find in vector--worst case O(n)
        find in set--worst case O(logN)


        so we can take the input in a set and perform the find function it gives us the ans
        cout<<((s.find(x)!=s.end())?"YES\n":"NO\n");
        */
    }
    return 0;
}