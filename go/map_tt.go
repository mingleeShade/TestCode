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
	fmt.Printf("test: %v\n", t)

	var m2 map[string]*int

	fmt.Println("===test2===")
	if m2 == nil {
		a := m2["1"] // 这里不会 panic
		if a != nil && *a == 0 {
			fmt.Println("a is 0")
		}
		fmt.Println("m2 is nil")
		// m2["2"] = new(int) // 会panic

		m2 = make(map[string]*int, 0)
		if m2 != nil {
			fmt.Println("m2 is not nil  after make")
		}
		m2["2"] = new(int) // 不会panic
	} else {
		fmt.Println("m2 is not nil")
		a := m2["1"]
		if *a == 0 {
			fmt.Println("a is 0")
		}
	}
}
