import math
t=int(input())
for _ in range(t):
    n, c=[int(x) for x in input().split()]
    a=[int(x) for x in input().split()]
    A=4*n 
    B=0
    C=-c
    for x in a:
        B+=4*x 
        C+=x*x 
    delta=B*B-4*A*C 
    x=int((-B+math.sqrt(delta))//(2*A))
    print(x)