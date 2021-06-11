#include <iostream>
using namespace std;

int n, k;
int dp[10001];
int arr[101];

void Solution()
{
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i]; j <= k; j++)
        {
            dp[j] = dp[j] + dp[j - arr[i]];
        }
    }
    cout << dp[k] << endl;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution();
}
