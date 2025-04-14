n=int(input())
ans=0
a=[100, 20, 10, 5, 1]
for i in range(len(a)):
    ans=ans+n//a[i]
    n=n%a[i]
print(ans)