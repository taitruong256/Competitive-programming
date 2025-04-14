s=input()
n=len(s)
cnt1=[0]*26
cnt2=[]
for i in range(26): cnt2.append([0]*26)

ans=0
for i in range(n):
    c=ord(s[i])-ord('a')
    for j in range(26):
        cnt2[j][c]+=cnt1[j]
    cnt1[c]=cnt1[c]+1
ans=max(cnt1)
for i in range(26): 
    t=max(cnt2[i])
    ans=max(ans, t)
print(ans)
    