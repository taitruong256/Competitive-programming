a=sorted(list(set(map(int, input().split(',')))))
a.append(-1)
ans=''
for i in range(len(a)-1):
    if a[i]-1 not in a:
        ans+=','+str(a[i])
    elif a[i]+1 not in a:
        ans+='-'+str(a[i])
print(ans[1:])