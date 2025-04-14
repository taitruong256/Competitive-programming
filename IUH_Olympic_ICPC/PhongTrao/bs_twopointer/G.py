k=int(input())
i=19
while k>0:
    sum=0; x=i
    while (x>0):
        sum+=x%10
        x//=10
    if sum==10: k=k-1
    if k==0: break
    i=i+1
print(i)