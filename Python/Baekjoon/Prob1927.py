# 힙 직접 구현은 11279번 - 최대힙에서 해봤으니, heapq 모듈 이용해보기
import sys
import heapq

N = int(input())
heap = []

for i in range(N):
    num = int(sys.stdin.readline())
    if num:
        heapq.heappush(heap, num)
    else:
        if len(heap) > 0:
            print(heapq.heappop(heap))
        else:
            print(0)