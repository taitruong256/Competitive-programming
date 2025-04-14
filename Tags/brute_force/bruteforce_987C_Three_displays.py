n=int(input())
a=[int(x) for x in input().split(" ")]
c=[int(x) for x in input().split(" ")]

ans=int(1e18)
for j in range(1, n-1):
    cost=0
    pos=-1; mn=0
    for i in range(0, j): 
        if a[i]<a[j] and c[i]>mn:
            mn=c[i]
            pos=i
    if pos==-1: continue
    cost+=c[pos]
    
    pos=-1; mn=0
    for k in range(j+1,n):
        if a[j]<a[k] and c[k]>mn:
            mn=c[k]
            pos=k
    if (pos==-1): continue
    cost+=c[pos]
    cost+=c[j]
    ans=min(ans, cost)
if ans==int(1e18): ans=-1
print(ans)