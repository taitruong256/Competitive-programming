a=int(input())
b=int(input())
ans=1
for i in range(a, b+1):
    ans*=i 
while len(str(ans))>1:
    sum=0
    while (ans>0):
        sum+=ans%10
        ans//=10
    if len(str(sum))<=1:
        print(sum)
        break;
    ans=sum 