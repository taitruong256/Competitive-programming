n=int(input())
a=[int(x) for x in input().split(" ")]
b=[0]*n
for i in range(n): b[a[i]-1]=i+1
for it in b: print(it, end=" ")
