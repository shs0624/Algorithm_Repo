#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> returndays;
    int cnt = 0;
    int temp = 0;

    for (int i = 0; i < progresses.size(); i++)
    {
        if ((100 - progresses[i]) % speeds[i] == 0)
            returndays.push((100 - progresses[i]) / speeds[i]);
        else
            returndays.push((100 - progresses[i]) / speeds[i] + 1);
    }

    while (!returndays.empty())
    {
        temp = returndays.front();
        cnt++;
        returndays.pop();

        while (!returndays.empty() && temp >= returndays.front())
        {
            cnt++;
            returndays.pop();
        }

        answer.push_back(cnt);
        cnt = 0;
    }

    return answer;
}