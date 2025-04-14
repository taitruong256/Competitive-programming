n=int(input())
a=[int(x) for x in input().split(" ")]
b=[]
for i in range(n):
    t=input()
    s=sum(t.count(x) for x in 'aiouey')
    b.append(s==a[i])
if all(b): print("YES")
else: print("NO")