n=int(input())
a=[input() for i in range(n)]
print(max(a.count(x) for x in a))