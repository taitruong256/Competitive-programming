for _ in range(int(input())):
    s=input()
    t=input()
    i=0
    truoc=''
    s=s+"@"
    for x in t:
        if x==s[i]:
            i+=1
            truoc=x
        elif x!=truoc: break
    print(i)
    if i==len(s)-1: print("YES")
    else: print("NO")