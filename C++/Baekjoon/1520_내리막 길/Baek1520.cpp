#include <iostream>
using namespace std;

int N, M;
int board[501][501];
int dp[501][501];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int DFS(int x, int y)
{
    if (x == (N - 1) && y == (M - 1))
    {
        return 1;
    }
    else if (dp[y][x] == -1)
    {
        dp[y][x] = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (board[ny][nx] >= board[y][x]) continue;

            dp[y][x] += DFS(nx, ny);
        }
    }

    return dp[y][x];
}

void Solution()
{
    cout << DFS(0, 0) << endl;

    cout << endl;
}

int main()
{
    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            dp[i][j] = -1;
        }
    }
    Solution();
}
