#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

int N, L, R;
int arr[51][51];
bool visit[51][51];
bool moved = true;

int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
queue<pair<int, int>> searchQ;
queue<pair<int, int>> unionQ;

void BFS(int x, int y)
{
    visit[x][y] = true;
    searchQ.push(make_pair(x, y));
    unionQ.push(make_pair(x, y));
    int sum = 0;
    int cnt = 0;

    while (!searchQ.empty())
    {
        int nx = searchQ.front().first;
        int ny = searchQ.front().second;
        searchQ.pop();
        sum += arr[nx][ny];
        cnt++;

        for (int i = 0; i < 4; i++)
        {
            int dx = nx + dir[i][0];
            int dy = ny + dir[i][1];

            if (dx <= 0 || dx > N || dy <= 0 || dy > N) continue;
            if (visit[dx][dy]) continue;

            int dif = abs(arr[nx][ny] - arr[dx][dy]);
            if (dif >= L && dif <= R)
            {
                visit[dx][dy] = true;
                searchQ.push(make_pair(dx, dy));
                unionQ.push(make_pair(dx, dy));
            }
        }
    }

    int num = sum / cnt;
    if (unionQ.size() != 1) moved = true;
    while (!unionQ.empty())
    {
        arr[unionQ.front().first][unionQ.front().second] = num;
        unionQ.pop();
    }
}

void Solution()
{
    int cnt = 0;
    moved = true;
    while (moved)
    {
        moved = false;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (visit[i][j])
                    continue;
                BFS(i,j);
            }
        }

        if (moved) cnt++;
        memset(visit, false, sizeof(visit));
    }

    cout << cnt << endl;
}

// 어느나라들이 연맹으로 묶여있는가?
// 묶인 나라들의 인구 합과 연합을 이룬 나라의 개수는?

int main()
{
    cin >> N >> L >> R;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }
    Solution();
}
