s=list(input())
n=len(s)
c=ord('a')
for i in range(n):
    if ord(s[i])<=c:
        s[i]=chr(c)
        c+=1
    if c==ord('z')+1:
        print(''.join(s))
        exit(0)
print(-1)
