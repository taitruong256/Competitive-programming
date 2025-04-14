check=[]
mx=0; ans=0
ke=[]
 
def dfs(u, d):
    global mx, check, ke
    check[u]=True
    for v in ke[u]: 
        if check[v]==False:
            dfs(v, d+1)
    mx=max(mx, d)

with open('_input.txt', 'r') as f:
    t=int(f.readline())
    for _ in range(t):
        a=[int(x) for x in f.readline().split(' ')]
        n=a[0]
        ke=[]
        for i in range(2*n): 
            ke.append([])
        check=[False]*(2*n)
        mx=0; now=0
        for i in range(n-1):
            u=a[i*2+1]
            v=a[i*2+2]
            ke[u].append(v)
            ke[v].append(u)
 
        for i in range(1, n+1):
            check=[False]*(2*n)
            dfs(i, 0)
        ans+=mx
    with open('_output.txt', 'w') as o:
        o.write(str(ans))