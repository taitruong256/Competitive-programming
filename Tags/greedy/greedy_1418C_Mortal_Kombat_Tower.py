for _  in range(int(input())):
    n=int(input())
    a=[int(x) for x in input().split(" ")]
    ans=0
    if (a[0]==1): ans=1
    i=1
    while i<n:
        if a[i]==0:
            i=i+1
            continue
        else:
            j=i
            while j<n and a[j]==1: j=j+1
        ans+=(j-i)//3
        i=j
    print(ans)