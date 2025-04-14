n, k=map(int, input().split(" "))
ans=[]
for i in range(n):
    if k>0: 
        ans.append(2*i+2)
        ans.append(2*i+1)
    else:
        ans.append(2*i+1)
        ans.append(2*i+2)
    k-=1
for i in ans: print(i, end=" ")