n=int(input())
isprime=[1]*(n+5)
isprime[0]=0
isprime[1]=0
for i in range(2, n+1):
    if isprime[i]==1:
        j=i*2
        while j<=n:
            isprime[j]=0
            j=j+i

ans=[]
for i in range(2, n+1):
    if isprime[i]==1:
        j=1
        while i*j<=n:
            ans.append(i*j)
            j=j*i
print(len(ans))
print(*ans)