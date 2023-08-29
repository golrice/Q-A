#include <vector>

using namespace std;

int getMaxValue(int **graph, int length, int weight)
{
    if (length == 0 && weight == 0)
        return graph[0][0];
    else if (length == 0)
        return getMaxValue(graph, 0, weight - 1) + graph[0][weight];
    else if (weight == 0)
        return getMaxValue(graph, length - 1, 0) + graph[length][0];
    else
        return max(getMaxValue(graph, length - 1, weight), getMaxValue(graph, length, weight - 1)) + graph[length][weight];
}

int getMaxValue_l(int **graph, int length, int weight)
{
    vector<vector<int>> dp(weight, vector<int>(length, 0));
    dp[0][0] = graph[0][0];
    for (int i = 1; i < length; i++)
        dp[i][0] = dp[i - 1][0] + graph[i][0];
    for (int i = 1; i < weight; i++)
        dp[0][i] = dp[0][i - 1] + graph[0][i];

    for (int i = 1; i < weight; i++)
    {
        for (int j = 1; j < length; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + graph[i][j];
    }
    return dp[weight - 1][length - 1];
}