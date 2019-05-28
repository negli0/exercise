package main

import "fmt"

const (
	MAX = 1000000000
	MIN = 1
)

func solve(x int) int {
	if x == 1 {
		return 0
	} else if x == 2 {
		return 1 + solve(x-1)
	} else {
		if x%3 == 1 {
			return 1 + solve(x-1)
		} else if x%3 == 2 {
			return 1 + solve(x+1)
		} else {
			return 1 + solve(x/3)
		}
	}
}

func main() {
	var x int
	fmt.Scanf("%d", &x)
	ret := solve(x)
	fmt.Println(ret)
}
