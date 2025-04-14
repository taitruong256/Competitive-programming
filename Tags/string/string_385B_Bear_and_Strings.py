s=input()
ans=0
n=len(s)
for i in range(len(s)):
    pos=s[i:].find('bear')
    if pos!=-1: ans+=n-pos-i-3
print(ans)