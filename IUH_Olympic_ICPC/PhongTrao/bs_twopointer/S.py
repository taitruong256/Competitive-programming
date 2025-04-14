for _ in range(int(input())):
    n=int(input())
    a=[int(x) for x in ("0 "+input()).split()]
    i=1; j=n
    while i<=j and a[i]==a[j]: i=i+1; j=j-1
    if i>j:
        print("YES")
        continue
    x=a[i]; y=a[j]
    s=i; t=j
    while s<=t:
        if a[s]==a[t]: s=s+1; t=t-1
        elif a[s]==x: s=s+1
        elif a[t]==x: t=t-1
        else: break
    if s>t:
        print("YES")
        continue
    s=i; t=j
    while s<=t:
        if a[s]==a[t]: s=s+1; t=t-1
        elif a[s]==y: s=s+1
        elif a[t]==y: t=t-1
        else: break
    if s>t:
        print("YES")
        continue
    print("NO")
    