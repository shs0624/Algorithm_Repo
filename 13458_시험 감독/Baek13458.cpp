#include <iostream>
using namespace std;

int N, B, C;
int arr[1000001];

void Solution()
{
    // 자료형 int로 사용하면 오류발생
    long long answer = 0;
    for (int i = 0; i < N; i++)
    {
        arr[i] -= B;
        answer++;
        if (arr[i] > 0)
        {
            int n = arr[i] / C;
            if (arr[i] % C == 0) answer += n;
            else answer += (n + 1);
        }
    }
    cout << answer << endl; 
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cin >> B >> C;
    Solution();
}