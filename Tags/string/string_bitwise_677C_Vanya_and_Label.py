s=input()
id='0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_'
ans=1
for x in s: ans=(ans*3**(6-bin(id.index(x)).count('1')))%1000000007
print(ans)
