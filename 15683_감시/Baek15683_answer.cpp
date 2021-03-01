#include <iostream>
using namespace std;

struct CCTV
{
    int type;
    int y; // r
    int x; // c
};
//https://kevinthegrey.tistory.com/163 못풀어서 보고함

int N, M, ccSize, answer = 1e9; // 1e9 = 1 * 10의9승 = 1000000000
int board[9][9];
CCTV cctvArr[8];
int rotation[] = { NULL, 4, 2, 4, 4, 1 }; // 타입마다 확인해야되는 방향의 개수

void CheckDir(int dir, CCTV cctv)
{
    dir %= 4; // dir이 4보다 큰 경우를 위해
    if (dir == 0)
    {
        //오른쪽
        for (int i = cctv.x + 1; i < M; i++)
        {
            if (board[cctv.y][i] == 6) break;
            board[cctv.y][i] = -1;
        }
    }
    else if (dir == 1)
    {
        //위쪽
        for (int i = cctv.y - 1; i >= 0; i--)
        {
            if (board[i][cctv.x] == 6) break;
            board[i][cctv.x] = -1;
        }
    }
    else if (dir == 2)
    {
        //왼쪽
        for (int i = cctv.x - 1; i >= 0; i--)
        {
            if (board[cctv.y][i] == 6) break;
            board[cctv.y][i] = -1;
        }
    }
    else if (dir == 3)
    {
        //아래쪽
        for (int i = cctv.y + 1; i < N; i++)
        {
            if (board[i][cctv.x] == 6) break;
            board[i][cctv.x] = -1;
        }
    }
}

void DFS(int idx)
{
    if (idx == ccSize)
    {
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] == 0) cnt++;
            }
        }
        if (answer > cnt) answer = cnt;
        return;
    }
    int backup[9][9];
    int type = cctvArr[idx].type;

    for (int d = 0; d < rotation[type]; d++)
    {
        // 백업에 원래 보드를 붙여넣음.
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                backup[i][j] = board[i][j];

        //CheckDir은 한방향을 체크한다. 이 함수를 필요한 만큼 호출시킨다.
        if (type == 1)
        {
            CheckDir(d, cctvArr[idx]);
        }
        else if (type == 2) // 기본방향 + 180도
        {
            CheckDir(d, cctvArr[idx]);
            CheckDir(d + 2, cctvArr[idx]);
        }
        else if (type == 3)
        {
            CheckDir(d, cctvArr[idx]);
            CheckDir(d + 1, cctvArr[idx]);
        }
        else if (type == 4)
        {
            CheckDir(d, cctvArr[idx]);
            CheckDir(d + 1, cctvArr[idx]);
            CheckDir(d + 2, cctvArr[idx]);
        }
        else if (type == 5)
        {
            CheckDir(d, cctvArr[idx]);
            CheckDir(d + 1, cctvArr[idx]);
            CheckDir(d + 2, cctvArr[idx]);
            CheckDir(d + 3, cctvArr[idx]);
        }

        DFS(idx + 1);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                board[i][j] = backup[i][j];
    }
}

int main()
{
    ccSize = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] != 0 && board[i][j] != 6)
            {
                cctvArr[ccSize].y = i;
                cctvArr[ccSize].x = j;
                cctvArr[ccSize].type = board[i][j];
                ccSize++;
            }
        }
    }
    DFS(0);
    cout << answer << endl;
}
