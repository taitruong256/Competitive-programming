n=int(input())
mod=int(1e9+7)
x=[[0, 1], [1, 1]]

def nhanmatran(x, y):
    ans=[[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                ans[i][j]+=x[i][k]*y[k][j]
                ans[i][j]%=mod
    return ans

def luythua(x, n):
    p=[[1, 0], [0, 1]]
    while n>0:
        if n%2==1:
            p=nhanmatran(p, x)
        n=n//2
        x=nhanmatran(x, x)
    return p 

x=luythua(x, n-1)
print((x[0][0]*2+x[0][1]*1)%mod)