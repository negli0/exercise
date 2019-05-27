package main

import (
	"fmt"
	"math"
)

var n int

type pos struct {
	r int
	c int
}

func solve(s, f pos) int {
	if (s.r+s.c)%2 != (f.r+f.c)%2 {
		return -1
	} else {
		if s == f {
			return 0
		} else if math.Abs(float64(s.r-f.r)) == math.Abs(float64(s.c-f.c)) {
			return 1
		} else {
			return 2
		}
	}
}

func main() {
	var s, f pos

	fmt.Scanf("%d%d%d%d", &s.r, &s.c, &f.r, &f.c)

	ret := solve(s, f)
	fmt.Println(ret)
}
