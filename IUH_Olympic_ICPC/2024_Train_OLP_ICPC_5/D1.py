import math

def count_divisors(n):
    count = 0
    sqrt_n = int(math.sqrt(n))
    for i in range(1, sqrt_n + 1):
        if n % i == 0:
            count += 1  # i là ước
            if i != n // i:  # nếu i khác n // i thì n // i cũng là ước
                count += 1
    return count

# Đọc số test case
T = int(input())

# Xử lý từng test case
for _ in range(T):
    n = int(input())
    print(count_divisors(n))
