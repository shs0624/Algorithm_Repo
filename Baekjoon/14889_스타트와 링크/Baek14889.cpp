#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,result = 1000000;
int board[21][21];
vector<int> start;
vector<int> link;

//https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-14889-%EC%8A%A4%ED%83%80%ED%8A%B8%EC%99%80-%EB%A7%81%ED%81%AC
//보고 풀음
//1. 팀 나누기
//2. 팀 멤버 각각의 시너지 확인
//3. 최소값과 비교후 교체

void Solution(int idx)
{
    if (idx == N + 1)
    {
        if (start.size() == N / 2 && link.size() == N / 2)
        {
            int start_sum = 0;
            int link_sum = 0;

            for (int i = 0; i < N / 2; i++)
            {
                for (int j = i + 1; j < N / 2; j++)
                {
                    if (i == j) continue;
                    int sf = start[i];
                    int ss = start[j];

                    start_sum += board[sf][ss] + board[ss][sf];

                    int lf = link[i];
                    int ls = link[j];

                    link_sum += board[lf][ls] + board[ls][lf];
                }
            }

            result = min(result, abs(start_sum - link_sum));
        }
        return;
    }

    start.push_back(idx);
    Solution(idx + 1);
    start.pop_back();

    link.push_back(idx);
    Solution(idx + 1);
    link.pop_back();
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
        }
    }
    Solution(1);

    cout << result << endl;
}
