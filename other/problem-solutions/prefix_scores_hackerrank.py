



# let prefix[i] = a0, a1, a2, ..., ai , with mx = max(a0,a1,...ai)
# let mx be the maximum of a given prefix i before it is changed

# operation 1
# after the first operation, a0 will become a0+mx, then, the new max will be a1+mx
# operation 2
# after the second operation, a1 will become a1+new_max = a1 + (a0+mx), then, the new max will be a1+a0+mx

# then, score(i) = (a0+mx) + (a0 + a1 + mx) + (a0 + a1 + a2 + mx) ...
# = mx * (i+1) +
# + (a0) + (a0+a1) + ... (a0+a1+...+ai)


# solution: mx can be calculated on the go, prefix_sum will be an array storing
# the prefix sum of arr at first, then it will be chaned to be the refix sum of
# itself
def getPrefixScores(arr):
    mod = int(10**9 + 7)
    scores = []
    prefix_sum = [a for a in arr]
    for i in range(2):
        for j in range(1,len(prefix_sum)):
            prefix_sum[j] += prefix_sum[j-1]
            prefix_sum[j] %= mod

    # now prefix_sum[i] = (a0) + (a0+a1) + ... (a0+a1+...+ai)

    mx = 0
    for i in range(len(arr)):
        v = arr[i]
        mx = max(mx, v)
        scores.append(
            ((i+1) * mx + prefix_sum[i]) % mod
        )

    return scores
