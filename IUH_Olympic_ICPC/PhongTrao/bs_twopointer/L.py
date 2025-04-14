for _ in range(int(input())):
    n=int(input())
    a=[int(x) for x in input().split(" ")]
    b=[]
    if n%2==1:
        i=n//2; 
        b.append(a[i])
        for k in range(1, n//2+1): 
            b.append(a[i+k])
            b.append(a[i-k])
        b.reverse()
        for it in b: print(it, end=" ")
        print()
    else:
        i=n//2; 
        b.append(a[i])
        b.append(a[i-1])
        for k in range(1, n//2): 
            b.append(a[i+k])
            b.append(a[i-k-1])
        b.reverse()
        for it in b: print(it, end=" ")
        print()