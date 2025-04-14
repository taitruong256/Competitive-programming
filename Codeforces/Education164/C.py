tc = int(input())
for _ in range(tc):
    s=[c for c in input()]
    t=[c for c in input()]
    n=len(s)
    for i in range(n):
        a=int(''.join(s))
        b=int(''.join(t))
        tmp=s[i]
        s[i]=t[i]
        t[i]=tmp 
        c=int(''.join(s))
        d=int(''.join(t))
        if (a*b>c*d):
            tmp=s[i]
            s[i]=t[i]
            t[i]=tmp 
    print(''.join(s))
    print(''.join(t))