t=input()
s=t.split('@')
if ''.join(s)==t:
    print('No solution')
    exit(0)
n=len(s)
if s[0]=='' or s[n-1]=='': 
    print('No solution')
    exit(0)
for i in range(1, n-1):
    if len(s[i])<2:
        print('No solution')
        exit(0)
    s[i]=s[i][:1]+','+s[i][1:]
print('@'.join(s))