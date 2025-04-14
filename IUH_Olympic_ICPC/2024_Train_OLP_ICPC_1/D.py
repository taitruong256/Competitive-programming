def binpow(x, n, limit_digits):
    ans = 1
    while n > 0:
        if n % 2 == 1:
            ans *= x
            ans = int(str(ans)[:limit_digits])  
        x *= x
        x = int(str(x)[:limit_digits]) 
        n //= 2
    return ans

a, b, k = [int(x) for x in input().split()]
ans = str(binpow(a, b, 100))

if len(ans) < k:
    ans += '0' * (k - len(ans)) 
print(ans[:k])