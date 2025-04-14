def gcd(a, b): 
	while b != 0: 
		a, b = b, a % b 
	return a

for _ in range(int(input())):
    n=int(input())
    s=input()
    d=0; k=0
    cnt=dict()
    for i in range(n):
        if s[i]=='D': d+=1;
        else: k+=1;
        x=gcd(d, k)
        t=(d//x,k//x)
        if t not in cnt:
            cnt[t]=0
        cnt[t]+=1
        print(cnt[t], end=" ")
    print()