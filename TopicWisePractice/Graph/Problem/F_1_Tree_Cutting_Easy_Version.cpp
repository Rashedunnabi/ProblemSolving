#include <bits/stdc++.h>
using namespace std;
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
const int N = 3e5 + 7;
int val[N], even[N], odd[N];
vector<int> graph[N];

void dfs(int vertex, int parent)
{
    even[vertex] += (val[vertex] == 2);
    odd[vertex] += (val[vertex] == 1);

    for (auto child : graph[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
        even[vertex] += even[child];
        odd[vertex] += odd[child];
    }
}

int main()
{
    Faster;
    int n, i;
    cin >> n;

    for (i = 1; i <= n; i++)
        cin >> val[i];
    for (i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1, 0);

    int ans = 0;

    for (i = 2; i <= n; i++)
    {
        int cur_even = even[i];
        int cur_odd = odd[i];
        int rem_even = even[1] - cur_even;
        int rem_odd = odd[1] - cur_odd;

        if (cur_even * cur_odd == 0 && rem_even * rem_odd == 0)
            ans++;
    }
    cout << ans << '\n';

    return 0;
}