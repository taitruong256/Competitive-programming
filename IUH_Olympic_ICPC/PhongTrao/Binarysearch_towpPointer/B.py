a=int(input())
b=int(input())
c=int(input())
d=int(input())
n=int(input())

x=[]
def dem(a, n):
    global x
    i=a
    while i<=n:
        x.append(i)
        i=i+a

dem(a, n)
dem(b, n)
dem(c, n)
dem(d, n)
print(x)
# print(len(set(x)))
    
    

