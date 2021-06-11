#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long M;
long long Min = 1, Max = 0;
long long arr[1000000];

bool cutting(long long h)
{
	long long cnt = 0;

	for (int i = 0; i < N; i++)
	{
		if (arr[i] - h > 0)
			cnt += arr[i] - h;
	}

	if (cnt >= M) return true;
	else return false;
}

void Solution()
{
	long long result = 0;
	while (Min <= Max)
	{
		long long mid = (Min + Max) / 2;
		if (cutting(mid))
		{
			result = max(result, mid);
			Min = mid + 1;
		}
		else
			Max = mid - 1;
	}
	cout << result << endl;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		Max = max(Max, arr[i]);
	}
	Solution();
}