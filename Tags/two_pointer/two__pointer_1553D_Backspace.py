for _ in range(int(input())):
    s=input()
    t=input()
    i=len(s)-1
    j=len(t)-1
    while i>=0 and j>=0:
        if s[i]==t[j]:
            i-=1
            j-=1
        else:
            i-=2
    if (j==-1): print("YES")
    else: print("NO")