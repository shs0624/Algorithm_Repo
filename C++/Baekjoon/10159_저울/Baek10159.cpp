#include <iostream>
using namespace std;

int N, M, answer;
int graph[101][101];
//https://blog.naver.com/ndb796/221234427842 플로이드-와샬
//https://jow1025.tistory.com/117 풀이 보고함

void Solution()
{
    //거치는 지점
    for (int i = 1; i <= N; i++)
    {
        //시작 지점
        for (int j = 1; j <= N; j++)
        {
            //도착 지점
            for (int k = 1; k <= N; k++)
            {
                if (graph[j][i] && graph[i][k]) graph[j][k] = 1;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        answer = 0;
        for (int j = 1; j <= N; j++)
        {
            if (i == j) continue;
            if (graph[i][j] == 0 && graph[j][i] == 0) answer++;
        }
        cout << answer << endl;
    }
}

int main()
{
    int a, b;
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        graph[a][b] = 1;
    }
    Solution();
}