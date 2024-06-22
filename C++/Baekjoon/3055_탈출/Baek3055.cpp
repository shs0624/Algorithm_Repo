#include <iostream>
#include <queue>
using namespace std;

struct Node
{
public:
    int x;
    int y;
};

int R,C;
char board[52][52] = {0,};
int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
int result = 0;
queue<Node> waitingNode;
queue<Node> waterQueue;
Node startPoint;

void BFS()
{
    int waterCount, moveCount;
    while(!waitingNode.empty())
    {
        int waterCount = waterQueue.size();
        // 물 확장
        for(int i = 0; i < waterCount; i++)
        {
            Node waterNode = waterQueue.front();
            int x = waterNode.x;
            int y = waterNode.y;
            waterQueue.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if((nx >= 0 && nx < R && ny >= 0 && ny < C) && board[nx][ny] == '.')
                {
                    Node newNode;
                    newNode.x = nx;
                    newNode.y = ny;
                    waterQueue.push(newNode);

                    board[nx][ny] = '*';
                }
            }
        }

        moveCount= waitingNode.size();
        // 고슴도치 이동    
        for(int i = 0; i < moveCount; i++)
        {
            Node moveNode = waitingNode.front();
            int x = moveNode.x;
            int y = moveNode.y;
            waitingNode.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if(board[nx][ny] == 'D')
                {
                    cout << ++result;
                    return;
                }

                if((nx >= 0 && nx < R && ny >= 0 && ny < C) && board[nx][ny] == '.')
                {
                    Node newNode;
                    newNode.x = nx;
                    newNode.y = ny;
                    waitingNode.push(newNode);

                    board[nx][ny] = 'S';
                }
            }
        }

        result++;
    }

    cout << "KAKTUS";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 'S')
            {
                startPoint.x = i;
                startPoint.y = j;
            }
            else if(board[i][j] == '*')
            {
                Node node;
                node.x = i;
                node.y = j;
                waterQueue.push(node);
            }
        }
    }

    waitingNode.push(startPoint);

    BFS();
}