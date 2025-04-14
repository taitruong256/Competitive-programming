import math

l, r = map(int, input().split())
lm = 1
for i in range(l, r + 1):
    lm = math.lcm(lm, i)
ans = 0
while lm % 10 == 0:
    ans += 1
    lm //= 10
print(ans)