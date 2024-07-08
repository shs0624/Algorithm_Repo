#include <stdio.h>

int N;
int arr[1000001] = { 0 };

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 퀵정렬은 최악의 경우 N^2 시간복잡도. 여기선 퀵정렬 사용 X
// 힙정렬 구현해보기..
//void QuickSort(int start, int end)
//{
//	if (start >= end) return;
//
//	int pivot = start;
//	int f = start + 1;
//	int l = end;
//
//	while (f <= l)
//	{
//		while (f <= end && arr[f] <= arr[pivot]) f++;
//		while (l > start && arr[l] >= arr[pivot]) l--;
//
//		if (f > l) Swap(&arr[pivot], &arr[l]);
//		else Swap(&arr[f], &arr[l]);
//	}
//
//	QuickSort(start, l - 1);
//	QuickSort(l + 1, end);
//}

// 힙으로 만드는 과정
void Heapify(int idx, int size)
{
	int left = idx * 2 + 1;
	int right = idx * 2 + 2;
	int max = idx;

	if (left < size && arr[max] < arr[left])
	{
		max = left;
	}
	if (right < size && arr[max] < arr[right])
	{
		max = right;
	}

	if (max != idx)
	{
		Swap(&arr[idx], &arr[max]);
		Heapify(max, size);
	}
}

// 힙을 만드는 함수
void BuildHeap()
{
	for (int i = N / 2 - 1; i >= 0; i--)
	{
		Heapify(i, N);
	}
}

void HeapSort()
{
	BuildHeap();

	int size = N - 1;
	for (int i = size; i >= 0; i--)
	{
		Swap(&arr[0], &arr[i]);
		Heapify(0, i);
	}
}

int main(void)
{
	int num;
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &num);
		arr[i] = num;
	}

	HeapSort();

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}