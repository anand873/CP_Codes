t = int(input());
for _ in range(t):
	x, y = map(int, raw_input().split())
	vis = [False for i in range(10)]
	ans = 0
	for d in range(10):
		if(x<y*(d+1)):
			continue
		ans += ((x - y*(d+1))//(y*10) + 1)*((y*(d+1))%10)

	print(ans)
