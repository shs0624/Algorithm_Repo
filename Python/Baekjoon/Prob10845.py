N = int(input())
strList = []
queue = []

for i in range(N):
    strList.append(input())

for str in strList:
    li = str.split(' ')
    if li[0] == "push":
        queue.append(int(li[1]))
    elif li[0] == "pop":
        if len(queue) == 0:
            print(-1)
        else:
            print(queue.pop(0))
    elif li[0] == "size":
        print(len(queue))
    elif li[0] == "empty":
        if len(queue) == 0:
            print(1)
        else:
            print(0)
    elif li[0] == "front":
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[0])
    elif li[0] == "back":
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[len(queue) - 1])