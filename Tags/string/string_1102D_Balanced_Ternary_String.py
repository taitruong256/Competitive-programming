n=int(input())
s=[ord(x)-ord('0') for x in input()]
cnt=[s.count(x) for x in [0, 1, 2]]

def truoc(x):
    for i in range(n):
        if (cnt[x]<n//3 and cnt[s[i]]>n//3 and x<s[i]):
            cnt[x]+=1
            cnt[s[i]]-=1
            s[i]=x
            
def sau(x):
    for i in range(n-1, -1, -1):
        if (cnt[x]<n//3 and cnt[s[i]]>n//3 and x>s[i]):
            cnt[x]+=1
            cnt[s[i]]-=1
            s[i]=x
            
truoc(0)
truoc(1)
sau(2)
sau(1)
print(''.join(str(x) for x in s))