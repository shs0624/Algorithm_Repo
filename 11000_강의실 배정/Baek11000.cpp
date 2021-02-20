#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, answer;
vector<pair<int, int>> lesson;
priority_queue<int, vector<int>, greater<int>> pq;
// priority queue를 활용할 생각을 못함
// 참고 https://j3sung.tistory.com/497

bool bigger(pair<int,int> a, pair<int,int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

void Solution()
{
    answer = 0;
    sort(lesson.begin(), lesson.end(), bigger);

    pq.push(lesson[0].second);
    for (int i = 1; i < lesson.size(); i++)
    {
        if (pq.top() <= lesson[i].first)
        {
            pq.pop();
            pq.push(lesson[i].second);
        }
        else
        {
            pq.push(lesson[i].second);
        }
    }

    cout << pq.size();
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        lesson.push_back(make_pair(a, b));
    }
    Solution();
}
