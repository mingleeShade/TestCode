package main

import "fmt"

func test(m map[string]interface{}) {
	l, ok := m["a"].([]string)
	if !ok {
		fmt.Println("nil map type assert is nil")
		return
	}
	if len(l) == 0 {
		fmt.Println("l is nil")
	}
	l = append(l, "b")
	m["a"] = l
}

func main() {
	var v map[int]int

	v = nil

	a, ok := v[1243]
	if ok {
		fmt.Println("exist! a: ", a)
	} else {
		// 这里打印
		fmt.Println("not exists!")
	}

	fmt.Println("nil map")
	var m map[string]interface{}
	test(m)

	fmt.Println("empty map")
	m = make(map[string]interface{})
	test(m)

	fmt.Println("map not empty")
	m["b"] = []string{}
	test(m)

	fmt.Println("map not empty, a not empty")
	m["b"] = []string{}
	test(m)
}
