package main

import (
	"fmt"
)

type ShoePair struct {
	r     uint
	l     uint
	pairs uint
}

var shoes [100]ShoePair

func createPair(size int, pair string) uint {
	if pair == "L" {
		shoes[size-1].l++
	} else if pair == "R" {
		shoes[size-1].r++
	}

	if shoes[size-1].r > 0 && shoes[size-1].l > 0 {
		shoes[size-1].r--
		shoes[size-1].l--
		return 1
	} else {
		return 0
	}
}

func main() {
	var N int
	fmt.Scanln(&N)

	var size int
	var pair string
	var ret uint

	for i := 0; i < N; i++ {
		fmt.Scanln(&size, &pair)
		ret += createPair(size, pair)
	}
	fmt.Println(ret)
}
