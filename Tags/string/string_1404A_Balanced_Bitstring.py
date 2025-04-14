for _ in range(int(input())):
    n, k=map(int, input().split(" "))
    s=input()
    one=0
    zero=0
    check=True
    for i in range(k):
        l=-1
        for j in range(i, n, k):
            if s[j]!='?':
                if l!=-1: l=ord(s[j])-ord('0')
                elif ord(s[j])-ord('0')!=l: check=False
        if (l!=-1):
            if (l==0): zero+=1
            else: one+=1
    if zero>k//2 or one>k//2: check=False
    if check==True: print("YES")
    else: print("NO")
    
            
            