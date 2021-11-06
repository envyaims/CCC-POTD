n = int(input())
cows = list(map(int,input().split()))
stalls = list(map(int,input().split()))
stalls.sort()
ans = 1
cowstaken = 0
for x in stalls:
    cancows = 0
    for y in cows:
        if y <= x:
            cancows += 1
    if cancows > cowstaken:
        ans *= (cancows-cowstaken)
        cowstaken += 1
print(ans)
