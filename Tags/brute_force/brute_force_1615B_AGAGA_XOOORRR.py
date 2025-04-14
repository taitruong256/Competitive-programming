for _ in range(int(input())):
    n=int(input())
    a=[int(x) for x in input().split(" ")]
    
    xr=[]
    x=0
    for i in range(n):
        x=x^a[i]
        xr.append(x)
    
    if xr[-1]==0: 
        print("YES")
        continue
    else:
        vt=xr.index(x)
        if 0 in xr[vt+1:]:
            print("YES")
        else:
            print("NO")