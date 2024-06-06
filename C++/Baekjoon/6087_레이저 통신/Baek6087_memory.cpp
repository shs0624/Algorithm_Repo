#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

//메모리 초과 - 과도한 중복 호출때문인지 잘 이해가 아직 안됨
struct Node {
    int x;
    int y;
    int dir;
};

//enum DIR { N, E, S, W };
int W, H;
char board[101][101];
bool visit[101][101];
int mirCount[101][101];
int dir[4][2] = { {0,-1}, {1,0}, {0,1},{-1,0} };
queue<pair<int, int>> nodeQ;
queue<Node> checkQ;

void Solution()
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            mirCount[i][j] = 987654321;
            visit[i][j] = false;
        }
    }
    pair<int, int> startPos = nodeQ.front();
    nodeQ.pop();
    pair<int, int> endPos = nodeQ.front();
    nodeQ.pop();

    checkQ.push({ startPos.first, startPos.second, 0 });
    checkQ.push({ startPos.first, startPos.second, 2 });
    checkQ.push({ startPos.first, startPos.second, 1 });
    checkQ.push({ startPos.first, startPos.second, 3 });
    mirCount[startPos.second][startPos.first] = 0;
    visit[startPos.second][startPos.first] = true;

    while (!checkQ.empty())
    {
        int px = checkQ.front().x;
        int py = checkQ.front().y;
        int pdir = checkQ.front().dir;
        visit[py][px] = true;
        checkQ.pop();
        
        if (py == endPos.second && px == endPos.first)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nx = px + dir[i][0];
            int ny = py + dir[i][1];

            if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if (visit[ny][nx]) continue;
            if (board[ny][nx] == '*') continue;

            if (i != pdir)
            {
                mirCount[ny][nx] = min(mirCount[ny][nx], mirCount[py][px] + 1);
            }
            else
            {
                mirCount[ny][nx] = min(mirCount[ny][nx], mirCount[py][px]);
            }

            checkQ.push({ nx, ny, i });
        }
    }

    cout << mirCount[endPos.second][endPos.first] << endl;
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
