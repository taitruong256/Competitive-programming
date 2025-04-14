for _ in range(int(input())):
    s=input()
    n=int(len(s))
    ans=int(1e18)
    cnt=[0, 0, 0]
    l=0
    for r in range(n):
        cnt[ord(s[r])-ord('1')]=cnt[ord(s[r])-ord('1')]+1
        while (l<r and cnt[0]>0 and cnt[1]>0 and cnt[2]>0):
            cnt[ord(s[l])-ord('1')]=cnt[ord(s[l])-ord('1')]-1
            l=l+1
            if (cnt[0]>0 and cnt[1]>0 and cnt[2]>0): ans=min(ans, r-l+1)
    print(ans)