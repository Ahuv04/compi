from collections import Counter

def mex():
    mex_val = 0
    while (mex_val <= n):
        if (mex_val not in s):
            return mex_val
        mex_val += 1
    return mex_val

for _ in range(int(input())):
    n = int(input())
    arr = [int(item) for item in input().split()]
    c = Counter(arr)
    print(c)
    s = set(arr)
    print(s)
    ans = []
    i=0
    while(i<n):
        m = mex()
        z = set()
        while (i < n):
            if (arr[i] < m):
                z.add(arr[i])
            c[arr[i]] -= 1
            if (c[arr[i]] == 0):
                s.remove(arr[i])
            if (len(z) == m):
                break
            i += 1
        ans.append(m)
        i += 1
    print(len(ans))
    print(*ans)