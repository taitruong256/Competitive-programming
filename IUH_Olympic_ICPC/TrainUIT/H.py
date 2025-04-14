n=int(input())
ans='ROYGBIV'
b='GBIV'
n-=7
for i in range(n):
    # t=ans
    # for j in range(0, 4):
    #     t-=ans[j]
    #     t-=ans[i-j]
    # print(t)
    ans+=b[i%4]
print(ans)
    