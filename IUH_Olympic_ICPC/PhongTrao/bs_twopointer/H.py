for _ in range(int(input())):
    a, b, c=map(int, input().split(" "))
    s=(a+b+c)
    if s%9==0 and a>=s//9 and b>=s//9 and c>=s//9:
        print("YES")
    else:
        print("NO")