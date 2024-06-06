#include <iostream>
#include <algorithm>
using namespace std;
//https://sihyungyou.github.io/baekjoon-2579/ 보고했음
int dp[301];
int arr[301];

//연속 3계단을 1칸씩 오르는게 금지
//계단을 1칸 오르는걸 계산하지 않고, 2칸 오른 후 1칸을 오르는거를 계산

int main()
{
	int N, V, cnt = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = max(arr[1] + arr[2], arr[2]);
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

	for (int i = 4; i <= N; i++)
	{
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}

	cout << dp[N];
}