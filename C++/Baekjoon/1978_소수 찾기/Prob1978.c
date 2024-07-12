#include <stdio.h>
#include <string.h>
#include <math.h>

int arr[101] = { 0 };
char check[1001] = { 1, };

// 에라토스테네스의 체 알고리즘 - 특정 수의 제곱근 까지의 수를 나열해서 체크하며, 각 수의 배수는 소수가 아니니 제외하는 방식.
// https://velog.io/@changhee09/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%86%8C%EC%88%98%EC%9D%98-%ED%8C%90%EB%B3%84-%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98-%EC%B2%B4
void CheckPrimeNum(int num)
{
	int sq = (int)sqrt(num);
	check[1] = 0;
	for (int i = 2; i <= sq; i++)
	{
		if (check[i])
		{
			int cnt = 2;
            // 받은 수를 넘어가지 않는동안 배수를 false로 설정
			while (i * cnt <= num)
			{
				check[i * cnt] = 0;
				cnt++;
			}
		}
	}
}

int main(void)
{
	int N, max = 0, result = 0;
	scanf_s("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &arr[i]);
		max = (arr[i] > max) ? arr[i] : max;
	}

	memset(check, 1, sizeof(check));
	CheckPrimeNum(max); // max값을 넘겨 최대값을 기준으로 check배열 설정
	
	for (int i = 0; i < N; i++)
	{
		if (check[arr[i]])
		{
			result++;
		}
	}

	printf("%d\n", result);
	return 0;
}