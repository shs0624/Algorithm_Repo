memo = [None] * 50
def fib(number):
    if number < 2:
        return number

    if memo[number] == None:
        memo[number] = fib(number-1) + fib(number-2)

    return memo[number]

num = int(input())
print(fib(num))
