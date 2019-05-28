package main

import (
	"fmt"
	"math"
)

var indArr [100001]int

func main() {
	var n int
	fmt.Scanf("%d", &n)

	for i := 0; i < n; i++ {
		var num int
		fmt.Scanf("%d", &num)
		indArr[num] = i
	}

	var minInd = n + 1
	var diff = -1
	for i := 1; i <= n; i++ {
		diff = int(math.Max(float64(diff), float64(indArr[i]-minInd)))
		minInd = int(math.Min(float64(minInd), float64(indArr[i])))
	}
	fmt.Println(diff)
}
