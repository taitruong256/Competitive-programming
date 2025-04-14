n, k=map(int, input().split(" "))
s=input()
st=sorted(set(s))
if k>n:
    print(s+st[0]*(k-n))
else:
    for i in range(k-1, -1, -1):
        if s[i]!=st[-1]:
            print(s[:i]+st[st.index(s[i])+1]+st[0]*(k-i-1))
