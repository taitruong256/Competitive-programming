from pickle import FALSE, TRUE

for _ in range(int(input())):
    s=input()+'$'
    for ch in range(ord('a'), ord('z')+1): 
        if chr(ch) in s:
            cnt=0
            check=TRUE
            for i in range(len(s)): 
                if s[i]==chr(ch): cnt=cnt+1
                else: 
                    if cnt%2==1: check=FALSE;
                    # print(i, chr(ch), cnt)
                    cnt=0
            if check==FALSE: print(chr(ch), end="")
    print()
            