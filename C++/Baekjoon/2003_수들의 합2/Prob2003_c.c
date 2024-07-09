#include <stdio.h>

int arr[10001] = { 0 };
int sum[10001] = { 0 };

int main(void)
{
	int N, M, result = 0;
	scanf_s("%d%d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &arr[i]);
		if (i > 0)
		{
			sum[i] = sum[i - 1] + arr[i];
		}
		else
		{
			sum[i] = arr[i];
		}
	}

	int r = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			if (i == 0)
			{
				r = sum[j];
			}
			else
			{
				r = sum[j] - sum[i - 1];
			}

			if (r == M)
			{
				result++;
				break;
			}
		}
	}

	printf("%d", result);
	return 0;
}