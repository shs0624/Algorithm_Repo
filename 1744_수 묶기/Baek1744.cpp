#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, result;
bool changed = false;;
vector<int> v;
vector<int> answer;
priority_queue<int, vector<int>, less<int>> pq;
priority_queue<int, vector<int>, greater<int>> spq;

void Sort()
{
    while (!pq.empty())
    {
        spq.push(pq.top());
        pq.pop();
    }
}

void spqSolution()
{
    int a, b;
    result = 0;
    while (!spq.empty())
    {
        if (spq.size() == 1)
        {
            answer.push_back(spq.top());
            spq.pop();
        }
        else
        {
            a = spq.top(); spq.pop();
            b = spq.top();
            if (a * b >= a + b)
            {
                spq.pop();
                answer.push_back(a * b);
            }
            else
            {
                answer.push_back(a);
            }
        }
    }
}

void pqSolution()
{
    int a, b;
    result = 0;
    while (!pq.empty())
    {
        if (pq.size() == 1)
        {
            answer.push_back(pq.top());
            pq.pop();
        }
        else
        {
            a = pq.top(); pq.pop();
            b = pq.top();
            if (!changed && a <= 0 && b <= 0)
            {
                pq.push(a);
                Sort();
                spqSolution();
                return;
            }
            if (a * b >= a + b)
            {
                pq.pop();
                answer.push_back(a * b);
            }
            else
            {
                answer.push_back(a);
            }
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        pq.push(num);
    }

    pqSolution();

    for (int i = 0; i < answer.size(); i++)
    {
        result += answer[i];
    }
    cout << result << endl;
}
