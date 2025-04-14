n, p=map(int, input().split(' '))

tu=1
mau=1
ans=0
for i in range(1, n+1):
    tu=tu*(n-i+1)
    mau=mau*i
    if (tu//mau)%p==0: ans+=1
print(ans)
    
