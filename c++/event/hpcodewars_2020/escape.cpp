#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = i + 1; k < j; k++)
            {
                if (dp[i][j] != 0)
                    int temp = dp[i][k - 1] + dp[k + 1][j] + k;
            }
        }
    }
}
