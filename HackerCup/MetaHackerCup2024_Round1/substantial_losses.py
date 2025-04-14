mod = 998244353

def solve(t, input):
    W, G, L = map(int, input.split())
    ans = (W - G) % mod * (L % mod * 2 + 1) % mod
    with open("substantial_losses_output.txt", "a") as f:
        f.write(f"Case #{t + 1}: {ans}\n")

with open("substantial_losses_input.txt", "r") as f:
    tc = int(f.readline().strip())
    for t in range(tc):
        solve(t, f.readline().strip())
