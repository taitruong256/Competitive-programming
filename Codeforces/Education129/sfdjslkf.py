n, x=map(int, input().split(" "))

def check(n):
    n=str(n)
    for i in n:
        if i!='1': return True
    return False

ans=0
while 0==0:
    s=list(int(t) for t in str(x))
    print(s)
    if len(s)>=n: break
    kt=False
    for i in s:
        if i!=1 and i!=0 and check(str(x*i))==True: 
            x=x*i
            kt=True
            ans+=1
            break
    if kt==False:
        print(-1)
        exit(0)
    print(x)
print(ans)
    
    
    
    