#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> rope;

void Solution()
{
    int Max = 0, cnt = 0, amount = 0, Min = 10001;

    sort(rope.begin(), rope.end(), greater<>());
    for (int i = 0; i < rope.size(); i++)
    {
        amount += rope[i];

        Min = min(Min, rope[i]);
        Max = max(Max, Min * (i + 1));
    }

    cout << Max << endl;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        rope.push_back(num);
    }
    Solution();
}
