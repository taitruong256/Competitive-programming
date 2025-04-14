s=input()
if ("w" in s or "m" in s):
    print(0)
    exit(0)
s=" "+s    

n=len(s)
f=[1]*n
mod=10**9+7
for i in range(2, n):
    if s[i] in "nu" and s[i]==s[i-1]: 
        f[i]=(f[i-1]+f[i-2])%mod
    else: 
        f[i]=f[i-1]
print(f[n-1])