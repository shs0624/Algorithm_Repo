# PyPy3로 해야 시간초과 발생 X
N, K = list(map(int, input().split()))
words = []
for i in range(N):
    words.append(input())

educated = [False for i in range(26)]
essential = 'antic'
answer = 0

def SetResult():
    result = 0
    global answer
    for word in words:
        possible = True
        for index in range(len(word)):
            if not educated[ord(word[index]) - ord('a')]:
                possible = False
                break

        if possible:
            result += 1

    answer = max(result, answer)

def DFS(index, count):
    global answer
    if count == K:
        SetResult()
        return

    for i in range(index, 26):
        if not educated[i]:
            educated[i] = True
            DFS(i, count + 1)
            educated[i] = False

def Solution(N, K):
    global answer
    if K < 5:
        print(answer)
        exit()

    for c in essential:
        educated[ord(c) - ord('a')] = True

    DFS(0, 5)
    print(answer)

Solution(N,K)

