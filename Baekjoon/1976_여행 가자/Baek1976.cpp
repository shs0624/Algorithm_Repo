#include <iostream>
#include <queue>
using namespace std;

int N, M;
int connection[201][201];
int plan[201];
bool visit[201];
queue<int> checkQ;
void Solution()
{
    visit[plan[1]] = true;
    checkQ.push(plan[1]);
    while (!checkQ.empty())
    {
        int num = checkQ.front();
        checkQ.pop();
        for (int i = 1; i <= N; i++)
        {
            if (!visit[i] && connection[num][i] == 1)
            {
                visit[i] = true;
                checkQ.push(i);
            }
        }
    }

    for (int i = 1; i <= M; i++)
    {
        if (!visit[plan[i]])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main()
{
    cin >> N;
    cin >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> connection[i][j];
        }
    }

    for (int i = 1; i <= M; i++)
    {
        cin >> plan[i];
    }
    Solution();
}
