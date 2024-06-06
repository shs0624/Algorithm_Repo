#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// 이동전에 부딪혀도 충돌로 인지하는거 고치기
string s;
int R, C, X;
int dir[9][2] = { {-1,1}, {0,1}, {1,1}, {-1, 0}, {0,0}, {1,0}, {-1, -1}, {0, -1}, {1,-1} };
char board[101][101];
int cntBoard[101][101];
bool boomCheck[101][101];

bool isAttacked = false;
queue<pair<int, int>> Rqueue;
queue<pair<int, int>> bombQ;
pair<int, int> myPos;

void Solution()
{
    for (int i = 0; i < s.size(); i++)
    {
        int num = s[i];
        int dx = myPos.first + dir[(int)s[i] - '0' - 1][0];
        int dy = myPos.second + dir[(int)s[i] - '0' - 1][1];

        if (board[dy][dx] == 'R')
        {
            X = i + 1;
            isAttacked = true;
            return;
        }

        board[myPos.second][myPos.first] = '.';
        board[dy][dx] = 'I';
        myPos = make_pair(dx, dy);

        int idx = Rqueue.size();
        for (int j = 0; j < idx; j++)
        {
            int m = 999;
            int ndir = 0;
            int x = Rqueue.front().first;
            int y = Rqueue.front().second;
            Rqueue.pop();

            for (int k = 0; k < 9; k++)
            {
                int nx = x + dir[k][0];
                int ny = y + dir[k][1];

                if (abs(nx - myPos.first) + abs(ny - myPos.second) < m)
                {
                    m = abs(nx - myPos.first) + abs(ny - myPos.second);
                    ndir = k;
                }
            }

            int nx = x + dir[ndir][0];
            int ny = y + dir[ndir][1];

            if (board[ny][nx] == 'I')
            {
                X = i + 1;
                isAttacked = true;
                return;
            }
            else
            {
                board[y][x] = '.';
                board[ny][nx] = 'R';
                cntBoard[y][x]--;
                cntBoard[ny][nx]++;
                Rqueue.push(make_pair(nx, ny));
            }
        }

        idx = Rqueue.size();
        for (int j = 0; j < idx; j++)
        {
            int x = Rqueue.front().first;
            int y = Rqueue.front().second;
            Rqueue.pop();

            if (cntBoard[y][x] > 1)
            {
                boomCheck[y][x] = true;
                bombQ.push(make_pair(x, y));
            }

            if (boomCheck[y][x])
            {
                board[y][x] = '.';
                cntBoard[y][x] = 0;
                continue;
            }
            else
            {
                cntBoard[y][x] = 1;
                board[y][x] = 'R';
                Rqueue.push(make_pair(x, y));
            }
        }

        while (!bombQ.empty())
        {
            boomCheck[bombQ.front().second][bombQ.front().first] = false;
            bombQ.pop();
        }
    }
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                cntBoard[i][j]++;
                Rqueue.push(make_pair(j, i));
            }
            if (board[i][j] == 'I') myPos = make_pair(j, i);
        }
    }
    cin >> s;

    Solution();
    if (isAttacked) cout << "kraj " << X << endl;
    else
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }
    }
}
