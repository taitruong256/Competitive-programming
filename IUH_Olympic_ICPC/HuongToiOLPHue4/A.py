n=int(input())
thuaso=[]
i=2
while i*i<=n:
    if n%i==0:
        while n%i==0:
            n//=i 
        thuaso.append(i);
    i+=1
if n>1:
    thuaso.append(n)

def dequy
print(thuaso)