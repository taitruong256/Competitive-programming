for _ in range(int(input())):
    s=input()
    ans=int(1e18)
    for i in range(len(s)):
        ans=min(ans, s[:i].count('0')+s[i:].count('1'))
        ans=min(ans, s[:i].count('1')+s[i:].count('0'))
    print(ans)