#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, answer;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int map[501][501];
bool visit[501][501];

// https://yabmoons.tistory.com/35 보고했음.
// 'ㅗ'모양을 빼면 DFS로 알아낼 수 있다.

//방문해서 사방을 검사하고, DFS방식으로 진행하며 4칸을 검사하는 함수.
//x,y좌표, 현재까지의 합, 검사한 개수를 매개변수로 보냄.
void DFS(int x, int y, int sum, int cnt)
{
    visit[x][y] = true;

    if(cnt == 3)
    {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (visit[nx][ny]) continue;

        DFS(nx, ny, sum + map[nx][ny], cnt + 1);
        visit[nx][ny] = false;
    }
}

//DFS로 검사가 불가능한 ㅏ ㅓ ㅗ ㅜ 모양 테트로미노 검사를 위한 함수.
void Shape(int x, int y, int num)
{
    int _sum = 0;
    switch (num)
    {
    case 1:
        _sum = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x - 1][y + 1];
        if (_sum > answer) answer = _sum;
        break;
    case 2:
        _sum = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1];
        if (_sum > answer) answer = _sum;
        break;
    case 3:
        _sum = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1];
        if (_sum > answer) answer = _sum;
        break;
    case 4: 
        _sum = map[x][y] + map[x - 1][y + 1] + map[x][y + 1] + map[x + 1][y + 1];
        if (_sum > answer) answer = _sum;
        break;
    }
}

void Solution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            //위치마다 DFS와 ㅓ 모양 테트로미노 검사를 진행하는 브루트포스 알고리즘.
            memset(visit, false, sizeof(visit));
            DFS(i, j, map[i][j], 0);
            if (i - 1 >= 0 && j + 2 < M) Shape(i, j, 1);// ㅓ
            if (j + 2 < M && i + 1 < N) Shape(i, j, 2); // ㅏ
            if (i + 2 < N && j + 1 < M) Shape(i, j, 3); // ㅜ
            if (i + 1 < N && i - 1 >= 0 && j + 1 < M) Shape(i, j, 4); // ㅗ
        }
    }
    cout << answer << endl;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
    Solution();
}
