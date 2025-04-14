n, m, k=[int(x) for x in input().split()]
print(n*m*k-max(0, n-2)*max(0, m-2)*max(0, k-2))