from bisect import *
arr_str = open('algo1-programming_prob-2sum.txt').readlines()
print 'read complete!'
arr = map(int, arr_str)
arr = list(set(arr))
arr.sort()
print 'sort complete'

ans = []
for x in arr:
	posl = bisect_left(arr, -10000-x)
	posr = bisect_right(arr, 10000-x)
	for y in arr[posl:posr]:
		ans.append(x + y)

print 'answer: ', len(set(ans))
print set(ans)
