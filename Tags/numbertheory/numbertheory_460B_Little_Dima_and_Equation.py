a, b, c=map(int, input().split(" "))
ans=[]
for i in range(1, 81+1):
    x=b*(i**a)+c
    if x>0 and sum(map(int, str(x)))==i and x<int(1e9): ans.append(x)
print(len(ans))
print(*ans)