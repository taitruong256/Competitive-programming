fi=open('_input.txt', 'r')
fo=open('_output.txt', 'w')

def solve():
    n=int(fi.readline())
    uoc=[]
    i=1
    while i*i<=n:
        if (n%i==0):
            uoc.append(i)
            if i!=n//i: uoc.append(n//i)
        i+=1
    uoc.sort()
    ans=len(uoc)
    ans=len(uoc)
    for i in range(0, len(uoc)-1):
        for j in range(i+1, len(uoc)):
            p=1
            q=1
            for k in range(1, 47):
                p*=uoc[i]
                q*=uoc[j]
                if (p+q)%(uoc[i]*uoc[j])==0:
                    ans+=2
                    fo.write(str())
                    break;
    fo.write(str(ans)+'\n')
    
t=int(fi.readline())
for i in range(t):
    solve()
    fo.write('\n')
fi.close();
fo.close();