#include <iostream>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
//극이 N이면0, S면 1
int rotation[4]; // 1은 시계, -1은 반시계
int gears[4][8];
int K, num, dir;

//queue를 이용해 삽입 후, pop할때 for문을
//q.size()를 이용해 돌리다가, 버그가 발생해서 8로 바꿔적고 고쳐짐.

void CheckRotation(int n, int start)
{
    bool isRight;
    if (n >= 4 || n < 0) return;

    if (start < n) isRight = false; // 시작지점이 왼쪽
    else isRight = true; // 시작지점이 오른쪽

    if (rotation[start] != 0)
    {
        if (isRight && gears[start][6] != gears[n][2])
        {
            if (rotation[start] == 1) rotation[n] = -1;
            else if (rotation[start] == -1) rotation[n] = 1;
            CheckRotation(n - 1, n);
        }
        else if (!isRight && gears[start][2] != gears[n][6])
        {
            if (rotation[start] == 1) rotation[n] = -1;
            else if (rotation[start] == -1) rotation[n] = 1;
            CheckRotation(n + 1, n);
        }
    }
}

void RotateWheel(int idx)
{
    queue<int> q;
    int cnt;
    
    if (rotation[idx] == 1)
    {
        q.push(gears[idx][7]);
        for (int i = 0; i < 7; i++) q.push(gears[idx][i]);

        for (int i = 0; i < 8; i++)
        {
            gears[idx][i] = q.front();
            q.pop();
        }
    }
    else
    {
        for (int i = 1; i < 8; i++) q.push(gears[idx][i]);
        q.push(gears[idx][0]);

        for (int i = 0; i < 8; i++)
        {
            gears[idx][i] = q.front();
            q.pop();
        }
    }
}

void Solution()
{
    for (int i = 0; i < 4; i++) rotation[i] = 0;

    rotation[num - 1] = dir;
    CheckRotation(num - 2, num - 1);
    CheckRotation(num, num - 1);

    for (int i = 0; i < 4; i++)
    {
        if(rotation[i] != 0) RotateWheel(i);
    }
}

int main()
{
    int result = 0;
    string s;
    for (int i = 0; i < 4; i++)
    {
        cin >> s;
        for (int j = 0; j < 8; j++)
        {
            gears[i][j] = (int)s[j] - 48;
        }
    }

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> num >> dir;
        Solution();
    }

    for (int i = 0; i < 4; i++)
    {
        if (gears[i][0] == 0) continue;
        else
        {
            result += pow(2, i);
        }
    }
    cout << result << endl;
}
