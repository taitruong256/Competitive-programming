n=int(input())
s=input()
ans=n
for i in range(1, n//2+1):
    if s[:i]==s[i:i*2]: ans=min(ans, n-len(s[:i])+1)
print(ans)