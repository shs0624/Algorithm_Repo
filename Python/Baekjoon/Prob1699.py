N = int(input())
arr = [i for i in range(100001)]

def Solution():
    global N
    for i in range(2, N + 1):
        p = int(i ** (1 / 2))
        for j in range(1, p + 1):
            if j**2 <= i:
                arr[i] = min(arr[i], arr[i - (j**2)] + 1)

    print(arr[N])

Solution()
