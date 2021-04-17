#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int dp[1001][1001];
//원래 해답보다 시간과 메모리 사용을 줄임

void Solution()
{
    for (int i = 1; i <= N; i++) // n*m
    {
        for (int j = 1; j <= M; j++)
        {
            dp[i][j] = max(dp[i - 1][j] + dp[i][j], dp[i][j - 1] + dp[i][j]);
        }
    }
    
    cout << dp[N][M] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> dp[i][j];
        }
    }

    Solution();
}
