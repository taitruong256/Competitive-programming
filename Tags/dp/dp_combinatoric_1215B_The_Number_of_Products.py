n=int(input())
a=[int(x) for x in ("0 "+input()).split(" ")]
pos=[0]*(n+1)
neg=[0]*(n+1)
ans=0
for i in range(1, n+1):
    if a[i]>0:
        pos[i]=pos[i-1]+1; neg[i]=neg[i-1]
    else:
        pos[i]=neg[i-1]; neg[i]=pos[i-1]+1
    ans+=neg[i]
print(ans, n*(n+1)//2-ans)
    