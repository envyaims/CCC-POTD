# https://cses.fi/problemset/task/1618/
count = 0
num = int(input())
 
while num >= 5:
    num //= 5
    count += num
 
print(count)
