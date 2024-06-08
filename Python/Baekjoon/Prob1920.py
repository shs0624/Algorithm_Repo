# set를 활용한 방법
'''
N = int(input())
A = input().split()
AList = set()
for i in A:
    AList.add(int(i))

M = int(input())
B = input().split()
for i in B:
    if int(i) in AList:
        print(1)
    else:
        print(0)
'''
# 이분탐색 활용해보기
N = int(input())
A = list(map(int, input().split()))
M = int(input())
arr = list(map(int, input().split()))
A.sort()

for num in arr:
    start, end = 0, N-1
    found = False
    while start <= end:
        mid = (start + end) // 2
        if A[mid] == num:
            print(1)
            found = True
            break
        elif num > A[mid]:
            start = mid + 1
        else:
            end = mid - 1
    if not found:
        print(0)