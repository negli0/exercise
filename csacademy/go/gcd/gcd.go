package main

import (
	"fmt"
)

func solve(a, b int) int {
	if b == 0 {
		return a
	}
	return solve(b, a%b)
}

func main() {
	var a, b int
	fmt.Scanln(&a, &b)
	ret := solve(a, b)
	fmt.Println(ret)
}
