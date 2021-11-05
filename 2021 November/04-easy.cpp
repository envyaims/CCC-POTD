import sys
sys.stdin = open("lemonade.in","r")
sys.stdout = open("lemonade.out","w")

n = int(input())
cows = sorted(list(map(int,input().split())),reverse=True)
count = 0
for i in range(n):
    if(cows[i] < i):
        count += 1
print(n-count)

