def solve():
    s=input()
    t=input()
    p=input()
    s=list(s)
    t=list(t)
    p=list(p)
    for c in t:
        if s!=[] and c==s[0]: s.remove(s[0])
        elif c in p: p.remove(c)
        else:
            print("NO")
            return
        print(s, t, p)
    if s==[]: print("YES")
    else: print("NO")

for _ in range(int(input())):
    solve()
                