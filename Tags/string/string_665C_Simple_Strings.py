s=list(input()+'a')
for i in range(len(s)-2):
    if s[i]==s[i+1]:
        s[i+1]=list({'a', 'b', 'c'}-{s[i]}-{s[i+2]})[0]
print(''.join(s[:-1]))
