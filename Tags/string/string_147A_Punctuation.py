s=input()
t='.,?!'
for i in t: s=s.replace(i, i+' ')
s=' '.join(s.split())
for i in t: s=s.replace(' '+i,i)
print(s)