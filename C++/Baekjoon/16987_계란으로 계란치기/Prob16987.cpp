#include <iostream>
#include <vector>
using namespace std;

int N, result = 0;
vector<pair<int, int>> eggVec;

int LeftEgg()
{
    int ret = 0;
    for (int i = 0; i < eggVec.size(); i++)
    {
        if (eggVec[i].first > 0)
            ret++;
    }
    return ret;
}

void BackTracking(int current)
{
    int res = 0;
    int left = LeftEgg();

    if (current == N || left <= 1)
    {
        res = 0;
        for (int i = 0; i < eggVec.size(); i++)
        {
            if (eggVec[i].first <= 0)
                res++;
        }

        result = max(result, res);
        return;
    }

    if (eggVec[current].first <= 0)
    {
        BackTracking(current + 1);
    }

    for (int i = 0; i < N; i++)
    {
        if (i != current && eggVec[current].first > 0 && eggVec[i].first > 0)
        {
            eggVec[current].first -= eggVec[i].second;
            eggVec[i].first -= eggVec[current].second;
            BackTracking(current + 1);
            eggVec[current].first += eggVec[i].second;
            eggVec[i].first += eggVec[current].second;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int hp, weight;
        cin >> hp >> weight;
        eggVec.push_back(make_pair(hp, weight));
    }

    BackTracking(0);
    cout << result;
}