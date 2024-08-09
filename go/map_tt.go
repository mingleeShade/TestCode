package main

import "fmt"

type Test struct {
	M map[string]int
}

func main() {
	t := Test{}
	if t.M == nil {
		t.M = make(map[string]int, 1)
	}
	t.M["1"] = 1
	fmt.Printf("test: %v", t)
}
