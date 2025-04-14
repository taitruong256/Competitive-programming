n, p = map(int, input().split())
ans=0

def giaithua(n):
    p=1
    for i in range(1, n+1):
        p=p*i
    return p

def nCk(n, k):
    return giaithua(n)/(giaithua(k)*giaithua(n-k));

for i in range(1, n+1):
    if nCk(n, i)%p==0:
        ans+=1
    
print(ans)