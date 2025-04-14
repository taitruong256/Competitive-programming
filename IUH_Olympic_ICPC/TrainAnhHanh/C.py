fi=open('divexp.inp', 'r')
fo=open('divexp.out', 'w')
l, r, k=map(int, fi.readline().split(" "))

def tinh(n, k):
    ans=0
    for i in range(1, n+1):
        ans=ans+n//i
        ans=ans-n//(i**k)
    return ans

fo.write(str(tinh(r, k)-tinh(l-1, k)))