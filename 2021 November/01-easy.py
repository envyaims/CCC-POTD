import sys
sys.stdin = open("moobuzz.in","r")
sys.stdout = open("moobuzz.out","w")


n = int(input())
relative = [-1,1,2,4,7,8,11,13]
print(15 * (n//8) + relative[n%8])
