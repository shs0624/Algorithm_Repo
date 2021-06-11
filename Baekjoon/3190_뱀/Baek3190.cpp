#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int N, K, L, answer;
int dir[5][2] = { {0,0},{0,-1},{1,0},{0,1},{-1,0} };
int apple[101][101];
int map[101][101];
queue<pair<int, char>> q;
deque<pair<int, int>> dq;
//1 = 북쪽 2 = 동쪽 3 = 남쪽 4 = 서쪽 5 = 몸통

void Solution()
{
    int d = 2;
    int nextT = q.front().first;
    char nextD = q.front().second;
    q.pop();

    map[1][1] = 2;
    dq.push_back({ 1,1 });
    answer = 0;
    while (1)
    {
        int nx, ny;
        answer++;
        nx = dq.front().first + dir[d][0];
        ny = dq.front().second + dir[d][1];
        //cout << nx << " " << ny << " nextT : " << nextT << endl;
        if (nx < 1 || nx > N || ny < 1 || ny > N)
            break;
        if (map[ny][nx] == 5) break;

        if (apple[ny][nx] == 1)
        {
            apple[ny][nx] = 0;
            map[dq.front().second][dq.front().first] = 5;
            map[ny][nx] = d;
            dq.push_front({ nx, ny });
        }
        else
        {
            map[dq.front().second][dq.front().first] = 5;
            map[dq.back().second][dq.back().first] = 0;
            dq.pop_back();
            map[ny][nx] = d;
            dq.push_front({ nx, ny });
        }

        if (answer == nextT)
        {
            //머리의 방향을 nextD로.
            if (nextD == 'L')
            {
                d -= 1;
                if (d < 1) d = 4;
            }
            else if (nextD == 'D')
            {
                d += 1;
                if (d > 4) d = 1;
            }

            if (!q.empty())
            {
                nextT = q.front().first;
                nextD = q.front().second;
                q.pop();
            }
            else
            {
                nextT = 1e9;
            }
        }
    }
    cout << answer << endl;
}

int main()
{
    cin >> N;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> y >> x;
        apple[y][x] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int X; char C;
        cin >> X >> C;
        q.push({ X,C });
    }
    Solution();
}
