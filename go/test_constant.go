package main

import "fmt"

type TestType int

const (
	TestType_1 TestType = 1
	TestType_2 TestType = 1
	TestType_3 TestType = 1
)

func main() {
	var t TestType
	fmt.Println("t: ", t)
}
