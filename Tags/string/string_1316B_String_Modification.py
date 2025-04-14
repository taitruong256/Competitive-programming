for _ in range(int(input())):
    n=int(input())
    s=input()
    a=[s[i:]+s[:i][::-1] if (n-1-i)%2==0 else s[i:]+s[:i] for i in range(n)]
    ans=min(a)
    print(ans)
    print(a.index(ans)+1)