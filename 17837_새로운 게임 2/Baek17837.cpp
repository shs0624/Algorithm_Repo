#include <iostream>
#include <vector>
using namespace std;

//dir을 지정하는 것과, 배열을 1부터 세는걸 실수해서 오류 발생함.
//이동지점이 파란색일때의 예외처리에 실수가 있었음.
struct Chess
{
    int x;
    int y;
    int dir;
};

int N, K;
int board[13][13]; // 0 = 흰색, 1 = 빨간색, 2 = 파란색
int dir[5][2] = { {0,0}, { 1,0 }, { -1,0 }, { 0,-1 }, { 0,1 } };
vector<int> MAP[13][13];
Chess chessMans[11];

void MoveMan(int x, int y, int d, int idx, int n)
{
    int cnt = 0;
    int nx = x + dir[d][0];
    int ny = y + dir[d][1];
    int color = board[ny][nx];

    if (nx <= 0 || ny <= 0 || nx > N || ny > N)
    {
        color = 2;
    }

    if (color == 0)
    {
        for (int i = idx; i < MAP[y][x].size(); i++)
        {
            MAP[ny][nx].push_back(MAP[y][x][i]);
            int num = MAP[y][x][i];
            chessMans[num].x = nx;
            chessMans[num].y = ny;
            cnt++;
        }
        for (int i = 0; i < cnt; i++) MAP[y][x].pop_back();
    }
    else if (color == 1)
    {
        for (int i = MAP[y][x].size() - 1; i >= idx; i--)
        {
            MAP[ny][nx].push_back(MAP[y][x][i]);
            int num = MAP[y][x][i];
            chessMans[num].x = nx;
            chessMans[num].y = ny;
            cnt++;
        }
        for (int i = 0; i < cnt; i++) MAP[y][x].pop_back();
    }
    else if (color == 2)
    {
        int newDir;
        switch (d)
        {
        case 1: newDir = 2; break;
        case 2: newDir = 1; break;
        case 3: newDir = 4; break;
        case 4: newDir = 3; break;
        }
        chessMans[n].dir = newDir;

        nx = x + dir[newDir][0];
        ny = y + dir[newDir][1];

        if (nx > 0 && ny > 0 && nx <= N && ny <= N)
        {
            if(board[ny][nx] != 2) MoveMan(x, y, newDir, idx, n);
            //해당지점이 파란색이면 이동하지 않는 코드
            //이 확인이 없어서 시간초과 나왔음
        }
    }
}

bool CheckGame()
{
    for (int i = 0; i < K; i++)
    {
        if (MAP[chessMans[i].y][chessMans[i].x].size() >= 4) return true;
    }
    return false;
}

int FindIdx(int x, int y, int idx)
{
    for (int i = 0; i < MAP[y][x].size(); i++)
    {
        if (MAP[y][x][i] == idx) return i;
    }
}

void Solution()
{
    int turn = 0;
    bool overTurn = true;
    while (1)
    {
        bool flag = false;
        turn++;

        if (turn > 1000) 
        {
            overTurn = false;
            break;
        }
        
        for (int i = 0; i < K; i++)
        {
            int x = chessMans[i].x;
            int y = chessMans[i].y;
            int d = chessMans[i].dir;
            
            int idx = FindIdx(x, y, i);

            MoveMan(x, y, d, idx, i);
            if (CheckGame())
            {
                flag = true;
                break;
            }
        }

        if (flag) break;
    }

    if (overTurn) cout << turn << endl;
    else cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; i++)
    {
        int x, y, d;
        cin >> y >> x >> d;
        chessMans[i] = { x,y,d };
        MAP[y][x].push_back(i);
    }
    Solution();
}
