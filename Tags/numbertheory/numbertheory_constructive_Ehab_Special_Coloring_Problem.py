n=int(input())
ans=[0]*(n+1)
m=1
for i in range(2, n+1):
    if (ans[i]==0):
        for j in range(i, n+1, i):
            ans[j]=m
        m+=1
print(*ans[2::])