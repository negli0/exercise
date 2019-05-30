package main

import (
	"fmt"
	"os"
	"strconv"
)

var result = map[int]string{}
var resInd int
var tar string
var end = false

func max(r []rune) []rune {
	for i := 0; i < len(r)-1; i++ {
		for j := i + 1; j < len(r); j++ {
			if r[i] < r[j] {
				r[i], r[j] = r[j], r[i]
			}
		}
	}
	return r
}

func genPerm(done string, rest string) {
	if end == true {
		return
	}
	if len(rest) == 1 {
		result[resInd] = done + rest
		champ, _ := strconv.Atoi(tar)
		chall, _ := strconv.Atoi(result[resInd])
		if chall <= champ {
			fmt.Println(chall)
			end = true
			os.Exit(0)
		}
		resInd++
		return
	}

	for i := 0; i < len(rest); i++ {
		if len(done) > 0 && string(done[0]) == "0" {
			continue
		}
		genPerm(done+string(rest[i]), rest[:i]+rest[i+1:])
	}
}

func solve(a, b string) string {
	genPerm("", a)
	ib, _ := strconv.Atoi(b)
	for i := resInd - 1; i >= 0; i-- {
		if ia, _ := strconv.Atoi(result[i]); ia <= ib {
			return result[i]
		}
	}
	return "-1"
}

func main() {
	var a, b string
	fmt.Scanf("%s%s", &a, &b)

	tar = b
	ra := []rune(a)
	sra := max(ra)

	ret := solve(string(sra), b)
	//for i := 0; i < resInd; i++ {
	//	fmt.Println(result[i])
	//}
	fmt.Println(ret)
}
