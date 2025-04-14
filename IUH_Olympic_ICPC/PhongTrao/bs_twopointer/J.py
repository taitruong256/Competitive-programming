for _ in range(int(input())):
    n, s=map(int, input().split(" "))
    cnt=0
    if n%2==0: cnt=n//2+1
    else: cnt=n//2
    print(s//cnt)
    