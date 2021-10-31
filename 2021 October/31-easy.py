import sys
sys.stdin = open("lifeguards.in","r")
sys.stdout = open("lifeguards.out","w")

n = int(input())
time = [0]*1001
intervals = []
for _ in range(n):
	a,b = map(int,input().split())
	intervals.append([a,b])
	for i in range(a,b):
		time[i] += 1

ans = 0
for x in intervals:
	curr = []
	for y in time:
		curr.append(y)
	
	for y in range(x[0],x[1]):
		curr[y] -= 1;
	
	cnt = 0
	for y in curr:
		if(y > 0):
			cnt += 1;
	
	ans = max(ans,cnt)
print(ans)
