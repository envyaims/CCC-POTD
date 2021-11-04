import sys
sys.stdin = open("triangles.in","r")
sys.stdout = open("triangles.out","w")

class point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

n = int(input())
points = []
for _ in range(n):
    x,y = map(int,input().split())
    points.append(point(x,y))

ans = 0
for i in range(n):
    for j in range(n):
        for k in range(n):
            if points[i].x == points[j].x and points[j].y == points[k].y:
                area = abs(points[i].y - points[j].y) * abs(points[j].x - points[k].x)
                ans = max(ans,area)

print(ans)


