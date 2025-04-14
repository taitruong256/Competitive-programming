n=int(input())
a=[int(x) for x in input().split(" ")]
for i in range(n):
    ans=15
    for add in range(16):
        for mul in range(16):
            if ((a[i]+add)*(2**mul)%32768==0):
                ans=min(ans, add+mul)
    print(ans)