for _ in range(int(input())):
    n, k=map(int, input().split(" "))
    s=input()
    cnt=[[0 for i in range(26)] for i in range(k)]
    for i in range(n):
        cnt[min(i%k, k-1-i%k)][ord(s[i])-ord('a')]+=1
    ans=0
    for i in range (k//2):
        ans+=2*(n//k)-max(cnt[i])
    if k%2==1:
        ans+=n//k-max(cnt[k//2])
    print(ans)