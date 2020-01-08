n = int(input())
seq = input().split()
seq = [int(i) for i in seq]
dp = [0 for i in range(len(seq))]
bef = [-1 for i in range(len(seq))]

for i in range(len(seq)):
    dp[i] = 1
    bef_idx = -1
    max_length = 0
    
    for j in range(i):
        if seq[j] < seq[i] and max_length < dp[j]:
            max_length = dp[j]
            bef_idx = j

    dp[i] += max_length
    bef[i] = bef_idx

print(max(dp))
