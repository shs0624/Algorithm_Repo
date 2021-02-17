#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

//https://yabmoons.tistory.com/125 보고 작성함
int W, H;
char board[101][101];
int visit[101][101];

int dir[4][2] = { {0,-1}, {1,0}, {0,1},{-1,0} };
queue<pair<int, int>> nodeQ;
queue<pair<pair<int,int>,pair<int,int>>> checkQ;

void Solution()
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            visit[i][j] = 987654321;
        }
    }
    pair<int, int> startPos = nodeQ.front();
    nodeQ.pop();
    pair<int, int> endPos = nodeQ.front();
    nodeQ.pop();

    for (int i = 0; i < 4; i++)
    {
        checkQ.push(make_pair(make_pair(startPos.first, startPos.second), make_pair(i, 0)));
    }
    visit[startPos.second][startPos.first] = 0;

    while (!checkQ.empty())
    {
        int px = checkQ.front().first.first;
        int py = checkQ.front().first.second;
        int pdir = checkQ.front().second.first;
        int cnt = checkQ.front().second.second;
        checkQ.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int nx = px + dir[i][0];
            int ny = py + dir[i][1];
            int nCnt = cnt;

            if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if (board[ny][nx] == '*') continue;

            if (i != pdir)
            {
                nCnt = nCnt + 1;
            }
            if (visit[ny][nx] >= nCnt)
            {
                visit[ny][nx] = nCnt;
                //여기선, 값이 더 작은 경우에만 Queue에 추가해줌.
                checkQ.push(make_pair(make_pair(nx, ny), make_pair(i, nCnt)));
            }
        }
    }

    cout << visit[endPos.second][endPos.first] << endl;
}

int main()
{
    cin >> W >> H;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'C') nodeQ.push(make_pair(j, i));
        }
    }
    Solution();
}
