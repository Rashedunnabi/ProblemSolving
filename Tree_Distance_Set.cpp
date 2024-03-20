#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 2005;

vector<int> tree[MAX_N];
int color[MAX_N];
int redCount, blueCount;

// Function to perform DFS traversal and calculate S1 and S2
void dfs(int node, int parent, int distance, int colorParent)
{
    if (colorParent == 1)
        redCount++;
    else
        blueCount++;

    for (int child : tree[node])
    {
        if (child != parent)
        {
            if (colorParent == 1)
                color[child] = (distance % 2 == 0) ? 1 : 2;
            else
                color[child] = (distance % 2 == 0) ? 2 : 1;
            dfs(child, node, distance + 1, color[child]);
        }
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        // Clearing the tree and color arrays for each test case
        for (int i = 1; i <= N; ++i)
        {
            tree[i].clear();
            color[i] = 0;
        }

        // Reading edges of the tree
        for (int i = 0; i < N - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        // Initialize coloring
        color[1] = 1; // Assign arbitrary color to the root node
        redCount = 1;
        blueCount = 0;
        dfs(1, -1, 0, 1); // Perform DFS traversal to calculate S1 and S2

        // Ensure that S1 = S2 by adjusting colors if needed
        if (redCount != blueCount)
        {
            for (int i = 1; i <= N; ++i)
            {
                if (color[i] == 1 && redCount > blueCount && redCount - blueCount > 1)
                {
                    color[i] = 2;
                    break;
                }
                if (color[i] == 2 && blueCount > redCount && blueCount - redCount > 1)
                {
                    color[i] = 1;
                    break;
                }
            }
        }

        // Output the colors
        for (int i = 1; i <= N; ++i)
        {
            if (color[i] == 1)
                cout << "R";
            else
                cout << "B";
        }
        cout << endl;
    }

    return 0;
}
