s, x, y=[input() for i in range(3)]
t=s[::-1]
op=0
pos=0
if x in s: 
    pos=s.index(x)+len(x)
    if y in s[pos:]: op+=1
if y in t:
    pos=t.index(x)+len(x)
    if y in t[pos:]: op+=2
ans=['fantasy', 'forward', 'backward', 'both']
print(ans[op])