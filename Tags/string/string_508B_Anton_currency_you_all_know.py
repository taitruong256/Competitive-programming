s=input()
index=-1
n=len(s)
for i in range(n):
    if s[i] in "02468":
        index=i
        if s[i]<s[-1]: break
if index==-1: print(-1)
else: print(s[:index]+s[-1]+s[index+1:n-1]+s[index])