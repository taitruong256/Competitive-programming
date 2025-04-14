def solve():
    n=int(input())
    s=input()
    s=list(s)
    t=['a', 'b', 'a', 'c', 'a', 'b', 'a']
    u=['a', 'b', 'a', 'c', 'a', 'b', 'a']
    for i in range(len(s)):
        if t!=[]:
            if s[i]==t[0]: t.remove(t[0])
            elif s[i]=='?': 
                s[i]=t[0]
                t.remove(t[0])
        elif s[i] in u:
            print("NO")
            return
    
    for c in s: 
        if c=='?':
            print("NO")
            return            
    print("YES")
    print("".join(s))

for _ in range(int(input())):
    solve()