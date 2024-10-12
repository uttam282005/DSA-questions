def fib():
    n = int(input())
    a = 0
    b = 1
    print(a, b, end=" ")
    for i in range(2, n):
        c = a + b
        print(c, end=" ")
        a = b
        b = c


def recursive_fib(n):
    if n < 2:
        return n
    return recursive_fib(n - 1) + recursive_fib(n - 2)


def prime_check(n):
    if n == 2:
        return True
    for i in range(2, n):
        if n % i == 0:
            return False
    return True
