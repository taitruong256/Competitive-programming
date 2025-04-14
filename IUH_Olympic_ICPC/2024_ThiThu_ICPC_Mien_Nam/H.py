a, b, m = map(int, input().split())

def f(n):
    return n*(n+1)*(2*n+1)//6

print((f(b)-f(a-1))%m) 