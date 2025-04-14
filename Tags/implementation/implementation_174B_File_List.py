def dau(x):
    if len(x)>3:
        return x[:3]
    else:
        return x[:1]

def cuoi(x):
    if (len(x)>3):
        return x[3:]
    else:
        return x[1:]

s=input()
if s.count(".")==0:
    print("NO")
    exit(0)
s=s.split(".")
if len(s[0])<1 or len(s[0])>8 or len(s[-1])>3 or len(s[-1])<1:
    print("NO")
    exit(0)
if (len(s)==2):
    print("YES")
    print(s[0]+"."+s[1])
    exit(0)
if len(s[-1])>3:
    print("NO")
    exit(0)
    
ans=[]
check=1
for i in range(0, len(s)-1):
    if i!=0 and (len(s[i])>11 or len(s[i])<2): check=0
    if check==0: break
    t=""
    if i==0:
        t=t+s[i]+"."+dau(s[i+1])
    elif i==len(s)-2:
        t=t+cuoi(s[i])+"."+s[i+1]
    else:
        t=cuoi(s[i])+"."+dau(s[i+1])
    ans.append(t)

if (check==0): print("NO")
else:
    print("YES")
    for x in ans: print(x)