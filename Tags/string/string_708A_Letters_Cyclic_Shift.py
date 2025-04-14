s=list(input())
l=0; r=0
for i in range(len(s)):
    if s[i]=='a': continue
    l=i
    r=i+1
    while r<len(s) and s[r]>'a': r+=1
    break
# print(l, r)
if l==0 and r==0:
    s[len(s)-1]='z';
    print(''.join(s))
else:
    for i in range(l, r):
        s[i]=chr(ord(s[i])-1)
    print(''.join(s))