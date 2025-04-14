a=[]
for i in range(1, 10000): a.append(i*i*i)

for _ in range(int(input())):
    n=int(input())
    check=0
    for i in range(1, 10000): 
        if i*i*i>n: break
        m=n-i*i*i
        l=0; r=9999; ans=0
        while l<=r:
            mid=(l+r)//2
            if (a[mid]==m):
                check=1
            if (a[mid]>=m): ans=mid; r=mid-1
            else: l=mid+1
    if check==0: print("NO")
    else: print("YES")