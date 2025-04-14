n=int(input())
mod=10**9+7

p=1
for i in range(1, n+1): p=(p*i)%mod
lt=1
for i in range(1, n): lt=(lt*2)%mod 
print((p-lt+mod)%mod)