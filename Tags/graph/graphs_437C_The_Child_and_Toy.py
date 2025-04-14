n, m=map(int, input().split())
a=[int(x) for x in input().split()]
ans=0
for i in range(m):
    u, v=map(int, input().split())
    ans+=min(a[u-1], a[v-1])
print(ans)
    