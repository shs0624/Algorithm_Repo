#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
//동서남북 때문에 더 힘들었던 문제.
//N이 Y가 1 증가하고, S가 Y가 1감소한다.
enum DIR { N, E, S, W };
int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
struct robot
{
    int x;
    int y;
    int direction;
};

struct command
{
    int target;
    char com;
    int times;
};

int A, B, n, m;
int board[102][102];
vector<robot> robotV;
queue<command> commandQ;

void Solution()
{
    for (int i = 1; i <= robotV.size(); i++)
    {
        board[robotV[i - 1].y][robotV[i - 1].x] = i;
    }

    while (!commandQ.empty())
    {
        command c = commandQ.front();
        commandQ.pop();

        int r = c.target;
        char com = c.com;
        int t = c.times;
        robot target = robotV[r - 1];

        switch (com)
        {
        case 'L':
            for (int i = 0; i < t; i++)
            {
                target.direction--;
                if (target.direction < 0) target.direction = 3;
                robotV[r - 1].direction = target.direction;
            }
            break;
        case 'R':
            for (int i = 0; i < t; i++)
            {
                target.direction++;
                if (target.direction > 3) target.direction = 0;
                robotV[r - 1].direction = target.direction;
            }
            break;
        case 'F':
            board[target.y][target.x] = 0;
            for (int i = 0; i < t; i++)
            {
                target.x += dir[target.direction][0];
                target.y += dir[target.direction][1];

                if (board[target.y][target.x] != 0)
                {
                    cout << "Robot " << r << " crashes into robot " << board[target.y][target.x] << endl;
                    return;
                }

                if (target.x < 1 || target.x > A || target.y < 1 || target.y > B)
                {
                    cout << "Robot " << r << " crashes into the wall" << endl;
                    return;
                }
            }
            robotV[r - 1].x = target.x;
            robotV[r - 1].y = target.y;
            board[target.y][target.x] = r;
            break;
        }
    }
    cout << "OK" << endl;
}

int main()
{
    cin >> A >> B;
    cin >> n >> m;

    memset(board, 0, sizeof(board));
    for (int i = 0; i < n; i++)
    {
        robot r;
        char ch;
        cin >> r.x >> r.y >> ch;
        switch (ch)
        {
        case 'N':
            r.direction = 0;
            break;
        case 'E':
            r.direction = 1;
            break;
        case 'S':
            r.direction = 2;
            break;
        case 'W':
            r.direction = 3;
            break;
        }
        robotV.push_back(r);
    }

    for (int i = 0; i < m; i++)
    {
        command c;
        cin >> c.target >> c.com >> c.times;
        commandQ.push(c);
    }
    Solution();
}
