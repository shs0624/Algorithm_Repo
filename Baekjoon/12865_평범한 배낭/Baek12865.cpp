#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int dp[101][100001];

int main()
{
    int W, V;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> W >> V;
        for (int j = 1; j <= K; j++)
        {
            if (j < W) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j - W] + V);
        }
    }

    cout << dp[N][K] << endl;
}
