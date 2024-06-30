#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 처음 시도 - 이분탐색만 사용해서 구현하려 함 -> 결과적으로 실패
// 시간 초과로 계속 중단되고, 줄일 방법이 생각나지 않아 누적합이라는 방법을
// 검색해서 찾아내고, 그 방법으로 다시 시도 -> Prob3020_Re.cpp로 재구현
int BSearch(vector<int> vec, int target);

int main()
{
    int N, H;
    vector<int> stone;
    vector<int> stalactite;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[500001];
    int cnt = 0;
    int min = INT32_MAX;
    cin >> N >> H;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (i % 2 == 0)
        {
            stone.push_back(num);
        }
        else
        {
            stalactite.push_back(num);
        }
    }

    sort(stone.begin(), stone.end());
    sort(stalactite.begin(), stalactite.end());

    for (int i = 0; i < H; i++)
    {
        arr[i] = (stone.size() - BSearch(stone, i + 1)) + (stalactite.size() - BSearch(stalactite, H - i));
        if (arr[i] < min)
        {
            cnt = 1;
            min = arr[i];
        }
        else if(min == arr[i]) 
        {
            cnt++;
        }
    }

    cout << min << " " << cnt;
    return 0;
}

int BSearch(vector<int> vec, int target)
{
    int end = vec.size();
    int start = 0;
    int mid = 0;
    while (start < end)
    {
        mid = (start + end) / 2;

        if (target <= vec[mid])
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    return start;
}