from operator import le


def tinh(s, c):
    if len(s)==1:
        if s[0]==c: return 0
        else: return 1
    mid=len(s)//2
    left=s[0:mid]
    right=s[mid:len(s)]
    cntl=left.count(c)
    cntr=right.count(c)
    l=mid-cntl+tinh(right, chr(ord(c)+1))
    r=mid-cntr+tinh(left, chr(ord(c)+1)) 
    # print(s, left, right, l, r, c)
    return min(l, r)

for t in range(int(input())):
    n=int(input())
    s=input()
    print(tinh(s, 'a'))
    