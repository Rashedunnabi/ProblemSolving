#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, n) for (int i = 0; i < n; i++)
#define F first
#define S second

struct Assistant
{
    int workTime, batchSize, refillTime;
};

// Calculate the maximum number of balloons that can be produced in given time
int maxBalloonsProduced(int workTime, int batchSize, int refillTime, int totalTime)
{
    int batchDuration = (batchSize * workTime) + refillTime;
    int batchCount = totalTime / batchDuration;
    int remainingTime = totalTime % batchDuration;
    int totalBalloons = batchCount * batchSize;
    if (remainingTime != 0)
    {
        if (remainingTime / workTime >= batchSize)
        {
            totalBalloons += batchSize;
        }
        else
        {
            totalBalloons += remainingTime / workTime;
        }
    }
    return totalBalloons;
}

// Check if producing given number of balloons is possible in given time
bool isBalloonProductionPossible(int workTime, int batchSize, int refillTime, int balloons, int totalTime)
{
    int batchDuration = (batchSize * workTime) + refillTime;
    int batches = balloons / batchSize;
    bool ok = (balloons % batchSize == 0) ? 1 : 0;
    int currentTime = 0;
    if (ok)
    {
        batches -= 1;
        currentTime = (batchDuration * batches) + (batchSize * workTime);
    }
    else
    {
        currentTime = (batchDuration * batches) + ((balloons % batchSize) * workTime);
    }
    return (currentTime <= totalTime);
}

// Check if producing required number of balloons is possible by all assistants in given time
bool isProductionPossible(Assistant *assistants, int numAssistants, int requiredBalloons, int totalTime)
{
    int totalBalloons = 0;
    FOR(i, numAssistants)
    {
        int workTime = assistants[i].workTime;
        int batchSize = assistants[i].batchSize;
        int refillTime = assistants[i].refillTime;
        int lo = 0, hi = (int)1e9;
        while (hi > lo + 1)
        {
            int balloons = (lo + hi) >> 1;
            if (isBalloonProductionPossible(workTime, batchSize, refillTime, balloons, totalTime))
            {
                lo = balloons;
            }
            else
            {
                hi = balloons;
            }
        }
        totalBalloons += lo;
    }
    return (totalBalloons >= requiredBalloons);
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int requiredBalloons, numAssistants;
    cin >> requiredBalloons >> numAssistants;
    Assistant assistants[numAssistants];
    FOR(i, numAssistants)
    {
        cin >> assistants[i].workTime >> assistants[i].batchSize >> assistants[i].refillTime;
    }
    int minTime = -1, maxTime = (int)1e9;
    while (maxTime > minTime + 1)
    {
        int totalTime = (minTime + maxTime) >> 1;
        if (isProductionPossible(assistants, numAssistants, requiredBalloons, totalTime))
        {
            maxTime = totalTime;
        }
        else
        {
            minTime = totalTime;
        }
    }
    cout << maxTime << '\n';
    int balloonsProduced[numAssistants];
    memset(balloonsProduced, 0, sizeof balloonsProduced);
    FOR(i, numAssistants)
    {
        int workTime = assistants[i].workTime;
        int batchSize = assistants[i].batchSize;
        int refillTime = assistants[i].refillTime;
        balloonsProduced[i] = maxBalloonsProduced(workTime, batchSize, refillTime, maxTime);
    }
    int totalBalloons = 0;
    FOR(i, numAssistants)
    {
        if (totalBalloons + balloonsProduced[i] <= requiredBalloons)
        {
            cout << balloonsProduced[i] << " ";
            totalBalloons += balloonsProduced[i];
        }
        else
        {
            if (totalBalloons == requiredBalloons)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << (requiredBalloons - totalBalloons) << " ";
                totalBalloons = requiredBalloons;
            }
        }
    }
    cout << '\n';
    return 0;
}
