N = int(input())
strList = []
stack = []
for i in range(N):
    strList.append(input())

for str in strList:
    li = str.split(' ')
    if li[0] == "push":
        stack.append(int(li[1]))
    elif li[0] == "pop":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack.pop())
    elif li[0] == "size":
        print(len(stack))
    elif li[0] == "empty":
        if len(stack) == 0:
            print(1)
        else:
            print(0)
    elif li[0] == "top":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[len(stack) - 1])