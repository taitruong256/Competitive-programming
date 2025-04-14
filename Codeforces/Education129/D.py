n, x=map(int, input().split(" "))

def check(n):
    n=str(n) 
    if n.count('1')+n.count('0')==len(s): return -1
    ans=0
    ans=len(n)-n.count('0')
    return ans

ans=0
while 0==0:
    s=list(int(t) for t in str(x))
    s.sort(reverse=True)
    # print(s)
    if len(s)>=n: break
    mx=0
    t=0
    for i in s:
        if i!=0 and i!=1 and check(str(x*i))>mx:
            mx=check(x*i)
            t=i 
    if mx<=0:
        print(-1)
        exit(0)
    x=x*t
    print(x)
    ans=ans+1
print(ans)