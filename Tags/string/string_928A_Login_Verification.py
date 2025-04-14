def f(s):
    return s.lower().replace('i', '1').replace('0', 'o').replace('l', '1')

s=f(input())
n=int(input())
a=[f(input()) for i in range(n)]
if s in a: print("No")
else: print("Yes")