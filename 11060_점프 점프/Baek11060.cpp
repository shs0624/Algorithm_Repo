#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001];

void Solution()
{
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1001;
    }
    dp[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= arr[i]; j++)
        {
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }

    if (dp[n] != 1001) cout << dp[n] << endl;
    else cout << -1 << endl;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    Solution();
}
