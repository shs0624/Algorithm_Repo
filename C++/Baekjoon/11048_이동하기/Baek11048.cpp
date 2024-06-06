#include <iostream>
#include <queue>
using namespace std;

int N, M;
int dir[3][2] = { {1,0},{0,1} }; //대각선은, 오른쪽과 아래쪽으로 가는게 무조건 크니까 스킵
int maze[1001][1001];
int candy[1001][1001];
bool visit[1001][1001];
queue<pair<int, int>> q;

void BFS()
{
    q.push(make_pair(0, 0));
    candy[0][0] = maze[0][0];
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 2; i++)
        {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];

            
            if (dx < M && dy < N)
            {
                if (!visit[dy][dx])
                {
                    q.push(make_pair(dx, dy));
                    candy[dy][dx] = candy[y][x] + maze[dy][dx];
                    visit[dy][dx] = true;
                }
                else if (candy[dy][dx] < candy[y][x] + maze[dy][dx])
                {
                    q.push(make_pair(dx, dy));
                    candy[dy][dx] = candy[y][x] + maze[dy][dx];
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> maze[i][j];
        }
    }
    BFS();

    cout << candy[N - 1][M - 1] << endl;
}

