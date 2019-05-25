package main

import "fmt"

func main() {
	var N int

	fmt.Scanf("%d", &N)
	arr := make([]int, 3)

	for i := 0; i < N; i++ {
		var num int
		fmt.Scanf("%d", &num)
		arr[num%3]++
	}

	ret := arr[0]*(arr[0]-1)/2 + arr[1]*arr[2]

	fmt.Println(ret)
}
