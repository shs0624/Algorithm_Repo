#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S, result;
    int arr[100001] = { 0 };
    int sum[100005] = { 0 };
    cin >> N >> S;
    result = N + 1;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (1)
        {
            sum[i + 1] = arr[i] + sum[i];
        }
    }

    if (sum[N] + sum[0] < S)
    {
        cout << 0;
        return 0;
    }

    int start = 0, end = 0, num = arr[0];
    while (start <= end && end <= N)
    {
        if (num < S)
        {
            end++;
            num = sum[end + 1] - sum[start];
        }
        else
        {
            result = min(result, end - start + 1);
            start++;
            num -= arr[start - 1];
        }
    }
    cout << result;
}