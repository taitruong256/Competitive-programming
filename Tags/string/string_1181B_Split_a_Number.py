l=int(input())
s=input()
j=(l+1)//2
i=j-1
while i>0 and s[i]=='0': i-=1
while j<l and s[j]=='0': j+=1
print(min(int(s[:l if i==0 else i])+int(s[i:]), int(s[:j])+int(s[0 if j>=l else j:])))
