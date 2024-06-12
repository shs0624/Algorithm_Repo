arr = [list(map(int, input().split())) for i in range(9)]
blankArr = [(x,y) for x in range(9) for y in range(9) if arr[x][y] == 0]

# 가로 세로 전부 체크
def checkVert(x, num):
    for i in range(9):
        if arr[x][i] == num:
            return False
    return True

def checkHorz(y, num):
    for i in range(9):
        if arr[i][y] == num:
            return False
    return True

# 구역 체크
def checkCube(x, y, num):
    x = (x // 3) * 3
    y = (y // 3) * 3
    for i in range(x, x + 3):
        for j in range(y, y + 3):
            if arr[i][j] == num:
                return False
    return True

def DFS(index):
    if index == len(blankArr):
        for i in range(9):
            print(*arr[i])
        exit()

    x, y = blankArr[index]
    for num in range(1,10):
        if checkHorz(y, num) and checkVert(x, num) and checkCube(x, y, num):
            arr[x][y] = num
            DFS(index + 1)
            arr[x][y] = 0

DFS(0)