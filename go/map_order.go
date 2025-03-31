package main

import "fmt"

func main() {
	m := make(map[int64]string, 0)
	m[1] = "1"
	m[2] = "2"
	m[3] = "3"
	m[4] = "4"
	m[5] = "5"
	fmt.Println(m)
	delete(m, 1)
	fmt.Println(m)
	m[12] = "12"
	fmt.Println(m)
}
