class MaxHeap:
    def __init__(self):
        self.heap = []
        self.heap.append(None)  # 힙 인덱스를 1부터 시작하기 위한 추가

    def Swap_Up(self, idx):
        if idx <= 1:
            return

        parentIdx = idx // 2
        if self.heap[idx] > self.heap[parentIdx]:
            self.heap[idx], self.heap[parentIdx] = self.heap[parentIdx], self.heap[idx]
            self.Swap_Up(parentIdx)
        else:
            return

    def Swap_Down(self, idx):
        leftIdx = idx * 2
        rightIdx = idx * 2 + 1

        if leftIdx >= len(self.heap):
            return
        elif rightIdx >= len(self.heap):
            if self.heap[leftIdx] > self.heap[idx]:
                self.heap[idx], self.heap[leftIdx] = self.heap[leftIdx],self.heap[idx]
                self.Swap_Down(leftIdx)
            else:
                return
        else:
            if self.heap[leftIdx] > self.heap[rightIdx]:
                if self.heap[leftIdx] > self.heap[idx]:
                    self.heap[idx], self.heap[leftIdx] = self.heap[leftIdx], self.heap[idx]
                    self.Swap_Down(leftIdx)
                else:
                    return
            else:
                if self.heap[rightIdx] > self.heap[idx]:
                    self.heap[idx], self.heap[rightIdx] = self.heap[rightIdx], self.heap[idx]
                    self.Swap_Down(rightIdx)
                else:
                    return

    def Add(self, num):
        self.heap.append(num)
        idx = len(self.heap) - 1

        self.Swap_Up(idx)

    def Del(self):
        if (len(self.heap) - 1) < 1:
            print(0)
            return

        print(self.heap[1])
        self.heap[1] = self.heap[-1]
        self.heap.pop()

        idx = 1
        self.Swap_Down(idx)



N = int(input())
heap = MaxHeap()
numList = []
for i in range(N):
    num = int(input())
    numList.append(num)

for n in numList:
    if n == 0:
        heap.Del()
    else:
        heap.Add(n)