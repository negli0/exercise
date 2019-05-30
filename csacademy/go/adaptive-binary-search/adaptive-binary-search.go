package main

import "fmt"

func main() {
	var n int
	fmt.Scanf("%d", &n)
	var st = 0
	var en = n + 1
	var mid, ans int

	for en-st > 1 {
		mid = (st + en) / 2
		fmt.Printf("Q %d\n", mid)

		var y int
		fmt.Scanf("%d", &y)

		if y == 0 {
			en = mid
			ans = mid
		} else {
			st = mid
		}
	}
	fmt.Printf("A %d\n", ans)
}
