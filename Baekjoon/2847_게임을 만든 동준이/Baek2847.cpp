#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> Exp;

void Solution()
{
    int answer = 0;
    int Prev;
    for (int i = Exp.size() - 1; i >= 1; i--)
    {
        Prev = Exp[i - 1];
        if (Exp[i] <= Prev)
        {
            int diff = Prev - (Exp[i] - 1);
            Exp[i - 1] = Prev - diff;
            answer += diff;
        }
    }

    cout << answer << endl;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        Exp.push_back(num);
    }
    Solution();
}
