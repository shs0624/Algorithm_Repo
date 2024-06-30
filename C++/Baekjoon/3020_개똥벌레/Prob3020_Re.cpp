#include <iostream>
#include <vector>
using namespace std;

// 누적합 사용해보기
// 결국 특정 높이로 날 때의 석순,종유석 부수는 개수를 합하면 된다.
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int min;
    int N,H;
    int cnt = 0;
    cin >> N >> H;

    vector<int> stone(H + 1, 0);      //석순
    vector<int> stalactite(H + 1, 0); //종유석
    min = 500001;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (i % 2 == 0)
        {
            stone[num]++;
        }
        else
        {
            stalactite[H + 1 - num]++;
        }
    }

    // 위에서부터 아래로 줄이며 석순 부서지는거 누적
    for(int i = H - 1; i > 0; i--)
    {
        stone[i] += stone[i + 1];
    }

    // 아래서부터 위로 늘리며 종유석 부서지는거 누적
    for(int i = 1; i <= H; i++)
    {
        stalactite[i] += stalactite[i - 1];
        if(stone[i] + stalactite[i] < min)
        {
            cnt = 1;
            min = stone[i] + stalactite[i];
        }
        else if(stone[i] + stalactite[i] == min)
        {
            cnt++;
        }
    }

    cout << min << " " << cnt;
}