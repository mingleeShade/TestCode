package main

import "fmt"

func main() {
	var v map[int]int

	v = nil

	a, ok := v[1243]
	if ok {
		fmt.Println("exist! a: ", a)
	} else {
		fmt.Println("not exists!")
	}
}
