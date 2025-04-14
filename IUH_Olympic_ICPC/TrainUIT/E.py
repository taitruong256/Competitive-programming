n=input()
cnt=0
while len(n)>1:
    m=sum(int(x) for x in n)
    cnt+=1
    n=str(m)
print(cnt)
    