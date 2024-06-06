#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, answer = 0;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        pq.push(num);
    }

    if (N == 1) answer = 0;
    else
    {
        while (!pq.empty())
        {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();

            answer += a + b;
            if (!pq.empty()) pq.push(a + b);
        }
    }

    cout << answer << endl;
}
