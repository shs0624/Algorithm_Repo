N = input()
arr = input().split()
numList = []
max = 0
average = 0
for i in arr:
    numList.append(int(i))
    if int(i) > max: max = int(i)

for i in numList:
    average += (i/max) * 100

print(average / len(numList))