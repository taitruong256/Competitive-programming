for _ in range(int(input())):
    s=input()
    t=input()
    if t=="a":
        print(1)
        exit(0)
    if 'a' in t:
        print(-1)
        exit(0)
    st=set(s)
    while 'a' in s:
        s.replace("a", t)
        st.add(s)
print(len(st))
    