#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 지나간 방도 다시 돌아가며 불을 키러 다녀야 한다.
// 이 점을 놓쳐서 나중에 bfs를 반복하는 방식으로 변경
// 참고 : https://ijsilver.tistory.com/27
struct node {
    int x;
    int y;
};

int n, m;
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
bool roomslight[101][101];
bool visit[101][101];
vector<node> board[101][101];

void solution()
{
    int cnt = 0;

    while (1)
    {
        memset(visit, false, sizeof(visit));
        queue<node> checkq;
        roomslight[0][0] = true;
        visit[0][0] = true;
        checkq.push({ 0,0 });
        bool lightup = false;

        while (!checkq.empty())
        {
            int x = checkq.front().x;
            int y = checkq.front().y;
            checkq.pop();
            if (!board[y][x].empty())
            {
                for (int i = 0; i < board[y][x].size(); i++)
                {
                    auto a = board[y][x][i];
                    roomslight[a.y][a.x] = true;
                }
                board[y][x].clear();
                lightup = true;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                {
                    if (roomslight[ny][nx] && !visit[ny][nx])
                    {
                        checkq.push({ nx,ny });
                        visit[ny][nx] = true;
                    }
                }
            }
        }
        if (!lightup) break;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (roomslight[i][j])
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

int main()
{
    int x, y, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> a >> b;
        board[y - 1][x - 1].push_back({ a - 1, b - 1 });
    }
    solution();
}
