#include <iostream>
using namespace std;

void Solution(int num)
{
	int arr[10001];
	int cnt = 0, input;
	string str;

	for (int i = 0; i < num; i++)
	{
		cin >> str;
		if (str == "push") {
			scanf(" %d", &input);
			arr[cnt++] = input;
		}
		else if (str == "front") {
			if (cnt == 0) printf("-1\n");
			else printf("%d\n", arr[0]);
		}
		else if (str == "back") {
			if (cnt == 0) printf("-1\n");
			else printf("%d\n", arr[cnt - 1]);
		}
		else if (str == "size") {
			printf("%d\n", cnt);
		}
		else if (str == "empty") {
			printf("%d\n", cnt == 0);
		}
		else if (str == "pop") {
			if (cnt == 0) printf("-1\n");
			else {
				printf("%d\n", arr[0]);

				for (int j = 0; j < cnt - 1; j++)
				{
					arr[j] = arr[j + 1];
				}
				cnt--;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	Solution(n);
}