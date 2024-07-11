#include <iostream>
#include <queue>
using namespace std;

int N;
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int arr[101][101] = { 0 };
bool check[101][101] = { false };

queue<pair<int, int>> waitingQueue;

void ResetCheckArr()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			check[i][j] = false;
		}
	}
}

void BFS(int x, int y, int height)
{
	check[x][y] = true;
	waitingQueue.push(make_pair(x, y));

	int nx, ny;
	while (!waitingQueue.empty())
	{
		x = waitingQueue.front().first;
		y = waitingQueue.front().second;
		waitingQueue.pop();

		for (int i = 0; i < 4; i++)
		{
			nx = x + dir[i][0];
			ny = y + dir[i][1];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			{
				continue;
			}

			if (arr[nx][ny] > height && !check[nx][ny])
			{
				check[nx][ny] = true;
				waitingQueue.push(make_pair(nx, ny));
			}
		}
	}
}

int main(void)
{
	int result = 1, cnt = 1, mHeight = 1;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > mHeight)
			{
				mHeight = arr[i][j];
			}
		}
	}

	for (int height = 1; height <= mHeight; height++)
	{
		cnt = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!check[i][j] && arr[i][j] > height)
				{
					BFS(i, j, height);
					cnt++;
				}
			}
		}

		if (result < cnt)
		{
			result = cnt;
		}

		ResetCheckArr();
	}

	cout << result;
}