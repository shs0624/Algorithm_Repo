#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, result;
vector<pair<int, int>> v;

//DFS가 맞는지는 모르겠음
void DFS(int day, int ans)
{
    cout << "day : " << day << " ans : " << ans << endl;
    if (day >= N)
    {
        result = max(result, ans);
        return;
    }

    int a = v[day].second;
    if (day + v[day].first - 1 < N)
    {
        DFS(day + v[day].first, ans + a);
    }
    if (v[day].first != 1) DFS(day + 1, ans);
}

int main()
{
    result = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    DFS(0, 0);

    cout << result << endl;
}
