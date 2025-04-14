n=int(input())
a=[int(x) for x in input().split(" ")]
maxn=100005
minprime=[0]*maxn
i=2
while i*i<maxn:
    if minprime[i]==0:
        j=i*i
        while j<maxn: 
            if minprime[j]==0: minprime[j]=i 
            j+=i
    i+=1
for i in range(1, maxn):
    if minprime[i]==0: minprime[i]=i

dp=[0]*maxn
for i in range(n):
    x=a[i]
    st={1}
    while x>1:
        st.add(minprime[x])
        x//=minprime[x]
    mx=0
    for j in st: 
        if j!=1: mx=max(mx, dp[j])
    mx+=1
    for j in st: 
        if j!=1: dp[j]=mx 
dp[1]=1

print(max(dp))