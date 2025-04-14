me=input()
n=int(input())
d=dict()
for _ in range(n):
    s=input().split(' ')
    x, y=s[0], s[-2].split('\'')[0]
    if x not in d: d[x]=0
    if y not in d: d[y]=0
    act=15
    if s[1]=='commented': act=10
    elif s[1]=='likes': act=5
    if x==me: d[y]+=act
    if y==me: d[x]+=act
    
p=[]
for i in d.keys(): 
    if i!=me: p.append([-d[i], i])
p.sort()
for i in p: print(i[1])